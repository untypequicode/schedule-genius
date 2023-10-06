#include "fichier.hpp"

Fichier::Fichier()
	: m_name("empty.csv"),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier)
	: m_name(nom_fichier),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier, unsigned int nb_ligne)
	: m_name(nom_fichier),
	m_nb_ligne(nb_ligne)
{

}

Fichier::~Fichier()
{

}

int Fichier::GetNbLigne() const
{
	return m_nb_ligne;
}

std::string Fichier::GetNom() const
{
	return m_name;
}

std::string Fichier::Split(TabDynChar split)
{
	std::ifstream myfile;
	bool test = false;
	if (myfile)
	{
		myfile.open(m_name);
		std::string data = "";
		std::string ligne = "";

		if (m_nb_ligne <= 0)
		{
			std::ifstream myfiletest;
			{
				myfiletest.open(m_name);
				std::string lignetest;
				std::getline(myfile, lignetest);

				while (ligne != lignetest)
				{
					std::getline(myfile, ligne);
					for (char carac : ligne)
					{
						for(int i = 0; i < split.GetNbElem(); i++)
						{
							if (carac == split.Get(i))
							{
								test = true;
							}
						}

						if (test)
						{
							data += " ";
							test = false;
						}

						else
						{
							data += carac;
						}
					}
					data += "\n";
					std::getline(myfiletest, lignetest);
				}
			}
		}

		else
		{

			for (unsigned int i = 0; i < m_nb_ligne; i++)
			{
				std::getline(myfile, ligne);
				for (char carac : ligne)
				{
					for (int i = 0; i < split.GetNbElem(); i++)
					{
						if (carac == split.Get(i))
						{
							test = true;
						}
					}

					if (test)
					{
						data += " ";
						test = false;
					}

					else
					{
						data += carac;
					}
				}
				data += "\n";
			}
		}

		std::cout << data;
		return(data);
	}

	else
	{
		std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
		return "";
	}
}

std::string Fichier::GetTexte() const
{
	std::ifstream myfile;
	if (myfile)
	{
		myfile.open(m_name);
		std::string data = "";
		std::string ligne = "";

		if (m_nb_ligne <= 0)
		{
			std::ifstream myfiletest;
			{
				myfiletest.open(m_name);
				std::string lignetest;
				std::getline(myfile, lignetest);

				while (ligne != lignetest)
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
		}

		else
		{

			for (unsigned int i = 0; i < m_nb_ligne; i++)
			{
				std::getline(myfile, ligne);
				for (char carac : ligne)
				{
					data += carac;
				}
				data += "\n";
			}
		}

		std::cout << data;
		return(data);
	}

	else
	{
		std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
		return "";
	}
}

TabDynString Fichier::GiveTab(TabDynChar split)
{
	TabDynString retour(0, 1, 100);
	std::ifstream myfile;
	bool test = false;
	if (myfile)
	{
		myfile.open(m_name);
		std::string data = ""; 
		std::string ligne = "";

		if (m_nb_ligne <= 0)
		{
			std::ifstream myfiletest;
			{
				myfiletest.open(m_name);
				std::string lignetest;
				std::getline(myfile, lignetest);

				while (ligne != lignetest)
				{
					std::getline(myfile, ligne);
					for (char carac : ligne)
					{
						for (int i = 0; i < split.GetNbElem(); i++)
						{
							if (carac == split.Get(i))
							{
								test = true;
							}
						}

						if (test)
						{
							data += " ";
							test = false;
						}

						else
						{
							data += carac;
						}
					}
					retour.Add(data);
					std::getline(myfiletest, lignetest);
					data = "";
				}
			}
		}

		else
		{

			for (unsigned int i = 0; i < m_nb_ligne; i++)
			{
				std::getline(myfile, ligne);
				for (char carac : ligne)
				{
					for (int i = 0; i < split.GetNbElem(); i++)
					{
						if (carac == split.Get(i))
						{
							test = true;
						}
					}

					if (test)
					{
						data += " ";
						test = false;
					}

					else
					{
						data += carac;
					}
				}
				retour.Add(data);
				data = "";
			}
		}
		return(retour);
	}

	else
	{
		std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
		return TabDynString(0);
	}
}

TabDynEleve Fichier::GenererEleve()
{
	TabDynEleve retour(m_nb_ligne);
	unsigned int indice = 0;
	std::ifstream myfile;
	if (myfile)
	{
		myfile.open(m_name);
		TabDynString data(5);
		TabDynString matiere(2);
		std::string ligne = "";

		if (m_nb_ligne <= 0)
		{
			std::ifstream myfiletest;
			{
				myfiletest.open(m_name);
				std::string lignetest;
				std::getline(myfile, lignetest);

				while (ligne != lignetest)
				{
					std::getline(myfile, ligne);
					for (char carac : ligne)
					{
						if (indice < 6)
						{
							if (carac != ';')
							{
								data.Add(data.Pop(indice) + carac);
							}
						}

						else if (indice < 6)
						{
							indice += 1;
						}

						else if (carac == ';')
						{

						}
					}

					Eleve eleve(convertString(data.Pop(0)), data.Pop(0), data.Pop(0), data.Pop(0), data.Pop(0));
					std::getline(myfiletest, lignetest);
					data.Clear();
				}
			}
		}

		else
		{

			for (unsigned int i = 0; i < m_nb_ligne; i++)
			{
				std::getline(myfile, ligne);
				for (char carac : ligne)
				{
					for (int i = 0; i < split.GetNbElem(); i++)
					{
						if (carac == split.Get(i))
						{
							test = true;
						}
					}

					if (test)
					{
						data += " ";
						test = false;
					}

					else
					{
						data += carac;
					}
				}
				data = "";
			}
		}
		return(eleves);
	}

	else
	{
		std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
		return TabDynEleve(0);
	}
}