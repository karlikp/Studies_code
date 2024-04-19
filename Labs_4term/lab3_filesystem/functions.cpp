#include "functions.h"

void zad1()
{
	cout << "zad1\n\n";
	fs::path p{"/parent/child/file.txt"};

	cout << p.root_name() << endl;			// Zwraca nazwê korzenia œcie¿ki
	cout << p.root_directory() << endl;		// Zwraca katalog korzenia œcie¿ki
	cout << p.root_path() << endl;			// Zwraca korzeñ œcie¿ki
	cout << p.relative_path() << endl;		// Zwraca czêœæ wzglêdn¹ œcie¿ki
	cout << p.parent_path() << endl;		// Zwraca œcie¿kê nadrzêdn¹
	cout << p.stem() << endl;				// Zwraca element ostatni z wyj¹tkiem rozszerzenia pliku
	cout << p.extension() << endl;			// Zwraca rozszerzenie pliku
	cout << p.is_absolute() << endl;		// Zwraca wartoœæ logiczn¹ (true/false), okreœlaj¹c¹ czy œcie¿ka jest œcie¿k¹ bezwzglêdn¹ czy wzglêdn¹
}

void zad2()
{
	cout << "\nZad2\n\n";

	string source_path;

	cout << "Podaj sciezke z ktorej chcesz odczytac pliki: ";
	getline(cin, source_path);										

	fs::path p{source_path};

	if (fs::exists(source_path))
		cout << "plik istnieje\n";
	else
	{
		cout << "plik nie istnieje\n";
		return;
	}

	if (fs::is_directory(p))
		cout << "plik jest katalogiem\n\n";
	else
	{
		cout << "plik nie jest katalogiem\n\n";
		return;
	}
	
	for (const auto& entry : fs::directory_iterator(source_path)) 
			std::cout << entry << std::endl;
		
}

void zad3()
{
	cout << "\nZad3\n\n";

	string source_path = "./source";	
	string target_path = "./destination";
	string target_file_extension = ".txt";

	copyFiles(source_path, target_path, target_file_extension);
}

void copyFiles(const std::string& source_path, const std::string& target_path, const std::string& target_file_extension)
{
	fs::path source(source_path);
	fs::path target(target_path);

	if (!fs::exists(source)) {
		std::cout << "Bl¹d: katalog zrodlowy nie istnieje" << std::endl;
		return;
	}

	for (const auto& entry : fs::directory_iterator(source)) {
		if (fs::is_regular_file(entry) && entry.path().extension() == target_file_extension) {
			fs::copy(entry.path(), target / entry.path().filename(), fs::copy_options::overwrite_existing);
			std::cout << "Skopiowano: " << entry.path() << " do " << (target / entry.path().filename()) << std::endl;
		}
	}
}