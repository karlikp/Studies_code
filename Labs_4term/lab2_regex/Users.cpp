#include "Users.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <regex>

void Users::display(const std::smatch& matches)
{
    for (auto& i : matches)
        std::cout << i << " ";
    std::cout << std::endl;
}


std::vector<std::string> Users::getDataFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    std::vector<std::string> data;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filePath << std::endl;
        return data;
    }

    while (std::getline(file, line)) {
        data.push_back(line);
    }

    file.close();
    return data;
}

void Users::getPhoneNumber()
{
    auto response = getDataFromFile("users.txt");
    std::regex reg("[6-9]{3}-[1-6]{3}-\\d{3}");

    for (auto& string : response) {
        std::smatch matches;
        while (std::regex_search(string, matches, reg))
        {
            display(matches);
            string = matches.suffix().str();
        }
    }
}

void Users::countMales()
{
    auto response = getDataFromFile("users.txt");
    std::regex reg("[^fe]male");
    int counter = 0;

    for (auto& string : response) {
        std::smatch matches;
        while (std::regex_search(string, matches, reg))
        {
            counter++;
            string = matches.suffix().str();
        }
    }

    std::cout << "TEAM BOYS: " << counter << " | " << "TEAM GIRLS: " << response.size() - counter << std::endl;
}

void Users::getFemaleURL(){
    auto response = getDataFromFile("users.txt");
    std::regex reg("female");
    std::vector<std::string> femalesData;


    for (auto& string : response) {
        std::smatch matches;
        while (std::regex_search(string, matches, reg))
        {
            femalesData.push_back(string);
            string = matches.suffix().str();
        }
    }

    std::regex regURL("https\\S*");
    
    for (auto& female : femalesData)
    {
        std::smatch matches;
        while (std::regex_search(female, matches, regURL))
        {
            display(matches);
            female = matches.suffix().str();
        }
    }
}
