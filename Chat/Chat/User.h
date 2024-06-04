#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class User {
public:
	string login;
	string password;
	string name;

	User(string login, string password, string name) : login(login), password(password), name(name) {}

	User() {}

	std::string getPassword()
	{
		return this->password;
	}

	std::string getLogin()
	{
		return this->login;
	}
};