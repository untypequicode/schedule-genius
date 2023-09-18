#include "eleves.hpp"
#include <iostream>

/*
on va creer des classes eleves
*/


class Eleve
{
public:
	int taille_tableau;
	std::string nom;
	std::string prenom;
	std::string niveau;
	std::string* matiere = new std::string[taille_tableau];
};

void test()
{
	int taille = 0;
	std::cin >> taille;
	std::string* matiere = new std::string[taille];
};