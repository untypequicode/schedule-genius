#include "import.hpp"

int ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile;

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl;
		std::cout << std::endl;
		myfile.open(nom_fichier);
		std::string ligne;
		std::getline(myfile, ligne);
		std::cout << ligne << std::endl;


	}
	else
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl;
	}
	return 0;
}

