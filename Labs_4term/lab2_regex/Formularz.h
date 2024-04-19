#pragma once
#ifndef FORMULARZ_H
#define FORMULARZ_H

#include <string>
#include <regex>

class Form {
	std::string userName;
	std::string userPassword;
	std::string userEmail;
public:

	Form() {};

	void getFullName();
	void getPassword();
	void getEmail();
	
	bool validate(const std::string&, const std::regex&);
	bool validateIt(const std::string&, const std::regex&);
	void sentByPOSTMethod();
};

#endif