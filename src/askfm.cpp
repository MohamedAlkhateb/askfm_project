#include "user/user.h"
using namespace std;

int main()
{
    DataBase database;
    int anonymous = 1;
    string password = "566", userName = "mohamed", email = "mohamed@gmail.com";

    // cin >> userName >> password >> email >> anonymous;
    User user(userName, password, email, anonymous);
    string reciver;
    reciver = "mohamed@gmail.com";
    user.login("omar@emara.com", "015");
    user.askQuestion(reciver);
    return 0;
}