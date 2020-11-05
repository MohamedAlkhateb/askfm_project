#include "user/user.h"
using namespace std;

int main()
{
    int anonymous = 1;
    string password = "566", userName = "mohamed", email = "mohamd@gmail.com";

    // cin >> userName >> password >> email >> anonymous;
    User user(userName, password, email, anonymous);
    user.login(email, password);
    return 0;
}