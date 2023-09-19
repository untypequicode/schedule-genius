#ifndef DEF_UMPORT
#define DEF_UMPORT

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string ouvrirFichier(std::string const nom_fichier);

void test()
{
	std::string nom_fichier = "texte.txt";
	ouvrirFichier(nom_fichier);
}

#endif