#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>

using namespace std;

class Questions
{
public:
    void askMe();
    void printQuestionsToMe();

protected:
    int idQuestion;
    string sender;
    string reciver;
    string message;
    bool anonymousQuestion;
};

#endif