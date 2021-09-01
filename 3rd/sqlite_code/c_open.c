#include <stdio.h>
#include <sqlite3.h>


int main()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db",&db);

    if(rc)
    {
        fprintf(stdout,"Can't open database:%s\n",sqlite3_errmsg(db));
        //    exit(0);
        return 0;
    }
    else
    {
        fprintf(stdout,"Opened database successfully\n");
    }
    sqlite3_close(db);
}
