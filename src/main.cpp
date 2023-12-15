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

    for(unsigned int i = 0; i < dict.GetNbElem(); i++)
        std::cout << dict.GetTabKeys().Get(i) << " : " << dict.GetTabValues().Get(i) << std::endl;
    std::cout << "nombre d'elements : " << dict.GetNbElem() << std::endl;

    std::cout <<  "filtre : = b or = a or = g" << std::endl;
    TabDynString condition;
    condition.Add("=");
    condition.Add("=");
    condition.Add("==");
    TabDynChar value;
    value.Add('b');
    value.Add('a');
    value.Add('g');
    TabDynString OrAnd;
    OrAnd.Add("or");
    OrAnd.Add("or");

    DictDynCharDouble dict_filtre = dict.FiltreKey(condition, value, OrAnd);

     for(unsigned int i = 0; i < dict_filtre.GetNbElem(); i++)
        std::cout << dict_filtre.GetTabKeys().Get(i) << " : " << dict_filtre.GetTabValues().Get(i) << std::endl;
        std::cout << "end";
    return 0;
}