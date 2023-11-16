#include <iostream>
#include <fstream>
#include <string.h>
#include "/Users/sumit/Desktop/sumit/include/as.h"

using namespace std;

class papa obb;

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    ifstream dataFile("/Users/sumit/Desktop/sumit/src/student_data.txt");
    string existingUsername;
    while (dataFile >> existingUsername) {
        if (existingUsername == username) {
            cout << "Username already exists. Please choose another one.\n";
            dataFile.close();
            return;
        }
    }
    dataFile.close();

    cout << "Enter a password: ";
    cin >> password;

    ofstream outFile("student_data.txt", ios::app);
    outFile << username << " " << password << endl;
        cout << "User registered successfully.\n";
    
    outFile.close();
}

bool loginUser(string username, string password) {
    ifstream dataFile("/Users/sumit/Desktop/sumit/src/student_data.txt");
    string existingUsername, existingPassword;
    while (dataFile >> existingUsername >> existingPassword) {
        if (existingUsername == username && existingPassword == password) {
            dataFile.close();
            return true;
        }
    }
    dataFile.close();
    return false;
}


void loginn(){
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (loginUser(username, password)) {
            cout << "\n=======================================" << endl;
            cout << "Login successful!\n";
            cout << "===================================\n" << endl;
            obb.subku();
            } else {
            cout << "\n===================================" << endl;
            cout << "Login failed. Invalid username or password.\n";
            cout << "===================================" << endl;
            cout<<"Please enter correct Password"<<endl;
            loginn();
            }
}
class myroom {
    public:
    void call(){
    cout << "\n\n=======================================" << endl;
    cout << "         Welcome To The Student Page         " << endl;
    cout << "=======================================" << endl;
    cout<<endl;
     cout << "====================================================" << endl;
    cout<<"1.Already have an account            2.Create new Account"<<endl;
   cout << "====================================================" << endl;
    cout<<"\nEnter choice"<<endl;
    int choice;
    cin>>choice;
    switch (choice)
        {
        case 1:
        loginn();
        break;
        case 2:
        registerUser();
        break;
        default:
            cout << "\nPlease select from the options given above" << endl;
            call();
        }
    }
};