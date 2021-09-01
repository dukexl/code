#include <iostream>
#include <string.h>
#include <libgen.h>

int main(void) {

    char *path = "../conf/pipe_client.conf";
    std::cout << path << std::endl;

    std::cout << "------------------------" << std::endl;
    char *dirc = strdup(path);
    char *basec = strdup(path);
    std::cout << "dirc=" << dirc << std::endl;
    std::cout << "basec=" << basec << std::endl;
    char *d = dirname(dirc);
    std::cout << "dirname(dirc)=" << d << std::endl;
    std::cout << "dirc=" << dirc << std::endl;
    std::cout << "basec=" << basec << std::endl;

    char *f = basename(basec);
    std::cout << "basename(basec)=" << f << std::endl;

    //std::cout << dir << std::endl;


    return 0;
}
