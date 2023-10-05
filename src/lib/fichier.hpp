#ifndef DEF_FILE
#define DEF_FILE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tab_dyn/tab_dyn.hpp"

/*
* Classe Fichier
* Classe de stockage pour exploiter les fichiers
* COntient le nom du fichier et potentiellement son nombre de ligne
* 
* Constructeurs :
* Fichier() : m_name("empty.csv"), m_nb_ligne(0)
* Fichier(std::string nom_fichier) : m_name(nom_fichier), m_nb_ligne(-1) <= valeur inconnu
* Fichier(std::string nom_fichier, unsigned int nombre_de_ligne) : m_name(nom_fichier), m_nb_ligne(nombre_de_ligne)
* 
* Destructeur:
* ~Fichier()
* 
* Méthodes :
* 
* std::string Split(char split)
* std::string Split(char split, char split2)
* std::string Split(char split, char split2, char split3)
* std::string Split(char split, char split2, char split3, char split4)
* std::string Split(char split, char split2, char split3, char split4, char split5)
* TabDyn GiveMot(TabDyn split)
* 
* Accesseurs:
* std::string GetNom() const
* int GetNbLigne() const
* std::string GetTexte() const
* 
* Attributs :
* int or insigned int m_nb_ligne
* string m_name
*/
class Fichier
{
public:
	Fichier();
	//créer un fichier vide nommé empty.csv
	Fichier(std::string nom_fichier);
	//enregistre le fichier (privilégier un fichier existant)
	Fichier(std::string nom_fichier, unsigned int nombre_de_ligne);
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
	TabDyn GiveMot(TabDyn split);
	//renvoie le contenue du texte dans un tableau dynamique en séparant les élémens par les splits (qui ne seront pas inscrit dans le tableau)

private:
	int m_nb_ligne;

protected :
	std::string m_name;
};
#endif