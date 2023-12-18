#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

class Ustawienia
{
	std::unordered_map<std::string, int> settings;

	Ustawienia() = default;
	~Ustawienia() = default;
	Ustawienia(const Ustawienia&) = delete;
	Ustawienia& operator=(const Ustawienia&) = delete;
	
public:
	bool available = true;
	static Ustawienia& Instance();
	
	void zapiszOpcje(const std::string& nazwa, int opcja);

	int sprawdzOpcje(const std::string& nazwa);
	
};




