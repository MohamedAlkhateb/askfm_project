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
#include "/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/database/database.h"
#include "/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/question/questions.h"

using namespace std;

class User : public DataBase, public Questions
{

public:
    User(string, string, string, bool);
    User(char **);
    User() {}

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
    void askQuestion(string);
    void printQuestionsToMe();
    string serialize();
    void deserialize(string);
    void answerQuestion(int);
    User returnUser(char **);
    void rest(User &);

private:
    string name;
    string email;
    string password;
    bool anonymous;
};

#endif