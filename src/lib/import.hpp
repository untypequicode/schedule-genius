#ifndef DEF_UMPORT
#define DEF_UMPORT

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

void ouvrirFichierParCaractere(std::string const nom_fichier)
/*
en paramètre le nom du fichier a ouvrir
le programme parcours chaque caractère du fichier
*/
#endif