#include "Formularz.h"
#include <iostream>
#include <regex>

void Form::getFullName()
{
    std::string name;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    std::regex reg("[A-Z]{1}[a-z]{2,}\\s[A-Z]{1}[a-z]{2,}");

    auto isNameValid = validate(name, reg);
    if (isNameValid) {
        userName = name;
        std::cout << "Name OK\n";
    }
    else {
        std::cout << "Name wrong!\n";
        getFullName();
    }
}

void Form::getPassword()
{
    std::string password;
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    std::regex reg("(?!.*[\\s])(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z0-9]{8,20}"); // looks ahead for lowercase letter, uppercase letter and for numbers, exclude spaces, everything at least 8 digits

    auto isNameValid = validate(password, reg);
    if (isNameValid) {
        userPassword = password;
        std::cout << "Password OK\n";
    }
    else {
        std::cout << "Password wrong!\n";
        getPassword();
    }
}

void Form::getEmail()
{
    std::string email;
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);


    std::regex reg("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}");

    auto isNameValid = validate(email, reg);
    if (isNameValid) {
        userEmail = email;
        std::cout << "Email OK\n";
    }
    else {
        std::cout << "Email wrong!\n";
        getEmail();
    }
}

bool Form::validate(const std::string& str, const std::regex& reg)
{
    return std::regex_match(str, reg);
}

bool Form::validateIt(const std::string& str, const std::regex& reg)
{
    std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
    std::sregex_iterator lastMatch;
    
    while (currentMatch != lastMatch) {
        std::smatch match = *currentMatch;
        return true;
        currentMatch++;
    }
    
    return false;
}

void Form::sentByPOSTMethod()
{
    if (!userName.empty() && !userPassword.empty() && !userEmail.empty()) {
        std::cout << "Form has been sent successfully.\n";
        return;
    }

    std::cout << "Form has some issues, contact your administrator for more information...\n";
}
