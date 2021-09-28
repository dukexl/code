/*
linux提供了daemon函数用于创建守护进程

#include  int  daemon(int nochdir, int noclose);
1． daemon() 函数主要用于希望脱离控制台，以守护进程形式在后台运行的程序。
2． 当nochdir为0时，daemon将更改进城的根目录为root(“/”)。
3． 当noclose为0是，daemon将进城的STDIN, STDOUT, STDERR都重定向到 / dev / null。

daemon的实现大致如下：

int daemon(int nochdir, int noclose)
{
    pid_t pid;
    if (!nochdir && chdir("/") != 0) //如果nochdir=0,那么改变到"/"根目录
        return -1;

    if (!noclose) //如果没有noclose标志
    {
        int fd = open("/dev/null", O_RDWR);
        if (fd < 0)
            return -1;         //重定向标准输入、输出、错误 到/dev/null，键盘的输入将对进程无任何影响，进程的输出也不会输出到终端
        dup(fd, 0);
        dup(fd, 1);
        dup(fd, 2);
        close(fd);
    }

    pid = fork(); //创建子进程.
    if (pid < 0)  //失败
        return -1;
    if (pid > 0)
     _exit(0); //返回执行的是父进程,那么父进程退出,让子进程变成真正的孤儿进程.

    //创建的 daemon子进程执行到这里了
    if (setsid() < 0) //创建新的会话，并使得子进程成为新会话的领头进程
        return -1;
    return 0; //成功创建daemon子进程
}

*/

#include <unistd.h>

int main()
{
    daemon(1, 1); //参数根据需求确定
    /*  在这里添加你需要在后台做的工作代码  */
    while (true)
    {
        sleep(100);
    }
}