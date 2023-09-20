#include "import.hpp"

int ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile;

	if (myfile)
	{
		std::cout << "Le fichier est ouvert !!" << std::endl;
		myfile.open(nom_fichier);


	}
	else
	{
		std::cout << "Erreur d'ouverture du dossier";
	}
	return 0;
}

