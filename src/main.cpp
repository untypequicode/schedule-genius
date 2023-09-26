#include "lib/eleves.hpp"
#include "lib/groupes.hpp"
#include "lib/generation_groupes.hpp"
//#include "lib/generateur_csv.hpp"
//#include "lib/import.hpp"
#include "lib/tableau_dynamique.hpp"
#include <iostream>

int main()
{
	//// Micky
	// 
	//creerCsv();
	

	//// Vincent
	// 
	/*std::string nom_fichier = "example.txt";
	ouvrirFichierParLigne(nom_fichier);
	ouvrirFichierParMot(nom_fichier);
	ouvrirFichierParCaractere(nom_fichier);*/


	//// Ethan
	//
	/*Eleve eleve(0, "Ethan", "Facca", "L1");
	eleve.addMatiere("Maths");
	eleve.addMatiere("Physique");
	std::cout << eleve.getMatiere(0) << std::endl;
	std::cout << eleve.getMatiere(1) << std::endl;
	std::cout << eleve.getMatiere(3) << std::endl;
	Groupe groupe("L1", "info");
	groupe.AddEleve(eleve);
	std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
	std::cout << groupe.GetEleve(0).m_prenom << std::endl;*/
	TabDyn tab(10);
	std::cout << tab.getNbElem() << std::endl;
	std::cout << tab.getNbElemMax() << std::endl;
	TabDyn tab2;
	std::cout << tab2.getNbElem() << std::endl;
	std::cout << tab2.getNbElemMax() << std::endl;


	return 0;
}