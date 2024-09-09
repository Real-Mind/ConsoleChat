#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class User
{
public:
	User() : username(""), password(""), name("") {}	// Конструктор по умолчанию

	User(const string& username, const string& password, const string& name)
		: username(username), password(password), name(name) {}

	// Геттеры
	string getUsername();
	string getPassword();
	string getName();

private:
	string username;
	string password;
	string name;
};

