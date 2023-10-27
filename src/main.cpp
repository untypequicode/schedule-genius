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

//    CsvGenerateur exemple(10);
//    exemple.creerCsv(true);


    //// Vincent

    std::string nom_fichier = "eleve.csv";
    Fichier fichiertest(nom_fichier, 201);
    Database datatest;
    datatest.EcraserData(fichiertest);
    TabDynString data;
    for(int i = 0; i <= 1; i++) {
        std::cout << "\nDEBUT" << std::endl;
        std::cout << "hello " << data.Get(0) << " jj " << data.Get(1) << data.Get(2) << data.Get(3)<< " fin" << std::endl;
        std::cout << "FIN\n" << std::endl;
        data = datatest.GetAllData(i);
        std::cout << "\ndebut" << std::endl;
        std::cout << "bjr " << datatest.GetEleve(i).GetId() << std::endl;
        std::cout << "hello " << data.Get(0) << " jj " << data.Get(1) << data.Get(2) << data.Get(3)<< " fin" << std::endl;
        std::cout << "fin\n" << std::endl;
    }


    return 0;
}