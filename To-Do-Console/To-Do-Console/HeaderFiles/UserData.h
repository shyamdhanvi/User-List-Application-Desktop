#ifndef USERDATA_H
#define USERDATA_H

#include <iostream>
#include <string>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

class UserData {
private:
    string User_Name;
    string Password;
public:
    UserData() {}
    void setUserData();
    string get_UserName() const;
    string get_Password() const;

#ifdef _WIN32
    string getPassword();
#else
    string getPassword();
#endif
};

void UserData::setUserData(){
    cout << "Enter UserName: ";
    cin >> User_Name;
    cout << "Enter Password: ";
    Password = getPassword();
    cout << endl;
}
string UserData::get_UserName() const {
    return User_Name;
}
string UserData::get_Password() const {
    return password;
}

#ifdef _WIN32
string UserData::getPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}
#else
string UserData::getPassword() {
    string password;
    termios tty_old, tty_new;
    tcgetattr(STDIN_FILENO, &tty_old);
    tty_new = tty_old;
    tty_new.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_new);
    cin >> password;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_old);
    return password;
}
#endif
#endif // USERDATA_H
