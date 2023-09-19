#include "generateur_csv.hpp"

int tryplsidontwantthistobemylastword()
{
	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	return 0; 
}