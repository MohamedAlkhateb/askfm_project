#include "user.h"
static int callbackReturnData(void *data, int c_num, char **c_vals, char **c_names)
{
    vector<string> *storeData = (vector<string> *)data;
    for (int i = 0; i < c_num; i++)
    {
        storeData->push_back(c_vals[i]);
    }
    return 0;
}

static int callback(void *data, int c_num, char **c_vals, char **c_names)
{
    int *anonymous = (int *)data;
    *(int *)data = **c_vals - '0';
    return 0;
}

User::User(string n, string pass, string email, bool a)
{
    setName(n);
    setPassword(pass);
    setEmail(email);
    setAnonymous(a);
}

void User::setName(string n)
{
    if (n.size() > 0 && n.size() <= 20)
        name = n;
    else
        throw invalid_argument("name should be greater than 0 and equal or less than 20");
}
void User::setPassword(string pass)
{
    if (pass.size() > 0 && pass.size() <= 20)
        password = pass;
    else
        throw invalid_argument("password should be greater than 0 and equal or less than 20");
}
void User::setEmail(string em)
{
    if (em.size() > 0 && em.size() <= 20)
        email = em;
    else
        throw invalid_argument("email should be greater than 0 and equal or less than 20");
}
void User::setAnonymous(bool a)
{
    if (a == 0 || a == 1)
        anonymous = a;
    else
        throw invalid_argument("anonymous should only be 0 or 1");
}

string User::getName()
{
    return name;
}
string User::getPassword()
{
    return password;
}
string User::getEmail()
{
    return email;
}
bool User::getAnonymous()
{
    return anonymous;
}

void User::registerUser()
{

    string sql = "INSERT INTO users (name,email,password,anonymous) VALUES (" + serialize() + ")";
    char *zErrorMessage;
    int rc = sqlite3_exec(dbUsers, sql.c_str(), 0, 0, &zErrorMessage);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
}

void User::login(string e, string p)
{
    vector<string> data;

    int rc = sqlite3_open("/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/askfm.db", &dbUsers);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(dbUsers) << endl;
        return;
    }

    string sql = "SELECT * FROM users WHERE email = '" + e + "' AND password = '" + p + "'";
    char *zErrorMessage = 0;
    rc = sqlite3_exec(dbUsers, sql.c_str(), callbackReturnData, (void *)&data, &zErrorMessage);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }

    if (data.empty())
    {
        throw invalid_argument("email or password are wrong");
        return;
    }
    anonymous = stoi(data.back());
    data.pop_back();
    password = data.back();
    data.pop_back();
    email = data.back();
    data.pop_back();
    name = data.back();
    data.pop_back();
}

void User::askQuestion(string reciver)
{
    if (email == reciver)
    {
        cout << "You cannot ask your self\n";
        return;
    }
    string sql = "select anonymous from users where email = '" + reciver + "'";
    char *zErrorMessage = 0;
    int anonymousUser = -1;
    int rc = sqlite3_exec(dbUsers, sql.c_str(), callback, (void *)&anonymousUser, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
    if (anonymousUser == -1)
    {
        throw invalid_argument("There no user with this email");
        return;
    }
    char message[50];
    cout << "Enter the message: ";
    cin.getline(message, 50);
    sql = "insert into questions (sender,reciver,message,anonymous) values ('" +
          email + "'" + ",'" + reciver + "','" + message + "','" + to_string(anonymousUser) + "')";
    rc = sqlite3_exec(dbQuestions, sql.c_str(), 0, 0, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
}

void User::printQuestionsToMe()
{
    string sql = "select * from questions where reciver = '" + email + "'";
    vector<string> data;

    char *zErrorMessage;
    int rc = sqlite3_exec(dbQuestions, sql.c_str(), callbackReturnData, (void *)&data, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
    while (!data.empty())
    {
        anonymousQuestion = stoi(data.back());
        data.pop_back();
        message = data.back();
        data.pop_back();
        reciver = data.back();
        data.pop_back();
        sender = data.back();
        data.pop_back();
        idQuestion = stoi(data.back());
        data.pop_back();
        cout << "Question ID: " << idQuestion;
        if (anonymousQuestion == 1)
        {
            cout << " from anonymous: ";
        }
        else
        {
            cout << " from " << sender << ": ";
        }
        cout << message << endl;
    }
}

string User::serialize()
{
    return "'" + name + "'" + ',' + "'" + email + "'" + ',' + "'" + password + "'" + ',' + "'" + to_string(anonymous) + "'";
}

void User::deserialize(string matchResult)
{
    regex reg("(\\w*),(\\w*),(\\w*),(\\d)");
    smatch matches;
    regex_search(matchResult, matches, reg);
    name = matches.str(2);
    password = matches.str(3);
    email = matches.str(4);
    anonymous = stoi(matches.str(5));
}