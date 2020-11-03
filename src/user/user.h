#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <cstring>
#include <regex>
#include <sqlite3.h>
#include <vector>

using namespace std;

class User
{

public:
    User(string, string, string, bool);

    void setName(string n);
    void setPassword(string pass);
    void setEmail(string em);
    void setAnonymous(bool a);

    string getName();
    string getPassword();
    string getEmail();
    bool getAnonymous();

    void registerUser();
    void login(string, string);
    void askMe();
    void printQuestionsToMe();
    string serialize();
    void deserialize(string);

private:
    string name;
    string email;
    string password;
    bool anonymous;
};

#endif