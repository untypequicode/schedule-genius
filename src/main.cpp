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

    //// Ethan
    //
    DictDynCharDouble dict;
    dict.Add('a', 0.0);
    dict.Add('b', 1.1);
    dict.Add('c', 2.2);
    dict.Add('d', 3.3);
    dict.Add('e', 4.4);
    dict.Add('f', 5.5);
    dict.Add('g', 6.6);

    std::cout << "cles : ";
    for (unsigned int i = 0 ; i < dict.GetNbElem(); i++)
        std::cout << dict.GetTabKeys().Get(i) << " ; ";
    std::cout << std::endl;
    std::cout << "valeurs : ";
    for (unsigned int i = 0; i < dict.GetNbElem(); i++)
        std::cout << dict.GetTabValues().Get(i) << " ; ";
    std::cout << std::endl;
    std::cout << "taille du tableau de cle : " << dict.GetTabKeys().GetNbElem() << std::endl;
    std::cout << "taille du tableau de valeur : " << dict.GetTabValues().GetNbElem() << std::endl;
    std::cout << "taille du dictionnaire : " << dict.GetNbElem() << std::endl << std::endl;

    std::cout << "test de la fonction IfElement : " << std::endl;
    for(unsigned int i = 0; i < dict.GetNbElem(); i++)
    {
        std::cout << "est-ce que " << dict.GetTabValues().Get(i) << " est inferieur a 3.4 ?" << std::endl;
        if (dict.IfElement(i, "<", 3.4))
            std::cout << "oui" << std::endl;
        else
            std::cout << "non" << std::endl;
    }
    return 0;
}