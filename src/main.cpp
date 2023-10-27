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

    CsvGenerateur exemple(10);
    exemple.creerCsv(true);


    //// Vincent

    std::string nom_fichier = "eleve.csv";
    Fichier fichiertest(nom_fichier, 201);
    Database datatest;
    datatest.EcraserData(fichiertest);
    for(int i = 0; i < 10; i++) {
        TabDynString data = datatest.GetAllData(i);
        std::cout << data.Get(0) << " " << data.Get(1) << " " << data.Get(2) << data.Get(3) << std::endl;
    }


    return 0;
}