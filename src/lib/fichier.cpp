#include "fichier.hpp"

Fichier::Fichier()
	: m_name("empty.txt"),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier)
	: m_name(nom_fichier),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier, int nb_ligne)
	: m_name(nom_fichier),
	m_nb_ligne(nb_ligne)
{

}

std::string Fichier::Split(char split)
{
	std::ifstream myfile;
	TabDynString data;
	myfile.open(nom_fichier);
	std::string ligne;
	std::string peche = "";
	while (true)
	{
		std::getline(myfile, ligne);
		for (char character : ligne)
		{
			if (character == end)
			{
				data.Add(peche);
				std::cout << peche << std::endl;
				return data;
			}

			if (character == split)
			{
				data.Add(peche);
				std::cout << peche << std::endl;
				peche = "";
			}

			else
			{
				peche += character;
			}
		}
	}
	return data;
}