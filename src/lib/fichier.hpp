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
		Fichier(std::string, unsigned int);
		//enregistre le fichier ainsi que le nombre de ligne le composant
		~Fichier();

		std::string GetNom() const;
		//renvoie le nom du fichier
		std::string GetTexte() const;
		//renvoie le contenu textuel du fichier
		int GetNbLigne() const;
		//renvoie le nombre de ligne du fichier, ou -1 s'il n'a pas été rentré
		std::string Split(char split);
		//renvoie le texte du fichier, séparé par le Split
		std::string Split(char split, char split2);
		//renvoie le texte du fichier, séparé par les Split
		std::string Split(char split, char split2, char split3);
		//renvoie le texte du fichier, séparé par les Split
		std::string Split(char split, char split2, char split3, char split4);
		//renvoie le texte du fichier, séparé par les Split
		std::string Split(char split, char split2, char split3, char split4, char split5);
		//renvoie le texte du fichier, séparé par les Split

	private:
		std::string m_name;
		int m_nb_ligne;
};
#endif