#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "/Users/sumit/Desktop/sumit/include/adminLogin.h"

#include "/Users/sumit/Desktop/sumit/include/facultyLogin.h"
#include "/Users/sumit/Desktop/sumit/include/StudentLogin.h"
void adminLogin();
void facultyLogin();
void studentlogin();

class myroom cc;
class admin adm;
class faculty fac;
int num = 0;

int main()
{
    int choice;
    cout << "\n======================================================================" << endl;
    cout << "               Training Schedule System                  " << endl;
    cout << "======================================================================" << endl;
    cout << "\n\n\t\tWelcome To Home Page" << endl;
    cout << "\n\t\tPress 1 --> Admin Login" << endl;
    cout << "\t\tPress 2 --> Faculty Login" << endl;
     cout << "\t\tPress 3 --> Student Login" << endl;
    cout << "\t\tPress 4 --> Exit" << endl;
    cout << "\n======================================================================" << endl;
    cout << "                    LOGIN SYSTEM                 " << endl;
    cout << "======================================================================" << endl;
    cout << "\nPlease Enter Your Choice : ";
    // prototyp
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout << "\nPlease enter a number!!" << endl;
        main();
    }
    else
    {
        switch (choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            facultyLogin();
            break;
        case 3:
            cc.call();
            break;
        case 4:
            cout << "See you again." << endl;
            break;
        default:
            cout << "\nPlease select from the options given above" << endl;
            main();
        }
    }
}

void adminLogin()      
{
    string userId = "admin";
    string password = "12345";
    string id, pass;
    cout << "\n\n=======================================" << endl;
    cout << "         Welcome To The Admin Page         " << endl;
    cout << "=======================================" << endl;
    cout << "\n\nPlease Enter Your Username & Password For Authentiocation" << endl;

    cout << "\nEnter Your Username : ";
    cin >> id;

    cout << "\nEnter Your Password : ";
    cin >> pass;

    if (userId == id && password == pass)
    {
        cout << "\nCongratulations " << userId << endl;
        cout << "Your login as administrator is successfull. Thanks for logging in.\n"
             << endl;
        adm.adminModules();
    }
    else
    {
        cout << "\n!!!Login Error!!!" << endl;
        cout << "Please check your username and password again\n"
             << endl;
        num += 1;
        if (num == 3)
        {
            cout << "\nACCESS DENIED" << endl;
            exit(0);
        }
        main();
    }
}

void facultyLogin()
{

    int count = 0;
    string id, pass, stream, userId, password, techName;
    cout << "\n\n======================================" << endl;
    cout << "         Welcome To The Faculty Page         " << endl;
    cout << "======================================" << endl;
    cout << "\n\nPlease Enter Your Credentials For Authentiocation" << endl;

    cout << "\nEnter Your Name : ";
    cin >> userId;

    cout << "\nEnter Your Password : ";
    cin >> password;

    cout << "\nEnter Your Technology Name : ";
    cin >> techName;

    ifstream input("/Users/sumit/Desktop/sumit/data/facultyLogin.csv");

    while (input >> id >> pass >> stream)
    {
        if (id == userId && pass == password && stream == techName)
        {
            count = 1;
        }
    }

    input.close();

    if (count == 1)
    {
        cout << "\n\nCongratulations " << userId << endl;
        cout << "Your login as faculty is successfull. Thanks for logging in.\n"
             << endl;
        fac.loginId = userId;
        fac.facultyModules();
    }
    else
    {
        cout << "\n!!!Login Error!!!" << endl;
        cout << "Please enter your details again\n"
             << endl;
        num += 1;
        if (num == 3)
        {
            cout << "\nACCESS DENIED" << endl;
            exit(0);
        }
        main();
    }
}



