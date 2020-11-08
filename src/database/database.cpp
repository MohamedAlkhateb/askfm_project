#include "database.h"

DataBase::DataBase()
{
    int rc = sqlite3_open("/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/askfm.db", &dbUsers);

    if (rc)
    {
        cerr << "Can't open askfm database: " << sqlite3_errmsg(dbUsers) << endl;
    }

    rc = sqlite3_open("/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/questions.db", &dbQuestions);

    if (rc)
    {
        cerr << "Can't open askfm database: " << sqlite3_errmsg(dbQuestions) << endl;
    }
}
DataBase::~DataBase()
{
    sqlite3_close(dbUsers);
    sqlite3_close(dbQuestions);
}