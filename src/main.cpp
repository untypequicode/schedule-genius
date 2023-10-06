#include "lib/generation_groupes.hpp"
#include "lib/generateur_csv.hpp"
#include "lib/import.hpp"
#include "lib/fichier.hpp"



int main()
{
	//// Micky
	//
	CsvGenerateur exemple;
	exemple.creerCsv();
	

	//// Vincent
	//
	std::string nom_fichier = "eleve.csv";
	Fichier fichiertest(nom_fichier, 201);
	//fichiertest.GetTexte();
	TabDynChar tabdyncharsplit(3);
	tabdyncharsplit.Add(';');
	tabdyncharsplit.Add(' ');
	fichiertest.GiveTab(tabdyncharsplit);
	//std::cout << convertString("525") + convertString("58");
	genererEleveViaCsv(nom_fichier);

	//// Ethan
	//
	Eleve eleve(0, "Ethan", "Facca", "L1");
	eleve.AddMatiere("Maths");
	eleve.AddMatiere("Physique");
	std::cout << eleve.GetMatiere(0) << std::endl;
	std::cout << eleve.GetMatiere(1) << std::endl;
	std::cout << eleve.GetMatiere(3) << std::endl;
	/*Groupe groupe("L1", "info");
	groupe.AddEleve(eleve);
	std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
	std::cout << groupe.GetEleve(0).m_prenom << std::endl;*/

	return 0;
}