#include "lib/eleves.hpp"
#include "lib/groupes.hpp"
#include "lib/generation_groupes.hpp"
#include "lib/generateur_csv.hpp"
#include "lib/import.hpp"

#include <iostream>

int main()
{

	creerCsv();
	std::string nom_fichier = "example.txt";
	ouvrirFichier(nom_fichier);
	/*Eleve eleve("Ethan", "Facca", "L1", 10);
	eleve.SetMatiere("Maths", 1);
	std::cout << eleve.GetMatiere(1) << std::endl;
	Groupe groupe("L1", "info");*/
	//groupe.AddEleve(eleve);
	//std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
	//std::cout << groupe.GetEleve(0).m_prenom << std::endl;

	return 0;
}