#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <iostream>
#include <list>
#include <string>
#include <chrono>
//#include "UserName.h"
//#include "UserPassword.h"
#include "HeaderFiles/UserData.h"
//#include "HeaderFiles/UserPassword.h"

using namespace std;

class credential {
private:
	list<pair<string, string>> User_Credentials; 
public:
	credential() {}
	void set_Credentials();
	const list<pair<string, string>>& get_Cerdentials() const;
};
#endif // !CREDENTIAL_H
/*
void UserData::setUserData()
{
    cout << "Enter UserName: ";
    cin >> user_name;
    User_Name = user_name;
    cout << "Enter Password: ";
    disableEcho();
    cin >> password;
    enableEcho();
    Password = password;
    cout << endl;
}*/
