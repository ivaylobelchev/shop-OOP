#include "UserDatabase.hpp"
#include <iostream>
#include <string>

UserDatabase::UserDatabase()
{
	this->database.clear();
}

UserDatabase::UserDatabase(const User& firstUser)
{
	this->database.push_back(firstUser);
}

UserDatabase::UserDatabase(std::string Username, const char* Password)
{
	User temporary(Username, Password);
	this->database.push_back(temporary);
}

UserDatabase::UserDatabase(const UserDatabase& other)
{
	database = other.database;
}

UserDatabase& UserDatabase::operator=(const UserDatabase& other)
{
	database.clear();
	database = other.database;
	return *this;
}

UserDatabase::~UserDatabase()
{
	// No need?
}

void UserDatabase::addUser(const User& add)
{
	this->database.push_back(add);
}

void UserDatabase::addUser(std::string Username, const char* Password)
{
	User temporary(Username, Password);
	this->database.push_back(temporary);
}

User& UserDatabase::findUser(std::string Username)
{
	size_t i = 0;
	for (; i < this->database.size(); i++)
	{
		if (this->database[i].getActivity() == 0) continue;

		std::string iStrUsername = this->database[i].getUsername();
		std::string givenUsername(Username);

		if (iStrUsername == givenUsername) break;
	}

	return this->database[i];
}

void UserDatabase::printAll()
{
	std::cout << "Normal users:\n";
	for (size_t i = 0; i < database.size(); i++)
	{
		if (database[i].admin == false)
		{
			std::cout << "Username: " << database[i].getUsername() << "\n";
		}
	}

	std::cout << "\nAdmins:\n";
	for (size_t i = 0; i < database.size(); i++)
	{
		if (database[i].admin == true)
		{
			std::cout << "Admin username: " << database[i].getUsername() << "\n";
		}
	}
}