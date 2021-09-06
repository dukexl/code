/* 
* @Author: duke.xl  
* @Brief: duke.xl  
* @Date: 2021-09-06 10:39:27  
* @Last Modified by: duke.xl
* @Last Modified time: 2021-09-06 10:51:40
*/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

bool my_error(int rc, sqlite3 *db)
{
    if (rc)
    {
        fprintf(stdout, "Can't open database:%s\n", sqlite3_errmsg(db));
        return false;
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
        return true;
    }
}

int main()
{
    // 1 先打开一个db
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char *data = "Callback function called";

    rc = sqlite3_open("test.db", &db);
    if (!my_error(rc, db))
        return -1;

    // 2 创建一个表   /* Create SQL statement */
    sql = "CREATE TABLE COMPANY("
          "ID INT PRIMARY KEY     NOT NULL,"
          "NAME           TEXT    NOT NULL,"
          "AGE            INT     NOT NULL,"
          "ADDRESS        CHAR(50),"
          "SALARY         REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (!my_error(rc, db))
        return -1;

    // 3 插入数据
    /* Create SQL statement */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
          "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (!my_error(rc, db))
        return -1;

    // 4 查询数据
    sql = "SELECT * from COMPANY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
    if (!my_error(rc, db))
        return -1;

    // 5 修改数据
    /* Create merged SQL statement */
    sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; "
          "SELECT * from COMPANY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
    if (!my_error(rc, db))
        return -1;

    // 6 删除数据
    /* Create merged SQL statement */
    sql = "DELETE from COMPANY where ID=2; "
          "SELECT * from COMPANY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
    if (!my_error(rc, db))
        return -1;

    // 7 关闭db
    sqlite3_close(db);

    return 0;
}