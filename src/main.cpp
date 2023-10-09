#include "lib/generation_groupes.h"
#include "lib/generateur_csv.h"
#include "lib/import.h"
#include "lib/fichier.h"
#include "lib/dict_dyn/dict_dyn.h"



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
//    fichiertest.GetTexte();
    TabDynChar tabdyncharsplit(3);
//	tabdyncharsplit.Add(';');
//	tabdyncharsplit.Add(' ');
//	fichiertest.GiveTab(tabdyncharsplit);
//  std::cout << convertString("525") + convertString("58");
//  genererEleveViaCsv(nom_fichier);
//  fichiertest.GenererEleve();

    //// Ethan
    //
    Eleve eleve(0, "Ethan", "Facca", "L1");
    eleve.AddMatiere("Maths");
    eleve.AddMatiere("Physique");
    std::cout << eleve.GetMatiere(0) << std::endl;
    std::cout << eleve.GetMatiere(1) << std::endl;
    std::cout << eleve.GetMatiere(3) << std::endl;
//    Groupe groupe("L1", "info");
//    groupe.AddEleve(eleve);
//    std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
//    std::cout << groupe.GetEleve(0).m_prenom << std::endl;

    return 0;
}