//
// Created by PC-VINCENT on 10/10/2023.
//

#include "database.h"

Database::Database()
    :m_eleve(TabDynEleve(0))

{

};

Database::Database(unsigned int taille)
    :m_eleve(TabDynEleve(taille))
{

};

Database::Database(const Database& database)
    :m_eleve(database.m_eleve)
{

};

Database::~Database()
{

};

Eleve Database::GetEleve(unsigned int index) const
{
    return m_eleve.Get(index);
};

TabDynEleve Database::GetEleve() const
{
    return m_eleve;
};

TabDynString Database::GetEleveData(unsigned int index) const
{
    std::cout << "start getelevedata" << std::endl;
    std::cout << "creation du tableau de retour" << std::endl;
    TabDynString retour;
    std::cout << "creation du tableau de retour : ok" << std::endl;
    std::cout << "extraction de l'id" << std::endl;
//    int temp = m_eleve.Get(index).GetId();
    std::cout << "extraction de l'id : echec, generation d'un substitue : 0" << std::endl;
    int temp = 0;
    std::cout << "conversion de l'id" << std::endl;
    std::string id = convertToString(temp);
    std::cout << "conversion de l'id : ok" << std::endl;
    std::cout << "ajout de l'id" << std::endl;
    retour.Add(id);
    std::cout << "ajout de l'id : ok" << std::endl;
    std::cout << "extraction du prenom" << std::endl;
    //td::string prenom = m_eleve.Get(index).GetPrenom();
    std::cout << "extraction du prenom : echec, generation d'un substitue : 'prenom'" << std::endl;
    std::string prenom = "prenom";
    std::cout << "ajout du prenom" << std::endl;
    retour.Add(prenom);
    std::cout << "ajout du prenom : ok" << std::endl;
    std::cout << "extraction du nom" << std::endl;
    //std::string nom = m_eleve.Get(index).GetNom();
    std::cout << "extraction du nom : echec, generation d'un substitue : 'nom'" << std::endl;
    std::string nom = "nom";
    std::cout << "ajout du nom" << std::endl;
    retour.Add(nom);
    std::cout << "ajout du nom : ok" << std::endl;
    std::cout << "extraction du niveau scolaire" << std::endl;
    //std::string annee = m_eleve.Get(index).GetNiveauScolaire();
    std::cout << "extraction du niveau scolaire : echec, generation d'un substitue : 'niveau scolaire'" << std::endl;
    std::string annee = "niveau scolaire";
    std::cout << "ajout du niveau scolaire" << std::endl;
    retour.Add(annee);
    std::cout << "ajout du niveau scolaire : ok" << std::endl;
    std::cout << "extraction des matieres" << std::endl;
    TabDynString matieres;
//    for (unsigned int i = 0; i < m_eleve.Get(index).GetNbMatiere(); i++)
//    {
//        matieres.Add(m_eleve.Get(index).GetMatiere(i));
//    }
    std::cout << "extraction des matieres : echec, generation d'un substitue : TabDynString de format ['matiere1', 'matiere2']" << std::endl;
    matieres.Add("matiere1");
    matieres.Add("matiere2");
    std::cout << "ajout des matieres" << std::endl;
    for (unsigned int i = 0; i < matieres.GetNbElem(); i++)
    {
        retour.Add(matieres.Get(i));
    }
    std::cout << "ajout des matieres : ok" << std::endl;
    return retour;
};

unsigned int Database::GetNbEleve() const
{
    return m_eleve.GetNbElem();
};

void Database::EcraserData(Fichier source)
{
    m_eleve.Clear();
    TabDynEleve retour(10);
    std::ifstream myfile;
    TabDynString data;
    data.Add("");
    TabDynString matieres;
    unsigned int indice = 0;
    std::string ligne = "";
    myfile.open(source.GetNom());
    unsigned int last = 0;

    if (/*source.GetNbLigne() <= 0*/ true) // TODO : changer le if pour qu'il soit fonctionnel quand les Eleve seront implémentable
    {
        std::ifstream myfiletest;
        myfiletest.open(source.GetNom());
        std::string lignetest;
        std::getline(myfiletest, lignetest);
        std::getline(myfiletest, lignetest);
        std::getline(myfile, ligne);

        while(ligne != lignetest)
        {
            std::getline(myfile, ligne);
            matieres.Add("");
            for(char carac : ligne)
            {
                if (indice < 4)
                {
                    if (carac == ';')
                    {
                        data.Add("");
                        indice++;
                    }
                    else
                    {
                        data.Add(data.Pop(indice) + carac);
                    }
                }
                else
                {
                    if (carac == ';')
                    {
                        matieres.Add("");
                    }
                    else
                    {
                        matieres.Add(matieres.Pop() + carac);
                    }
                }
            }
            // TODO : inserer les donnée des eleves quand les Eleve seront implémentable
//            Eleve eleve(convertToInt(data.Get(0)), data.Get(1), data.Get(2), data.Get(3));
//            eleve.SetSecurity(false);
//            retour.Add(eleve);
//            std::cout << eleve.GetId() << " " << eleve.GetNom() << eleve.GetPrenom() << eleve.GetNiveauScolaire() << std::endl;
//            data.Clear();
//            std::cout << "Matieres facultatives : " << std::endl;
//            for (unsigned int i = 0; i < matieres.GetNbElem(); i++)
//            {
//                retour.Get(last).AddMatiere(matieres.Get(i));
//                std::cout << matieres.Get(i) << std::endl;
//            }
//            matieres.Clear();
//            indice = 0;
//            last++;
//            std::getline(myfiletest, lignetest);
//            std::cout << "fin de la " << last -1 << "eme ligne" << std::endl;
//            std::cout << "test : " << (ligne != lignetest) << std::endl << std::endl;

        }
        // TODO : recoder a boucle en fonction de la taille du fichier
    }
}

void Database::AjouterData(Fichier source)
{
    // TODO : coder la fonction AjouterData a partir de la fonction EcraserData
}
