#include "user.h"
static int callbackAsk(void *data, int c_num, char **c_vals, char **c_names)
{
    *(int *)data = **c_vals - '0';
    return 0;
}

static int callbackUser(void *data, int c_num, char **c_vals, char **c_names)
{
    User user(c_vals);
    ((vector<User> *)data)->push_back(user);
    return 0;
}

static int callbackQuestion(void *data, int c_num, char **c_vals, char **c_names)
{
    Questions question(c_vals);
    ((vector<Questions> *)data)->push_back(question);
    return 0;
}

static int callback(void *data, int c_num, char **c_vals, char **c_names)
{
    *(bool *)data = true;
    return 0;
}

User::User(string n, string email, string pass, bool a)
{
    setName(n);
    setPassword(pass);
    setEmail(email);
    setAnonymous(a);
}

User::User(char **vals)
{
    name = vals[0];
    email = vals[1];
    password = vals[2];
    anonymous = stoi(vals[3]);
}

void User::setName(string n)
{
    if (n.size() > 0 && n.size() <= 20)
        name = n;
    else
        throw invalid_argument("name should be greater than 0 and equal or less than 20!");
}
void User::setPassword(string pass)
{
    if (pass.size() > 0 && pass.size() <= 20)
        password = pass;
    else
        throw invalid_argument("password should be greater than 0 and equal or less than 20!");
}
void User::setEmail(string em)
{
    if (em.size() > 0 && em.size() <= 20)
        email = em;
    else
        throw invalid_argument("email should be greater than 0 and equal or less than 20!");
}
void User::setAnonymous(bool a)
{
    if (a == 0 || a == 1)
        anonymous = a;
    else
        throw invalid_argument("anonymous should only be 0 or 1!");
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

void User::rest(User &user)
{
    setName(user.name);
    setPassword(user.password);
    setEmail(user.email);
    setAnonymous(user.anonymous);
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
    vector<User> data;

    int rc = sqlite3_open("/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/askfm.db", &dbUsers);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(dbUsers) << endl;
        return;
    }

    string sql = "SELECT * FROM users WHERE email = '" + e + "' AND password = '" + p + "'";
    char *zErrorMessage = 0;
    rc = sqlite3_exec(dbUsers, sql.c_str(), callbackUser, (void *)&data, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
    if (data.empty())
    {
        throw invalid_argument("Email or Password are wrong!");
    }
    rest(data.back());
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
    int rc = sqlite3_exec(dbUsers, sql.c_str(), callbackAsk, (void *)&anonymousUser, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
    if (anonymousUser == -1)
    {
        throw invalid_argument("There no user with this email!");
        return;
    }
    char message[50];
    cout << "Enter the message: ";
    cin.get();
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
    vector<Questions> data;
    char *zErrorMessage;

    int rc = sqlite3_exec(dbQuestions, sql.c_str(), callbackQuestion, (void *)&data, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }
    if (data.empty())
    {
        throw "You don't have any questions";
    }
    while (!data.empty())
    {
        restQuestion(data.back());
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

void User::answerQuestion(int questionID)
{
    string sql = "select * from questions where id = '" + to_string(questionID) + "' and reciver = '" + email + "'";
    bool data = false;
    char *zErrorMessage;
    int rc = sqlite3_exec(dbQuestions, sql.c_str(), callback, (void *)&data, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
    }

    if (data == false)
    {
        throw invalid_argument("No question with this id for you!");
        cout << "here" << endl;
        return;
    }
    string answer;
    cout << "Enter the answer: ";
    cin >> answer;
    sql = "INSERT INTO questions (answer) VALUES ('" + answer + "') where id = " + to_string(questionID);
    cout << sql << endl;
    rc = sqlite3_exec(dbQuestions, sql.c_str(), 0, 0, &zErrorMessage);
    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
        return;
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