#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    time_t current_time;
    current_time = time(NULL);
    printf("%d\n",current_time);
    struct tm* tmp_time = (struct tm*)malloc(sizeof(struct tm));  
     strptime("20210308140207","%Y%m%d%H%M%S",tmp_time); //时间24时制
     time_t t = mktime(tmp_time);  
     printf("%lld\n",t);
     free(tmp_time);
    //cout<<current_time<<endl;
}
