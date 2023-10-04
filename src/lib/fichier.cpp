#include "fichier.hpp"

Fichier::Fichier()
	: m_name("empty.csv"),
	m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier)
	: m_name(nom_fichier),
	m_nb_ligne(-1)
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

std::string Fichier::Split(char split, char split2)
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
						if (carac == split)
						{
							data += " ";
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
					if (carac == split)
					{
						data += " ";
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

std::string Fichier::Split(char split, char split2)
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
						if (carac == split or carac == split2)
						{
							data += " ";
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
					if (carac == split or carac == split2)
					{
						data += " ";
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

std::string Fichier::Split(char split, char split2, char split3)
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
						if (carac == split or carac == split2 or carac == split3)
						{
							data += " ";
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
					if (carac == split or carac == split2 or carac == split3)
					{
						data += " ";
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

std::string Fichier::Split(char split, char split2, char split3, char split4)
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
						if (carac == split or carac == split2 or carac == split3 or carac == split4)
						{
							data += " ";
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
					if (carac == split or carac == split2 or carac == split3 or carac ==split4)
					{
						data += " ";
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

std::string Fichier::Split(char split, char split2, char split3, char split4, char split5)
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
						if (carac == split or carac == split2 or carac == split3 or carac == split4 or carac == split5)
						{
							data += " ";
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
					if (carac == split or carac == split2 or carac == split3 or carac == split4 or carac == split5)
					{
						data += " ";
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