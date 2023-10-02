#ifndef DEF_FILE
#define DEF_FILE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tab_dyn/tab_dyn.hpp"


class Fichier
{
	public:
		Fichier();
		Fichier(std::string);
		Fichier(std::string, int);
		~Fichier();

		std::string GetNom() const;
		std::string GetTexte() const;
		TabDynString Split(std::string nom_fichier, char split, char end);

	private:
		std::string m_name;
		int m_nb_ligne;
};
#endif