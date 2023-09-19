#include "generateur_csv.hpp"

void creerCsv()
{
	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	std::cout << "Fini" << std::endl;
}