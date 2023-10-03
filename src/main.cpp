#include "lib/eleves.hpp"
#include "lib/generation_groupes.hpp"
#include "lib/generateur_csv.hpp"
#include "lib/import.hpp"
#include "lib/tab_dyn/tab_dyn.hpp"
#include <iostream>
#include "lib/fichier.hpp""

int main()
{
	//// Micky
	//
	CsvGenerateur exemple;
	exemple.creerCsv();
	

	//// Vincent
	//
	std::string nom_fichier = "eleve.csv";
	//genererEleveViaCsv(nom_fichier);
	Fichier fichiertest(nom_fichier);
	fichiertest.GetTexte();
	//std::cout << convertString("525") + convertString("58");

	//// Ethan
	//
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
	std::cout << eleve.getMatiere(1) << std::endl;
	std::cout << eleve.getMatiere(3) << std::endl;
	Groupe groupe("L1", "info");
	groupe.AddEleve(eleve);
	std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
	std::cout << groupe.GetEleve(0).m_prenom << std::endl;*/

	return 0;
}