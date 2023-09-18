//#include "lib/import.hpp"
#include "lib/eleves.hpp"

#include <iostream>

int main()
{
	Eleve eleve(5);
	eleve.m_matieres[1] = "Maths";
	std::cout << eleve.m_matieres[1];

	return 0;
}