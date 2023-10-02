#include "fichier.hpp"

Fichier::Fichier()
	: m_name("empty.txt"),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier)
	: m_name(nom_fichier),
	m_nb_ligne(10000)
{

}

Fichier::Fichier(std::string nom_fichier, int nb_ligne)
	: m_name(nom_fichier),
	m_nb_ligne(nb_ligne)
{

}

Fichier::~Fichier()
{

}

std::string Fichier::GetNom() const
{
	return m_name;
}

TabDynString Fichier::Split(std::string nom_fichier, char split, char end)
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

std::string Fichier::GetTexte() const
{
	std::ifstream myfile;
	std::ifstream myfiletest;
	std::string data = "";
	if (myfile)
	{
		myfile.open(m_name);
		myfiletest.open(m_name);
		std::string ligne = "";
		std::string lignetest;
		std::getline(myfile, lignetest);

		//for (unsigned int i = 0; i < m_nb_ligne; i++)
		while(ligne != lignetest)
		{
			std::getline(myfile, ligne);
			for (char carac : ligne)
			{
				data += carac;
			}
			data += "\n";
			std::getline(myfiletest, lignetest);
		}
	}

	std::cout << data;
	return(data);
}