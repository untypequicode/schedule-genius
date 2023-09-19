#include "import.hpp"

/*void ouvrirFichier()
{
	std::ifstream fichier("fichier.txt", std::ios::in); // Ouvre le fichier en lecture

	if (fichier)
	{
		std::string ligne;

		while (std::getline(fichier, ligne)) // Lit le fichier ligne par ligne
		{
			std::cout << ligne << std::endl; // Affiche la ligne
		}

		fichier.close(); // Ferme le fichier
	}
}*/

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile;

	if (myfile)
	{
		std::cout << "Le fichier est ouvert !!";
		myfile.open(nom_fichier);


	}
	else
	{
		std::cout << "Erreur d'ouverture du dossier";
	}
	return "a";
}

