//#include "lib/import.hpp"
#include "lib/eleves.hpp"
#include "lib/generation_groupes.hpp"

#include <iostream>

int main()
{
	Eleve eleve("Ethan", "Facca", "L1", 10);
	eleve.SetMatiere("Maths", 1);
	std::cout << eleve.GetMatiere(1) << std::endl;

	return 0;
}