#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <unordered_map>

#include "functions.h"

using namespace std;

void zad_1()
{
	cout << "Zadanie 1\n";
	set <string> 
		my_friends = { "Bartek", "Dominik", "Karol", "Damian", "Wojtek" },
		his_friends = { "Bartek", "Natalia", "Dominik", "Karol", "Milena" },
		all_friends = my_friends;

	cout << "\nMoja lista przyjaciol: ";
	for (string i : my_friends)
		cout  << i << "; ";


	cout << "\nLista przyjaciol mojego znajomego: ";
	for (string i : his_friends)
		cout << i << "; ";

	all_friends.merge(his_friends);

	cout << "\nNasza wspolna lista znajomych: ";
	for (string i : all_friends)
		cout  << i << "; ";
	
	cout << "\n\n\n";
}

void zad_2()
{
	cout << "Zadanie 2\n\n";
	map <int, string> ingredients;
	ingredients.insert({ 1, "marchewka" });
	ingredients.insert({ 2, "pomidor" });
	ingredients.insert({ 3, "salata" });
	ingredients.insert({ 4, "ziemniak" });
	ingredients.insert({ 5, "papryka" });
	ingredients.insert({ 6, "ogorek" });
	ingredients.insert({ 7, "cebula" });
	ingredients.insert({ 8, "czosnek" });
	ingredients.insert({ 9, "sol" });
	ingredients.insert({ 10, "pieprz" });

	cout << "Elementy wraz z kluczmi do mapy:\n";
	for (const auto& [key, value] : ingredients)
		std::cout << '[' << key << "] = " << value << ";\n";

	ingredients.erase(1);
	ingredients.erase(2);

	ingredients.insert({ 11, "cynamon" });
	ingredients.insert({ 12, "kakao" });

	cout << "\nElementy wraz z kluczmi do zmodyfikowanej mapy:\n";
	for (const auto& [key, value] : ingredients)
		std::cout << '[' << key << "] = " << value << ";\n";
}

void zad_3()
{
	cout << "\nZadanie 3\n";

	vector<int> maths = { 5, 5, 3, 1, 2, 5, 3, 4, 3, 6 };
	array<int, 10> biology = { 5, 3, 4, 5, 2, 3, 1, 3, 4, 2 };
	deque <int> history = { 3, 4, 2, 5, 3, 4, 2, 1, 3, 4 };
	unordered_map <int, int> physic = {{0,3},{1,1},{2,3},{3,4},{4,2},
										{5,5},{6,3},{7,4},{8,2},{9,5}};

	arithmetic_average(maths, biology, history, physic);

	int student_id;
	cout << "\nWpisz numer ucznia ktorego oceny chcialbys zobaczyc: ";
	cin >> student_id;
	specyfic_information(student_id, maths, biology, history, physic);
}

void arithmetic_average(vector<int> maths, array<int, 10> biology,
	deque <int> history, unordered_map <int,int> physic)
{
	cout << "\nSrednie ocen studentow wraz z ich numerami: \n";
	for (int i = 0; i < 10; i++)
	{
		float average =
			(float)(maths[i] + biology[i] + history[i] + physic.at(i)) / 4;
		cout << "uczen nr " << i + 1 << " posiada srednia: " << average << ";\n";
	}
}

void specyfic_information(int student_id, vector<int> maths, array<int, 10> biology,
	deque <int> history, unordered_map <int, int> physic)
{
	cout << "Szczegolowe oceny ucznia nr " << student_id << ":\n";
	cout << "Matematyka: " << maths[student_id - 1] << ";\n";
	cout << "Biologia: " << biology[student_id - 1] << ";\n";
	cout << "Historia: " << history[student_id - 1] << ";\n";
	cout << "Fizyka: " << physic[student_id - 1] << ";\n";
}
