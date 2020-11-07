#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <iostream>

using namespace std;

class Questions
{
public:
    Questions(char **);
    Questions() {}

    void restQuestion(Questions &);

protected:
    int idQuestion;
    string sender;
    string reciver;
    string message;
    bool anonymousQuestion;
};

#endif