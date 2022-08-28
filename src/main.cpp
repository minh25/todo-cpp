#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <sqlite_orm/sqlite_orm.h>

#include "Todo.h"

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (int i = 0; i < argc; i++)
    {
        spdlog::info("{} {} /n", azColName[i], (argv[i] ? argv[i] : "NULL"));
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    auto log = spdlog::stdout_color_mt("log");

    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        spdlog::info(sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        spdlog::info("Connect successfully");
    }

    const char *sql = "CREATE TABLE COMPANY("
                      "ID INT PRIMARY KEY     NOT NULL,"
                      "NAME           TEXT    NOT NULL,"
                      "AGE            INT     NOT NULL,"
                      "ADDRESS        CHAR(50),"
                      "SALARY         REAL );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        spdlog::error("SQL error: {}", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        spdlog::info("Successfully");
    }
    sqlite3_close(db);

    return 0;
}