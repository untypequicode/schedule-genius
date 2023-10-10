#include "lib/generation_groupes.h"
#include "lib/generateur_csv.h"
#include "lib/import.h"
#include "lib/fichier.h"
#include "lib/dict_dyn/dict_dyn.h"
#include "lib/character/matieres.h"
#include "lib/database/database.h"




int main()
{
    //// Micky
    //
    CsvGenerateur exemple;
    exemple.creerCsv();


    //// Vincent
    //
//    std::string nom_fichier = "eleve.csv";
//    Fichier fichiertest(nom_fichier, 201);
    Database datatest();
    std::cout << convertToString(-54) << convertToString(132) << '\n';
//    fichiertest.GetTexte();
//  genererEleveViaCsv(nom_fichier);

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