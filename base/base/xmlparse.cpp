#include "/home/xuli/code/datacenter/dc/include/tinyxml2.h"
#include "/home/xuli/code/datacenter/dc/include/public_function.h"

bool loadSecuritiesXml()
{
    // 加载 商品数据
    bool bSuc = false;
    time_t t = time(NULL);
    int iRecord = 0;
    tm *Blocal = localtime(&t);
    int t_Byear = Blocal->tm_year + 1900;
    int t_Bmon = Blocal->tm_mon + 1;
    int t_Bday = Blocal->tm_mday;

    char szBTime[40];
    memset(szBTime, 0, sizeof(szBTime));
    sprintf(szBTime, "%04d%02d%02d", t_Byear, t_Bmon, t_Bday);

    char szFileName[256];
    memset(szFileName, 0, sizeof(szFileName));
    sprintf(szFileName, "securities_%s.xml", szBTime);

    tinyxml2::XMLDocument xml;
    int res = xml.LoadFile(szFileName);

    if (res != 0)
    {
        return false;
    }
    else
    {
        bSuc = true;

        // 获取根节点
        tinyxml2::XMLElement *pRoot = xml.RootElement();

        tinyxml2::XMLElement *pNode = pRoot->FirstChildElement("Security");
        while (pNode)
        {

            int listing_date = atol(pNode->FirstChildElement("ListDate")->GetText());
            if (listing_date < 10000)
            {
                printf("%d\n", listing_date);
            }

            pNode = pNode->NextSiblingElement();
        }
    }
    return bSuc;
}

int main()
{
    printf("start\n");
    loadSecuritiesXml();
    printf("end\n");

    return 0;
}