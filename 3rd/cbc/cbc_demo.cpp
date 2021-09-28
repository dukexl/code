#include "wrapper.h"
#include <string>
#include <string.h>
#include <iostream>
using namespace jzy_common::util;
int main()
{
    // 解析数据包 const char*szAesKey, const char*szAesIV, std::string src, std::string& des

    std::string strValue = "wrQutt30s0URdfrmSPwIuyL78vPDpq+oLkWePaP2UpMKyN/2Pv9Ainkwf/LQJXYLS+VmoQnN1HR9Gw/zsRGVUBYpqU4PGrx7aQzxOPRiO0yVxDzZBBOspW5Pj0zQ7wj0qnw6/4zFlWGPQufYrZtGmsQrNHkmw47DMdqyZa+i8sytJKTh8Ay8qjwuVFzSUiLx";
    std::cout << strValue.length() << std::endl;
    std::string strRedisValue = "h5l8uaxjqii0uhqs", des;
    char m_szTradeAESKey[32]; // 获取key
    strcpy(m_szTradeAESKey, strRedisValue.c_str());
    unsigned char g_szIV[17] = "kai&sa!global@)!";

    JZY_AES::fromAES((char *)m_szTradeAESKey, (char *)g_szIV, strValue, des);

    std::cout << des << std::endl;

    return 0;
}