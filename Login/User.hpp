#ifndef USER_HPP
#define USER_HPP

#include <string>

class User
{
protected:
    char* password;
    bool admin;
    bool active;
    std::string username;
    friend class UserDatabase;
public:
    User();
    User(std::string Username, const char* Password);
    User(const User&);
    User& operator=(const User&);
    void initialSetup();
    void setup(std::string Username, const char* Password);
    bool passwordMatch();
    bool passwordMatch(const char* Password);
    bool changePassword(const char* oldPassword, const char* newPassword);
    const std::string& getUsername() const;
    bool isThisAccountAnAdmin() const;
    void setActivity(bool active);
    bool getActivity();
    ~User();
};

#endif //USER_HPP