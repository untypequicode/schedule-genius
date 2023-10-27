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

//    CsvGenerateur exemple;
//    exemple.creerCsv(true);


    //// Vincent

    std::string nom_fichier = "eleve.csv";
    Fichier fichiertest(nom_fichier, 201);
    Database datatest;
    datatest.EcraserData(fichiertest);
    TabDynString data = datatest.GetAllData(1);
    for(int i = 0; i < 200; i++)
        std::cout << datatest.GetEleve(i).GetId() << datatest.GetEleve(i).GetNom() << datatest.GetEleve(i).GetPrenom() << datatest.GetEleve(i).GetNiveauScolaire() << std::endl;


    return 0;
}