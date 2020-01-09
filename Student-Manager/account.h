//account.h
#pragma once

#include <string>
using namespace std;

class account{
private:
	string Username;
	string Password;
public:
	account() :Username(""), Password(""){}
	void set(string username, string password);
	bool check(string username, string password);
};
