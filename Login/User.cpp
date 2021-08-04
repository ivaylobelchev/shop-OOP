#include <iostream>
#include <cstring>
#include <conio.h> // _getch    Only works on Windows
#include <limits> // used to clear buffer when typing
#include "User.hpp"
#pragma warning (disable:4996)

User::User()
{
    this->admin = 0;

    this->username = "";

    password = new char[1];
    password[0] = 0;
}

User::User(std::string Username, const char* Password)
{
    this->admin = 0;

    this->username = Username;

    unsigned short passwordLength = strlen(Password);
    this->password = new char[passwordLength + 1];
    strncpy(this->password, Password, passwordLength + 1);
    this->password[passwordLength] = '\0';
}

int SafetyInputInteger(int lowerBound, int upperBound) // Aldi's code from the UP course
{
    int intNumber;
    bool success;

    do {
        std::cout << "Input a number between " << lowerBound << " and " << upperBound << ": ";
        std::cin >> intNumber;
        //std::cout << std::endl << intNumber << std::endl;

        success = !std::cin.fail();

        if (!success)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!success || (intNumber < lowerBound) || (intNumber > upperBound));

    return intNumber;
}

bool YesOrNo()
{
    char answer = 0;
    std::cin >> answer;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // clears buffer memory if there have been entered more than 1 character

    if (answer == 'Y' || answer == 'y')
    {
        return 1;
    }
    else if (answer == 'N' || answer == 'n')
    {
        return 0;
    }
    else
    {
        return YesOrNo();
    }
}

void User::setup(std::string Username, const char* Password)
{
    this->username = Username;

    unsigned short passwordLength = strlen(Password);
    delete[] this->password;
    this->password = new char[passwordLength + 1];
    strncpy(this->password, Password, passwordLength + 1);
    this->password[passwordLength] = '\0';
}

void User::initialSetup()
{
    std::cout << "Set username: \n";
    char* temp = new char[1024];
    std::cin.getline(temp, 1024);
    username = temp;
    delete[] temp;

    std::cout << "\nSet password: \n";
    std::cout << "Make sure you remember your password as it cannot be changed later.\nPlease do not use unpermitted symbols.\n";
    delete[] password;
    char* temp2 = new char[2048];
    temp2[0] = '\0';
    char ch;
    ch = _getch();
    short i = 0;
    while (ch != 13)
    {
        temp2[i] = ch;
        ++i;
        std::cout << '*';
        ch = _getch();
        if (i == 2047) break;
    }
    temp2[i] = '\0';
    
    unsigned short passwordLength = strlen(temp2);
    this->password = new char[passwordLength + 1];
    strncpy(this->password, temp2, passwordLength + 1);
    this->password[passwordLength] = '\0';
    delete[] temp2;
}

bool User::passwordMatch()
{
    char* pass = new char[2048];
    pass[0] = '\0';
    char ch;
    std::cout << "\nEnter pass\n";
    ch = _getch();
    short j = 0;
    while (ch != 13)
    {
        pass[j] = ch;
        ++j;
        std::cout << '*';
        ch = _getch();
        if (j == 2048) break;
    }
    pass[j] = '\0';

    bool match = 1;
    for (size_t i = 0; i < 96 && this->password[i] != '\0'; ++i)
    {
        if (this->password[i] != pass[i])
        {
            match = 0;
            break;
        }
    }

    delete[] pass;
    if (!match) std::cerr << "\nIncorrect password!";
    else std::cerr << "\nCorrect password!";
    std::cerr << "\n\n";

    return match;

    // Not a perfect solution
    // Probvay neshto s '/r' i cin.get()
}

User::User(const User& from)
{
    this->username = from.username;
    
    this->password = new char[strlen(from.password) + 1];
    strncpy(this->password, from.password, strlen(from.password) + 1);

    this->admin = from.admin;
}

User& User::operator=(const User& from)
{
    if (this != &from)
    {
        this->username = from.username;
        
        delete[] this->password;
        this->password = new char[strlen(from.password) + 1];
        strncpy(this->password, from.password, strlen(from.password) + 1);

        this->admin = from.admin;
    }
    return *this;
}

bool User::changePassword(const char* oldPassword, const char* newPassword)
{
    // This function returns 0 if the change was unsuccessful and 1 if it was
    if (strcmp(oldPassword, this->password) != 0) return 0;
    delete[] this->password;
    this->password = new char[strlen(newPassword) + 1];
    strncpy(this->password, newPassword, strlen(newPassword) + 1);
    return 1;
}

const std::string& User::getUsername() const
{
    return this->username;
}

bool User::isThisAccountAnAdmin() const
{
    return this->admin;
}

bool User::passwordMatch(const char* Password)
{
    if (strcmp(Password, this->password) != 0) return 0;
    return 1;
}

void User::setActivity(bool active)
{
    this->active = active;
}

bool User::getActivity()
{
    return this->active;
}

User::~User()
{
    delete[] password;
    // no need to delete[] username
}