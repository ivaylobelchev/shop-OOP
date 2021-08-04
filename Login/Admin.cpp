#include "Admin.hpp"
#include <cstring>
#pragma warning (disable:4996)

Admin::Admin()
{
    this->admin = 1;
}

Admin::Admin(std::string Username, const char* Password)
{
    this->admin = 1;

    this->username = Username;

    unsigned short passwordLength = strlen(Password);
    this->password = new char[passwordLength + 1];
    strncpy(this->password, Password, passwordLength + 1);
    this->password[passwordLength] = '\0';
}

Admin::Admin(const Admin& from)
{
    this->username = from.username;

    this->password = new char[strlen(from.password) + 1];
    strncpy(this->password, from.password, strlen(from.password) + 1);

    this->admin = from.admin;
}

Admin::~Admin()
{
    // No new dynamically allocated memory to delete[]
}