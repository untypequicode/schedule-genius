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
    //exemple.creerCsv(true);


    //// Vincent

//    Fichier fichier("eleve.csv");
//    Database database;
//    std::cout << "start ecraserdata" << std::endl;
//    database.EcraserData(fichier);
//    std::cout << "end ecraserdata" << std::endl;
//    TabDynString test = database.GetEleveData(0);
//    std::cout << "end getelevedata" << std::endl << std::endl;
//
//    std::cout << "sortie de getelevedata : TabDynString de format : ";
//    std::cout << "[";
//    for (unsigned int i = 0; i < test.GetNbElem(); i++) {
//        std::cout << test.Get(i) << ",";
//        if (i != test.GetNbElem() -1)
//            std::cout << " ";
//    }
//    std::cout << "]" << std::endl;
//
//    std::cout << "start geteleve" << std::endl;
//    Eleve test2 = database.GetEleve(1);
//    std::cout << "end geteleve" << std::endl << std::endl;
//    std::cout << "sortie de geteleve : TabDynString de format : ";
//    std::cout << "[" << test2.GetId() << ", " << test2.GetPrenom() << ", " << test2.GetNom() << ", " << test2.GetNiveauScolaire() << "]" << std::endl;
//    //// Ethan
    //

    DictDynCharDouble dict;
    dict.Add('a', 0.0);
    dict.Add('b', 1.1);
    dict.Add('c', 2.2);
    dict.Add('d', 3.3);
    dict.Add('e', 4.4);
    dict.Add('f', 5.5);
    dict.Add('g', 6.6);

    for(unsigned int i = 0; i < dict.GetNbElem(); i++)
        std::cout << dict.GetTabKeys().Get(i) << " : " << dict.GetTabValues().Get(i) << std::endl;
    std::cout << "nombre d'elements : " << dict.GetNbElem() << std::endl;

    TabDynString condition;
    condition.Add(">");
    condition.Add("<");
    condition.Add("=");
    TabDynDouble value;
    value.Add(1);
    value.Add(3);
    value.Add(4.4);
    TabDynString OrAnd;
    OrAnd.Add("and");
    OrAnd.Add("or");


    for (unsigned int i = 0; i < condition.GetNbElem(); i++)
        std::cout << "condition : '" << condition.Get(i) << "'" << std::endl;

    std::cout << "test" << std::endl;

    DictDynCharDouble dict_filtre = dict.FiltreValue(condition, value, OrAnd);
//    DictDynCharDouble dict_filtre = DictDynCharDouble();


    unsigned int i = 0;
    unsigned int nb_parenthèse = condition.GetNbElem() - 1;
    std::cout << "filtre : ";
    for (unsigned int i = 0; i < nb_parenthèse; i++)
        std::cout << "(";
    while (i < condition.GetNbElem()) {
        std::cout << condition.Get(i) << value.Get(i);
        if (i != 0)
            std::cout << ")";
        std::cout << " ";
        std::cout << OrAnd.Get(i) << " ";
        i++;
    }
    std::cout << std::endl;
    for(unsigned int i = 0; i < dict_filtre.GetNbElem(); i++)
        std::cout << dict_filtre.GetTabKeys().Get(i) << " : " << dict_filtre.GetTabValues().Get(i) << std::endl;
    std::cout << "end test" << std::endl;
    return 0;
}