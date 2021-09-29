
#include "wrapper.h"
#include <openssl/evp.h>
#include <openssl/ossl_typ.h>
#include <openssl/x509.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace jzy_common
{
    namespace util
    {
        CWrapperCBC::CWrapperCBC()
        {
            memset(m_Key, 0, sizeof(m_Key));
            memset(m_Iv, 0, sizeof(m_Iv));
            m_pCtx = EVP_CIPHER_CTX_new();
            EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)m_pCtx);
        }

        CWrapperCBC::~CWrapperCBC()
        {
            EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)m_pCtx);
            EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)m_pCtx);
        }

        bool CWrapperCBC::GenKey(std::string &echoKey)
        {
            char tmp[9];
            memset(tmp, 0, sizeof(tmp));

            for (int i = 0; i < 8; i++)
            {
                tmp[i] = abs(rand()) % 127 + 1;
            }
            echoKey = tmp;
            return true;
        }

        bool CWrapperCBC::SetKeyIV(unsigned char *pszKey, unsigned char *pszIV)
        {
            if (pszKey == NULL || pszKey[0] == '\0')
            {
                return false;
            }
            if (pszIV == NULL || pszIV[0] == '\0')
            {
                return false;
            }

            memcpy(m_Key, pszKey, sizeof(m_Key));
            memcpy(m_Iv, pszIV, sizeof(m_Iv));
            return true;
        }

        void CWrapperCBC::ReInit()
        {
            memset(m_Key, 0, sizeof(m_Key));
            memset(m_Iv, 0, sizeof(m_Iv));
        }

        bool CWrapperCBC::Encrpt(unsigned char *pSrcBuf, int SrcSize, unsigned char *pDestBuf, int &echoDestSize)
        {
            if (pSrcBuf == NULL || SrcSize <= 0)
                return false;
            if (pDestBuf == NULL || echoDestSize < SrcSize + 16)
                return false;

            int rv = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)m_pCtx, EVP_aes_128_cbc(), NULL, m_Key, m_Iv);
            if (rv != 1)
            {
                return false;
            }

            int outl;
            int outltmp;
            rv = EVP_EncryptUpdate((EVP_CIPHER_CTX *)m_pCtx, pDestBuf, &outl, pSrcBuf, SrcSize);
            if (rv != 1)
            {
                return false;
            }

            rv = EVP_EncryptFinal_ex((EVP_CIPHER_CTX *)m_pCtx, pDestBuf + outl, &outltmp);
            if (rv != 1)
            {
                return false;
            }
            outl += outltmp;

            echoDestSize = outl;
            return true;
        }

        bool CWrapperCBC::Decrpt(unsigned char *pSrcBuf, int SrcSize, unsigned char *pDestBuf, int &echoDestSize)
        {
            if (pSrcBuf == NULL || SrcSize <= 0)
                return false;
            if (pDestBuf == NULL || echoDestSize < SrcSize)
                return false;

            EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)m_pCtx, EVP_PADDING_PKCS7);

            int rv = EVP_DecryptInit_ex((EVP_CIPHER_CTX *)m_pCtx, EVP_aes_128_cbc(), NULL, m_Key, m_Iv);
            if (rv != 1)
            {
                return false;
            }

            int outl;
            int outltmp;
            rv = EVP_DecryptUpdate((EVP_CIPHER_CTX *)m_pCtx, pDestBuf, &outl, pSrcBuf, SrcSize);
            if (rv != 1)
            {
                return false;
            }

            rv = EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)m_pCtx, pDestBuf + outl, &outltmp);
            if (rv != 1)
            {
                return false;
            }
            outl += outltmp;

            echoDestSize = outl;
            return true;
        }

        /* sz_in_buff 输入解密字符串
        *  key 为密钥
        *  iv为偏移量
        *  sz_out_buff 输出解密后字符串
        */
        bool CWrapperCBC::MyDecrpt(unsigned char *pSrcBuf, int SrcSize, unsigned char *pDestBuf, int &echoDestSize)
        {
#define Block_Size 128
            unsigned char in[Block_Size];
            int outl = 0;
            int outl_total = 0;
            int isSuccess;

            // EVP_CIPHER_CTX ctx;

            // //初始化ctx，加密算法初始化
            // EVP_CIPHER_CTX_init(&ctx);
            EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)m_pCtx, EVP_PADDING_PKCS7);
            isSuccess = EVP_DecryptInit_ex((EVP_CIPHER_CTX *)m_pCtx, EVP_aes_128_cbc(), NULL, m_Key, m_Iv);
            if (!isSuccess)
            {
                EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)m_pCtx);
                return false;
            }

            //解密数据
            while (SrcSize > Block_Size)
            {
                memcpy(in, pSrcBuf, Block_Size);
                SrcSize -= Block_Size;
                pSrcBuf += Block_Size;

                isSuccess = EVP_DecryptUpdate((EVP_CIPHER_CTX *)m_pCtx, pDestBuf + outl_total, &outl, in, Block_Size);
                if (!isSuccess)
                {
                    EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)m_pCtx);
                    return false;
                }
                outl_total += outl;
            }

            if (SrcSize > 0)
            {
                memcpy(in, pSrcBuf, SrcSize);
                isSuccess = EVP_DecryptUpdate((EVP_CIPHER_CTX *)m_pCtx, pDestBuf + outl_total, &outl, in, SrcSize);
                outl_total += outl;
            }

            /*解密数据块不为16整数倍时执行 */
            if (SrcSize % Block_Size != 0)
            {
                isSuccess = EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)m_pCtx, pDestBuf + outl_total, &outl);
                if (!isSuccess)
                {
                    EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)m_pCtx);
                    return false;
                }
                outl_total += outl;
            }
            echoDestSize = outl_total;

            EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)m_pCtx);
            return true;
        }

        bool JZY_AES::toAES(const char *szAesKey, const char *szAesIV, const char *src, int len, std::string &des, int nType) //0:不需要 safeAndNonsafeBase64Change 1:需要safeAndNonsafeBase64Change 2:不需要urlEncode和safeAndNonsafeBase64Change
        {
            if (nullptr == src)
                return false;
            des.clear();
            CWrapperCBC m_CBC;
            unsigned char szKey[16] = {0}, szIV[16] = {0};
            memcpy(szKey, szAesKey, sizeof(szKey));
            memcpy(szIV, szAesIV, sizeof(szIV));
            m_CBC.SetKeyIV(szKey, szIV);

            unsigned char szDest[1024] = {0};
            int iDstSize = sizeof(szDest);
            if (m_CBC.Encrpt((unsigned char *)src, len, (unsigned char *)szDest, iDstSize))
            {
                char *pEncode = Base64::base64_encode((char *)szDest, iDstSize);
                if (pEncode)
                {
                    std::string strPwdBase = pEncode;
                    if (nType == 0)
                    {
                        des = Base64::urlEncode(strPwdBase);
                    }
                    else if (nType == 1)
                    {
                        des = Base64::urlEncode(Base64::safeAndNonsafeBase64Change(strPwdBase, 2));
                    }
                    else if (nType == 2)
                    {
                        des = strPwdBase;
                    }

                    free(pEncode);
                    pEncode = NULL;

                    return true;
                }
            }
            return false;
        }

        bool JZY_AES::fromAES(const char *szAesKey, const char *szAesIV, std::string src, std::string &des)
        {
            if (src.empty())
                return false;
            des.clear();
            // 封包是先设置cbc.keyIV,再cbc.encrpt，再base64_encode
            // 解包，先base64_decode 再cbc.decrpt
            // unsigned char *pDecode = Base64::base64_decode((unsigned char *)src.c_str(), &ilen);
            std::string pDecode = Base64::base64_decode(src);
            if (!pDecode.empty())
            {
                // char szBaseDecode[2048];
                // memset(szBaseDecode, '\0', sizeof(szBaseDecode));
                // // memcpy_s(szBaseDecode, sizeof(szBaseDecode), pDecode, ilen + 1);
                // memmove(szBaseDecode, pDecode, ilen + 1);

                CWrapperCBC m_CBC;
                char chPwd[2048];
                memset(chPwd, '\0', sizeof(chPwd));

                int nDeslen = sizeof(chPwd);
                unsigned char szKey[16] = {0}, szIV[16] = {0};
                memcpy(szKey, szAesKey, sizeof(szKey));
                memcpy(szIV, szAesIV, sizeof(szIV));
                m_CBC.SetKeyIV(szKey, szIV);
                m_CBC.MyDecrpt((unsigned char *)pDecode.c_str(), pDecode.length(), (unsigned char *)chPwd, nDeslen);
                if (chPwd[0] != '\0')
                {
                    int i = 0;
                    // "{\"accountCode\":\"LYS001\",\"bsFlag\":\"B\",\"channelType\":\"I\",\"exchangeCode\":\"HKEX\",\"orderType\":\"E\",\"price\":\"54.250\",\"productCode\":\"00001\",\"qty\":\"500\"}", '\020' <repeats 16 times>
                    // windows新后面填充的是x6 linux下后面填充的是\20 现在以 json的}为解析点。
                    for (i = strlen(chPwd) - 1; i > 0 && chPwd[i] != '}'; i--)
                    {
                        // 丢掉后面的'\x6'
                    }
                    chPwd[i + 1] = '\0';
                    des = chPwd;
                }
                return true;
            }
            return false;
        }

        const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

        static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        static inline bool is_base64(unsigned char c)
        {
            return (isalnum(c) || (c == '+') || (c == '/'));
        }

        std::string Base64::base64_encode(unsigned char const *bytes_to_encode, size_t in_len)
        {
            std::string ret;
            int i = 0, j = 0;
            unsigned char char_array_3[3], char_array_4[4];

            while (in_len--)
            {
                char_array_3[i++] = *(bytes_to_encode++);
                if (i == 3)
                {
                    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                    char_array_4[3] = char_array_3[2] & 0x3f;

                    for (i = 0; (i < 4); i++)
                        ret += base64_chars[char_array_4[i]];
                    i = 0;
                }
            }

            if (i)
            {
                for (j = i; j < 3; j++)
                    char_array_3[j] = '\0';

                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (j = 0; (j < i + 1); j++)
                    ret += base64_chars[char_array_4[j]];

                while ((i++ < 3))
                    ret += '=';
            }

            return ret;
        }

        std::string Base64::base64_decode(std::string const &encoded_string)
        {
            size_t in_len = encoded_string.size();
            int i = 0, j = 0, in_ = 0;
            unsigned char char_array_4[4], char_array_3[3];
            std::string ret;

            while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
            {
                char_array_4[i++] = encoded_string[in_];
                in_++;
                if (i == 4)
                {
                    for (i = 0; i < 4; i++)
                        char_array_4[i] = base64_chars.find(char_array_4[i]);

                    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                    for (i = 0; (i < 3); i++)
                        ret += char_array_3[i];
                    i = 0;
                }
            }

            if (i)
            {
                for (j = i; j < 4; j++)
                    char_array_4[j] = 0;

                for (j = 0; j < 4; j++)
                    char_array_4[j] = base64_chars.find(char_array_4[j]);

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                for (j = 0; (j < i - 1); j++)
                    ret += char_array_3[j];
            }

            return ret;
        }

        std::string Base64::base64_encode(char *src)
        {
            int len = strlen(src), i = 0;
            std::string ret;
            char bit3to8[3];
            char bit4to6[4];
            while (len--)
            {
                bit3to8[i++] = *src++;
                if (i == 3)
                {
                    bit4to6[0] = (bit3to8[0] & 0xfc) >> 2;
                    bit4to6[1] = (bit3to8[0] << 4 & 0x3f) | ((bit3to8[1] & 0xff) >> 4);
                    bit4to6[2] = ((bit3to8[1] << 2 & 0x3c) | (bit3to8[2] >> 6 & 0xff));
                    bit4to6[3] = bit3to8[2] & 0x3f;
                    for (i = 0; (i < 4); i++)
                        ret += base64_chars[bit4to6[i]];
                    i = 0;
                }
            }

            if (i)
            {
                for (int j = i; j < 3; j++)
                    bit3to8[j] = '\0';

                bit4to6[0] = (bit3to8[0] & 0xff) >> 2;
                bit4to6[1] = (bit3to8[0] << 4 & 0x3f) | ((bit3to8[1] & 0xff) >> 4);
                bit4to6[2] = ((bit3to8[1] << 2 & 0x3c) | (bit3to8[2] >> 6 & 0xff));
                bit4to6[3] = bit3to8[2] & 0x3f;
                for (int j = 0; (j <= i); j++)
                    ret += base64_chars[bit4to6[j]];

                while ((i++ < 3))
                    ret += '=';
            }

            return ret;
        }

        char *Base64::base64_encode(char *data, int data_len)
        {
            int prepare;
            int ret_len;
            int temp = 0;
            char *ret = NULL;
            char *f = NULL;
            int tmp = 0;
            char changed[4];
            int i = 0;
            ret_len = data_len / 3;
            temp = data_len % 3;
            if (temp > 0)
                ret_len += 1;

            ret = (char *)malloc(ret_len * 4 + 1);
            if (ret == NULL)
                return NULL;

            f = ret;
            while (tmp < data_len)
            {
                temp = 0;
                prepare = 0;
                memset(changed, '\0', 4);
                while (temp < 3)
                {
                    if (tmp >= data_len)
                    {
                        break;
                    }
                    prepare = ((prepare << 8) | (data[tmp] & 0xFF));
                    tmp++;
                    temp++;
                }

                prepare = (prepare << ((3 - temp) * 8));
                for (i = 0; i < 4; i++)
                {
                    if (temp < i)
                    {
                        changed[i] = 0x40;
                    }
                    else
                    {
                        changed[i] = (prepare >> ((3 - i) * 6)) & 0x3F;
                    }
                    *f = base[static_cast<int>(changed[i])];
                    f++;
                }
            }
            *f = '\0';

            return ret;
        }

        unsigned char *Base64::base64_decode(unsigned char *src, int *iLen)
        {
            static const char *ch64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            int n, i, j;
            unsigned char *p;
            static unsigned char *dst;

            n = strlen((char *)src);
            for (i = 0; i < n; i++) /* map base64 ASCII character to 6 bit value */
            {
                p = (unsigned char *)strchr(ch64, src[i]);
                if (!p)
                    break;
                src[i] = p - (unsigned char *)ch64;
            }
            dst = new unsigned char[n * 3 / 4 + 1 + 100]; // "+100", paul, 20119-29, add, 如果base64是错的, 有越界.
            memset(dst, 0, n * 3 / 4 + 1);
            for (i = 0, j = 0; i < n; i += 4, j += 3)
            {
                dst[j] = (src[i] << 2) + ((src[i + 1] & 0x30) >> 4);
                dst[j + 1] = ((src[i + 1] & 0x0F) << 4) + ((src[i + 2] & 0x3C) >> 2);
                dst[j + 2] = ((src[i + 2] & 0x03) << 6) + src[i + 3];
            }
            *iLen = (n - 1) * 3 / 4;
            return dst;
        }

        unsigned char Base64::toHex(const unsigned char &x)
        {
            return x > 9 ? x + 55 : x + 48;
        }

        std::string Base64::urlEncode(const std::string &str)
        {
            std::string strTemp = "";
            size_t length = str.length();
            for (size_t i = 0; i < length; i++)
            {
                if (isalnum((unsigned char)str[i]) ||
                    (str[i] == '-') ||
                    (str[i] == '_') ||
                    (str[i] == '.') ||
                    (str[i] == '~'))
                    strTemp += str[i];
                else if (str[i] == ' ')
                    strTemp += "+";
                else
                {
                    strTemp += '%';
                    strTemp += toHex((unsigned char)str[i] >> 4);
                    strTemp += toHex((unsigned char)str[i] % 16);
                }
            }
            return strTemp;
        }

        std::string Base64::safeAndNonsafeBase64Change(std::string inputStr, int mode)
        {
            if (mode == 1) //safe -->> nonsafe
            {
                for (unsigned int i = 0; i < inputStr.size(); i++)
                {
                    if (inputStr[i] == '-')
                    {
                        inputStr[i] = '+';
                        continue;
                    }
                    if (inputStr[i] == '_')
                    {
                        inputStr[i] = '/';
                        continue;
                    }
                }
                int remainder = inputStr.length() % 4;
                while (remainder--)
                {
                    inputStr.append("=");
                }
                return inputStr;
            }
            else if (mode == 2) //nonsafe -->> safe
            {
                for (unsigned int i = 0; i < inputStr.size(); i++)
                {
                    if (inputStr[i] == '+')
                    {
                        inputStr[i] = '-';
                        continue;
                    }
                    if (inputStr[i] == '/')
                    {
                        inputStr[i] = '_';
                        continue;
                    }
                    if (inputStr[i] == '=')
                    {
                        inputStr.pop_back();
                        continue;
                    }
                }
                return inputStr;
            }
            else
                return std::string("");
        }
    }
}