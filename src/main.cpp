#include "lib/eleves.hpp"
#include "lib/groupes.hpp"
#include "lib/generation_groupes.hpp"
//#include "lib/generateur_csv.hpp"
#include "lib/import.hpp"
#include "lib/tableau_dynamique.hpp"
#include <iostream>

int main()
{

	//creerCsv();
	//std::string nom_fichier = "example.txt";
	/*Eleve eleve(0, "Ethan", "Facca", "L1");
	eleve.addMatiere("Maths");
	eleve.addMatiere("Physique");
	eleve.addMatiere("Anglais");
	eleve.addMatiere("Francais");
	eleve.addMatiere("Histoire");
	eleve.addMatiere("SVT");
	eleve.addMatiere("EPS");
	eleve.addMatiere("SI");
	eleve.addMatiere("Chimie");
	eleve.addMatiere("Allemand");
	eleve.addMatiere("Espagnol");
	eleve.addMatiere("Italien");
	eleve.addMatiere("Latin");
	eleve.addMatiere("Grec");
	eleve.addMatiere("Musique");
	eleve.addMatiere("Arts plastiques");
	eleve.addMatiere("Philosophie");
	eleve.addMatiere("Economie");
	eleve.addMatiere("Droit");
	eleve.addMatiere("Gestion");
	eleve.addMatiere("Informatique");
	eleve.addMatiere("Comptabilite");
	eleve.addMatiere("Marketing");
	eleve.addMatiere("Communication");
	eleve.addMatiere("Management");
	eleve.addMatiere("Ressources humaines");
	eleve.addMatiere("Logistique");
	std::cout << eleve.getMatiere(0) << std::endl;
	std::cout << eleve.getMatiere(10) << std::endl;
	std::cout << eleve.getMatiere(30) << std::endl;*/

	TabDyn tab(2);
	tab.AddElem(1);
	tab.AddElem(2);
	tab.AddElem(3);
	std::cout << "tab 0 : " << tab.GetElemInt(0) << std::endl;
	std::cout << "tab 1 : " << tab.GetElemInt(1) << std::endl;
	std::cout << "tab 2 : " << tab.GetElemInt(2) << std::endl;
	std::cout << "nombre elem : " << tab.GetNbElem() << std::endl;
	std::cout << "taille tab : " << tab.GetNbElemMax() << std::endl;
	tab.AddElem(4);
	tab.SetElemInt(0, 5);
	std::cout << "tab 0 : " << tab.GetElemInt(0) << std::endl;
	std::cout << "tab 1 : " << tab.GetElemInt(1) << std::endl;
	std::cout << "tab 2 : " << tab.GetElemInt(2) << std::endl;
	std::cout << "tab 3 : " << tab.GetElemInt(3) << std::endl;
	std::cout << "nombre elem : " << tab.GetNbElem() << std::endl;
	std::cout << "taille tab : " << tab.GetNbElemMax() << std::endl;


	//Groupe groupe("L1", "info");
	//groupe.AddEleve(eleve);
	//std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
	//std::cout << groupe.GetEleve(0).m_prenom << std::endl;

	return 0;
}