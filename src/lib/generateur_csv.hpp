#ifndef DEF_GENERATEUR_CSV
#define DEF_GENERATEUR_CSV

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

void creerCsv();

std::string None = "None";

std::vector <std::string> PRENOM = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack",
"Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor",
"Ursula", "Victor", "Wendy", "Xavier", "Yasmine", "Zane" };

std::vector <std::string> NOM = {"Dupont", "Martin", "Dubois", "Bernard", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy",
"Moreau", "Simon", "Laurent", "Lefebvre", "Michel", "Garcia", "David", "Roux", "Bonnet", "Fournier",
"Lopez", "Legrand", "Martinez", "Ferreira", "Fernandez", "Blanc", "André", "Leroux", "Rousseau" };

std::vector <std::string> MATIERE_SPE = {"Francais", "Histoire" "Geo", "EMC", "EPS", "SPC", "SVT", "Maths", "NSI", "Philo",
"Anglais", "Espagnole", "Allemand", "Italien", "Russe" };

#endif