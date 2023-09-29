#ifndef DEF_FILE
#define DEF_FILE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


class Fichier
{
	public:
		Fichier();
		Fichier(std::string);
		Fichier(std::string, int);
		~Fichier();

		std::string GetTexte() const;
		std::string Split(char split);

	private:
		std::string m_name;
		int m_nb_ligne;
};
#endif