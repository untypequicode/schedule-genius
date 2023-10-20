#include "lib/generation_groupes.h"
#include "lib/generateur_csv.h"
#include "lib/import.h"
#include "lib/fichier.h"
#include "lib/dict_dyn/dict_dyn.h"
#include "lib/database/database.h"
#include "lib/character/eleves.h"
#include "lib/character/groupes.h"
#include "lib/character/profs.h"
#include "lib/character/matieres.h"




int main()
{
    //// Micky
    //
//    TabDynInt tabDynInt(5);
//    tabDynInt.SetSecurity(false);
//    for (int i = 0; i < 10; i++)
//    {
//        tabDynInt.Add(i);
//    }
//    std::cout << tabDynInt.Get(0) << std::endl;
    CsvGenerateur exemple;
    exemple.creerCsv();


    //// Vincent

    std::string nom_fichier = "eleve.csv";
    Fichier fichiertest(nom_fichier, 201);
    Database datatest;
    datatest.EcraserData(fichiertest);
    std::cout << "fin" << std::endl;
//    for(int i = 0; i < datatest.GetEleve(0).GetNbMatiere(); i++)
//    {
//        std::cout << datatest.GetEleve(0).GetMatiere(i) << std::endl;
//    }


    //// Ethan
    //
//    Eleve eleve(0, "Ethan", "Facca", "L1");
//    eleve.AddMatiere("Maths");
//    eleve.AddMatiere("Physique");
//    std::cout << eleve.GetMatiere(0) << std::endl;
//    std::cout << eleve.GetMatiere(1) << std::endl;
//    std::cout << eleve.GetMatiere(3) << std::endl;
//    Groupe groupe("L1", "info");
//    groupe.AddEleve(eleve);
//    std::string matiere_eleve = groupe.GetEleve(0).GetMatiere(1);
//    std::cout << groupe.GetEleve(0).m_prenom << std::endl;



    return 0;
}