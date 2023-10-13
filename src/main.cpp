#include "lib/generation_groupes.h"
#include "lib/generateur_csv.h"
#include "lib/import.h"
#include "lib/fichier.h"
#include "lib/dict_dyn/dict_dyn.h"
#include "lib/character/matieres.h"
#include "lib/character/profs.h"
#include "lib/character/salles.h"
#include "lib/character/groupes.h"
//#include "lib/database/database.h"

int main()
{
    //// Micky
    //
    CsvGenerateur exemple;
    exemple.creerCsv();
    Profs ethan(1, "Ethan", "Facca", 5);
    Profs vincent(2, "Vincent", "Bouquet", 5);
    Matieres maths("Maths", 1, 5);
    Matieres physique("Physique", 2, 5);
    ethan.SetNbHeure(10);
    Salles salle(1, "A1", 12, 18);
    salle.SetHoraires(11,17);
//    std::cout <<ethan.GetNbHeure() << std::endl;
    salle.AddHoraires(10,16);
    for (int i=0 ; i < salle.GetHoraires().GetNbElem(); i++)
    {
        std::cout << salle.GetHoraires().Get(i) << std::endl;
    }

    //// Vincent
    //
//    std::string nom_fichier = "eleve.csv";
//    Fichier fichiertest(nom_fichier, 201);
//    Database datatest();
//    std::cout << convertToString(-54) << convertToString(132) << '\n';
//    fichiertest.GetTexte();
//  genererEleveViaCsv(nom_fichier);

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
//      DictDynIntString dictDynIntString(5);
//        dictDynIntString.Add(0, "test");
//        dictDynIntString.Add(1, "test2");
//        dictDynIntString.Add(2, "test3");
//        dictDynIntString.Add(3, "test4");
//        dictDynIntString.Add(4, "test5");
//        std::cout << dictDynIntString.Get(0) << std::endl;
//        std::cout << dictDynIntString.Get(1) << std::endl;
//        std::cout << dictDynIntString.Get(2) << std::endl;
//        std::cout << dictDynIntString.Get(3) << std::endl;
//        std::cout << dictDynIntString.Get(4) << std::endl;
//        std::cout << "..." << std::endl;
//        dictDynIntString.Remove(2);
//        std::cout << dictDynIntString.Get(0) << std::endl;
//        std::cout << dictDynIntString.Get(1) << std::endl;
//        std::cout << dictDynIntString.Get(2) << std::endl;
//        std::cout << dictDynIntString.Get(3) << std::endl;
//        std::cout << dictDynIntString.Get(4) << std::endl;
//        std::cout << "..." << std::endl;
//        dictDynIntString.Pop(1);
//        std::cout << dictDynIntString.Get(0) << std::endl;
//        std::cout << dictDynIntString.Get(1) << std::endl;
//        std::cout << dictDynIntString.Get(2) << std::endl;
//        std::cout << dictDynIntString.Get(3) << std::endl;
//        std::cout << dictDynIntString.Get(4) << std::endl;
//        std::cout << "..." << std::endl;
//        dictDynIntString.Set(0, "test6");
//        std::cout << dictDynIntString.Get(0) << std::endl;
//        std::cout << dictDynIntString.Get(1) << std::endl;
//        std::cout << dictDynIntString.Get(2) << std::endl;
//        std::cout << dictDynIntString.Get(3) << std::endl;
//        std::cout << dictDynIntString.Get(4) << std::endl;
//        std::cout << "..." << std::endl;
//        dictDynIntString.Pop();
//        std::cout << dictDynIntString.Get(0) << std::endl;
//        std::cout << dictDynIntString.Get(1) << std::endl;
//        std::cout << dictDynIntString.Get(2) << std::endl;
//        std::cout << dictDynIntString.Get(3) << std::endl;
//        std::cout << dictDynIntString.Get(4) << std::endl;

    return 0;
}