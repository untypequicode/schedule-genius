#include "generateur_csv.hpp"

void creerCsv()
{
	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file nice.\n";
	myfile << "petit test pour tester.\n";
	myfile << "petit test pour tester(2).\n";
	myfile.close();
	std::cout << "Fini" << std::endl;
}