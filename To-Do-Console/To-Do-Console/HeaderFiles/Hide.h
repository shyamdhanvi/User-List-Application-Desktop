#ifndef Hide_H
#define Hide_H

#include <iostream>
#include <conio.h>
#include <string> 
#include "HeaderFiles/UserData.h"

using namespace std;

class Hide {
private:
	string password;
public:
	Hide() {}
	string encript();
	string decript();
};
string Hide::encript() {
	UserData userdata;
	string e_pass = userdata.get_Password();
	for (char& c : e_pass)
	{
		c += 3;
	}
	password = e_pass;
	return e_pass;
}
string Hide::decript() {
	string d_pass = password;
	for (char& d : d_pass)
	{
		d -= 3;
	}
	return d_pass;
}
#endif 