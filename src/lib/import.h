#ifndef DEF_UMPORT
#define DEF_UMPORT

#include <fstream>
#include <sstream>
#include "tab_dyn/tab_dyn.h"
#include "eleves.h"

std::string ouvrirFichierParLigne(std::string const nom_fichier);
/*
en paramètre le nom du fichier a ouvrir
le programme écrit en console les lignes du fichier ouvert et les renvoie
*/

std::string ouvrirFichierParMot(std::string const nom_fichier);
/*
en paramètre le nom du fichier a ouvrir
le programme parcours chaque mot du fichier
*/

void ouvrirFichierParCaractere(std::string const nom_fichier);
/*
en paramètre le nom du fichier a ouvrir
le programme parcours chaque caractère du fichier
*/


TabDynEleve genererEleveViaCsv(std::string const nom_fichier);
/*
encore en travail
en paramètre le nom du fichier à extraire
en surtie une liste des données rangés dans la classe Eleve d'Ethan
*/

TabDynString splitFichier(std::string nom_fichier, char split, char end);
/*
en parametre le fichier à lire, le caractere à sauter et la caracter (unique !) de fin
renvoie un tableau de valeur séparé par le split jusqu'à atteindre end
*/

int convertString(std::string nombre);
/*
transforme la chaine de caractère entrée en int si correspondance
*/
#endif