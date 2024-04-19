#pragma once
#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include <regex>

class Users {
	std::vector<std::string> data;
public:

	std::vector<std::string> getDataFromFile(const std::string&);
	void getPhoneNumber();
	void countMales();
	void getFemaleURL();

	void display(const std::smatch&);
};

#endif