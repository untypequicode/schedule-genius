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
    // CsvGenerateur exemple;
    // exemple.creerCsv(true);


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


    return 0;
}