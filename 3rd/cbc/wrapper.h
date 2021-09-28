#ifndef _JZY_COMMON_WRAPPER_CBC_H_
#define _JZY_COMMON_WRAPPER_CBC_H_

#include <string>

#pragma pack(1)

#pragma pack(8)

namespace jzy_common
{
    namespace util
    {
        class CWrapperCBC
        {
        public:
            CWrapperCBC();
            ~CWrapperCBC();

            void ReInit();

            static bool GenKey(std::string &echoKey);

            bool SetKeyIV(unsigned char *pszKey, unsigned char *pszIV);

            bool Encrpt(unsigned char *pSrcBuf, int SrcSize, unsigned char *pDestBuf, int &echoDestSize);

            bool Decrpt(unsigned char *pSrcBuf, int SrcSize, unsigned char *pDestBuf, int &echoDestSize);

            bool MyDecrpt(unsigned char *pSrcBuf, int SrcSize, unsigned char *pDestBuf, int &echoDestSize);

        public:
            unsigned char m_Key[16]; //
            unsigned char m_Iv[16];  //
            void *m_pCtx;            //
        };

        class JZY_AES
        {
        public:
            static bool toAES(const char *szAesKey, const char *szAesIV, const char *src, int len, std::string &des, int nType);

            static bool fromAES(const char *szAesKey, const char *szAesIV, std::string src, std::string &des);
        };

        class Base64
        {
        public:
            static std::string base64_encode(unsigned char const *bytes_to_encode, size_t len);
            static std::string base64_decode(std::string const &s);
            static std::string base64_encode(char *);

            //----------------------------PC 移植过来的函数--------------------------------//
            static char *base64_encode(char *data, int data_len);
            static unsigned char *base64_decode(unsigned char *src, int *iLen);
            static unsigned char toHex(const unsigned char &x);
            static std::string urlEncode(const std::string &str);
            static std::string safeAndNonsafeBase64Change(std::string inputStr, int mode);
        };
    }
}

#endif