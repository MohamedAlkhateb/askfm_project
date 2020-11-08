#ifndef DataBase_h
#define DataBase_h
#include <sqlite3.h>
#include <iostream>

using namespace std;

class DataBase
{
public:
    DataBase();
    ~DataBase();

protected:
    sqlite3 *dbUsers;
    sqlite3 *dbQuestions;
};

#endif