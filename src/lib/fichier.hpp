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
		//créer un fichier vide nommé empty.csv
		Fichier(std::string);
		//enregistre le fichier (privilégier un fichier existant)
		Fichier(std::string, int);
		//enregistre le fichier ainsi que le nombre de ligne le composant
		~Fichier();

		std::string GetNom() const;
		std::string GetTexte() const;
		int GetNbLigne() const;
		TabDynString Split(std::string nom_fichier, char split, char end);

	private:
		std::string m_name;
		int m_nb_ligne;
};
#endif