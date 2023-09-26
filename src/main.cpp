#include "lib/eleves.hpp"
#include "lib/groupes.hpp"
#include "lib/generation_groupes.hpp"
//#include "lib/generateur_csv.hpp"
//#include "lib/import.hpp"
#include "lib/tableau_dynamique.hpp"
#include <iostream>

int main()
{

	//creerCsv();
	//std::string nom_fichier = "example.txt";
	//ouvrirFichierParLigne(nom_fichier);
	//ouvrirFichierParMot(nom_fichier);
	//ouvrirFichierParCaractere(nom_fichier);
	/*Eleve eleve(1, "Ethan", "Facca", "L1");
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

	TabDyn a_a();
	TabDyn a_b(10);
	a_b.AddElem(1);
	a_b.AddElem(2);
	a_b.AddElem(3);
	std::cout << "a_b 0 : " << a_b.GetElemInt(0) << std::endl;
	std::cout << "a_b 1 : " << a_b.GetElemInt(1) << std::endl;
	std::cout << "a_b 2 : " << a_b.GetElemInt(2) << std::endl;
	std::cout << "a_b 0 : " << a_b.GetTabInt()[0] << std::endl;
	a_b.SetElemInt(0, 4);
	std::cout << "a_b 0 : " << a_b.GetElemInt(0) << std::endl;
	std::cout << "a_b len : " << a_b.GetNbElem() << std::endl;
	std::cout << "a_b lenmax : " << a_b.GetNbElemMax() << std::endl;




	//Groupe groupe("L1", "info");
	//groupe.AddEleve(eleve);
	//std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
	//std::cout << groupe.GetEleve(0).m_prenom << std::endl;

	return 0;
}