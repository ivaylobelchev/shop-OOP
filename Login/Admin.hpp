#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"

class Admin : public User
{
public:
	Admin();
	Admin(std::string Username, const char* Password);
	Admin(const Admin&);
	~Admin();
};

#endif // ADMIN_HPP