#include "questions.h"

Questions::Questions(char **question)
{
    idQuestion = stoi(question[0]);
    sender = question[1];
    reciver = question[2];
    message = question[3];
    anonymousQuestion = stoi(question[4]);
}

void Questions::restQuestion(Questions &question)
{
    idQuestion = question.idQuestion;
    sender = question.sender;
    reciver = question.reciver;
    message = question.message;
    anonymousQuestion = question.anonymousQuestion;
}