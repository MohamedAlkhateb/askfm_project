#include "user.h"
static int callback(void *data, int c_num, char **c_vals, char **c_names)
{
    vector<string> *storeData = (vector<string> *)data;
    for (int i = 0; i < c_num; i++)
    {
        storeData->push_back(c_vals[i]);
    }
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
    sqlite3 *db;
    char *zErrorMessage = 0;
    int rc;
    string sql;

    rc = sqlite3_open("/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/askfm.db", &db);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sql = "INSERT INTO users (name,email,password,anonymous) VALUES (" + serialize() + ")";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrorMessage);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << zErrorMessage << endl;
    }
    sqlite3_close(db);
}

void User::login(string e, string p)
{
    sqlite3 *db;
    char *zErrorMessage = 0;
    int rc;
    string sql;
    vector<string> data = {"null"};

    rc = sqlite3_open("/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/askfm.db", &db);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sql = "SELECT * FROM users WHERE email = '" + e + "' AND password = '" + p + "'";
    rc = sqlite3_exec(db, sql.c_str(), callback, (void *)&data, &zErrorMessage);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error : " << zErrorMessage << endl;
        sqlite3_free(zErrorMessage);
    }

    if (data.back() == "null")
    {
        sqlite3_close(db);
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

    sqlite3_close(db);
}

void User::askMe()
{
    /*     int userId;

    do{
        cout << "Enter user id or -1 to cancel ";
        cin >> userId;
        if ( userId == -1 ){
            return;
        }
        else if ( userId <= 0 )
            cout << "user id must be greater than zero\n";
    } while( userId <= 0 );
    
    if ( userId == id ){
        cout << "you cannot ask yourself" << endl;
        return;
    }
    fstream userFile( "userFile.txt", ios::in );
    if ( !userFile )
        cerr << "Cannot open the user file";
    char line[50];
    
    
    regex reg("(\\d),(\\w*),(\\w*),(\\w*@\\w*\\.\\w*),(\\d)");

    while ( userFile.getline( line, 50 ) ){
        string lineString;
        smatch matches;
        lineString = line;
        regex_search( lineString, matches, reg );
        if ( stoi( matches.str() ) == userId ){
            fstream questionsFile( "questions.txt", ios::out | ios::app );
            if ( !questionsFile )
                cerr << "Cannot open the question file";
            fstream metaFile( "metadata.txt", ios::in );
            if ( !metaFile )
                cerr << "Cannot open the metadata file";
            string qusetion;
            cout << "Enter qusetion text: ";
            cin >> qusetion;
            regex reg( "(\\d) (\\d)" );
            metaFile.getline( line, 50 );
            lineString = line;
            metaFile.close();
            regex_search( lineString, matches, reg );
            questionsFile << stoi( matches.str( 2 ) ) + 1 << ',' << qusetion << ',' << id << ',' << userId << endl;
            questionsFile.close();
            metaFile.open( "metadata.txt", ios::out );
            if ( !metaFile )
                cerr << "Cannot open metadata file";
            metaFile << matches.str( 1 ) << " " << stoi( matches.str( 2 ) ) + 1;
            metaFile.close();
            return;
        }
    }
    cout << "no matches"; */
}

void User::printQuestionsToMe()
{
    /*     fstream questionsFile( "questions.txt", ios::in );
    if ( !questionsFile )
        cerr << "Cannot open the question file";
    char line[ 100 ];//i don't know how many charcter
    regex reg( "(\\d),(\\w*),(\\d),(\\d)");
    while( questionsFile.getline( line, 100 ) ){
        smatch matches;
        string lineString;
        lineString = line;
        regex_search( lineString, matches, reg );
        if ( stoi( matches.str( 4 ) ) == id ){
            cout << "Question ID (" << matches.str( 1 ) <<
                ") From user id(" << matches.str( 3 ) << ")\t" << matches.str( 2 ) << endl;
        }
    } */
}

string User::serialize()
{
    return "'" + name + "'" + ',' + "'" + email + "'" + ',' + "'" + password + "'" + ',' + "'" + to_string(anonymous) + "'";
}

void User::deserialize(string matchResult)
{
    /*     regex reg( "(\\d),(\\w*),(\\w*),(\\w*),(\\d)" );
    smatch matches;
    regex_search( matchResult, matches, reg );
    id = stoi( matches.str( 1 ) );
    name = matches.str( 2 );
    password = matches.str( 3 );
    email = matches.str( 4 );
    anonymous = stoi( matches.str( 5 ) ); */
}