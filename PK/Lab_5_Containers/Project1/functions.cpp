#include <iostream>
#include <set>
#include <map>

#include "functions.h"

using namespace std;

void zad_1()
{
	cout << "Zadanie 1";
	set <string> 
		my_friends = { "Bartek", "Dominik", "Karol", "Damian", "Wojtek" },
		his_friends = { "Bartek", "Natalia", "Dominik", "Karol", "Milena" },
		all_friends = my_friends;

	cout << "\nMoja lista przyjaciol: ";
	for (string i : my_friends)
		cout  << i << ", ";


	cout << "\nLista przyjaciol mojego znajomego: ";
	for (string i : his_friends)
		cout << i << ", ";

	all_friends.merge(his_friends);

	cout << "\nNasza wspolna lista znajomych: ";
	for (string i : all_friends)
		cout  << i << ", ";
	
	cout << '\n';
}

void zad_2()
{
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

}
