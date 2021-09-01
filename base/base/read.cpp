#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    std::string file_path = "./read.txt";
    FILE *fout_bp = fopen(file_path.c_str(), "rb");
    char buf[4];
    int len = 1;
    if (fout_bp != NULL)
    {
        while (len != 0)
        {
            len = fread(buf, 1, 4, fout_bp);
            printf("len:%d, buf:%s\n", len, buf);
        }
    }
    printf("buf:%s", buf);
    return 0;
}