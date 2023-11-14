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
dict.Add('a', 1.0);
dict.Add('b', 2.0);
dict.Add('c', 3.0);
dict.Add('d', 4.0);
dict.Add('e', 5.0);
dict.Add('f', 6.0);
dict.Add('g', 7.0);
dict.Add('h', 8.0);
dict.Add('i', 9.0);
dict.Add('j', 10.0);
TabDynChar key = dict.GetTabKeys();
TabDynDouble value = dict.GetTabValues();
for(unsigned int i =0; i < key.GetNbElem(); i++)
{
    std::cout << key.Get(i) << " : " << value.Get(i) << std::endl;
}



    return 0;
}