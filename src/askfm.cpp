#include "user/user.h"
using namespace std;

int main()
{
    /*     DataBase database;
    int anonymous = 1;
    string password = "566", userName = "mohamed", email = "mohamed@gmail.com";

    // cin >> userName >> password >> email >> anonymous;
    User user(userName, email, password, anonymous);
    string reciver;
    reciver = "omar@emara.com";
    user.login("omar@emara.com", "015");
    user.answerQuestion(); */
    DataBase database;
    User user;
    int flag;

    do
    {
        cout << "Enter 1 to register or 2 for login: ";
        cin >> flag;
    } while (flag != 1 && flag != 2);

    if (flag == 1)
    {
        do
        {
            flag = 0;
            int anonymous;
            string password, name, email;
            cout << "Enter without spaces\n";
            cout << "Enter your name between(1-20): ";
            cin >> name;
            cout << "Enter your email between(1-20): ";
            cin >> email;
            cout << "Enter your password between(1-20): ";
            cin >> password;
            do
            {
                cout << "Are you want to be anonymous 0 or 1: ";
                cin >> anonymous;
            } while (anonymous != 0 && anonymous != 1);
            try
            {
                User user(name, email, password, anonymous);
                user.registerUser();
                flag = 1;
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
            }
        } while (flag == 0);
    }
    else
    {
        do
        {
            flag = 0;
            cout << "Enter your email: ";
            string email;
            cin >> email;
            cout << "Enter your password: ";
            string password;
            cin >> password;
            try
            {
                user.login(email, password);
                flag = 1;
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
            }
        } while (flag == 0);
    }
    do
    {
        do
        {
            cout << "Enter 1 to ask a question or 2 to answer a question or 3 to print a questions to you: ";
            cin >> flag;
        } while (flag != 1 && flag != 2 && flag != 3);
        if (flag == 1)
        {
            do
            {
                flag = 0;
                cout << "Enter the email you want to ask: ";
                string emailAsk;
                cin >> emailAsk;
                try
                {
                    user.askQuestion(emailAsk);
                    flag = 1;
                }
                catch (exception &e)
                {
                    cout << e.what() << endl;
                }
            } while (flag == 0);
        }
        else if (flag == 2)
        {
            flag = 0;
            do
            {
                int questionID;
                do
                {
                    cout << "Enter question id to answer(it should be greater than 0): ";
                    cin >> questionID;
                } while (questionID < 1);
                try
                {
                    user.answerQuestion(questionID);
                    flag = 1;
                }
                catch (exception &e)
                {
                    cout << e.what() << endl;
                }
            } while (flag == 0);
        }
        else
        {
            flag = 0;
            do
            {
                try
                {
                    user.printQuestionsToMe();
                    flag = 1;
                }
                catch (exception &e)
                {
                    cout << e.what() << endl;
                }
            } while (flag != 1);
        }
        do
        {
            cout << "Enter 1 to continue or 0 to end: ";
            cin >> flag;
        } while (flag != 1 && flag != 0);
    } while (flag == 1);
    return 0;
}