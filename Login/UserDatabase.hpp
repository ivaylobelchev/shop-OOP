#ifndef USERDATABASE_HPP
#define USERDATABASE_HPP

#include "Admin.hpp"
#include <vector>

class UserDatabase
{
private:
	std::vector<User> database;
public:
	UserDatabase();
	UserDatabase(const User& firstUser);
	UserDatabase(std::string Username, const char* Password);
	UserDatabase(const UserDatabase& other);
	UserDatabase& operator=(const UserDatabase& other);
	~UserDatabase();

	void addUser(const User& add);
	void addUser(std::string Username, const char* Password);
	User& findUser(std::string Username);

	void printAll();
};

#endif // USERDATABASE_HPP