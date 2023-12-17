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
    TabDynString retour(5);
    retour.Add(convertToString(m_eleve.Get(index).GetId()));
    retour.Add(m_eleve.Get(index).GetPrenom());
    retour.Add(m_eleve.Get(index).GetNom());
    retour.Add(m_eleve.Get(index).GetNiveauScolaire());
    for (unsigned int i = 0; i < m_eleve.Get(index).GetNbMatiere(); i++)
    {
        retour.Add(m_eleve.Get(index).GetMatiere(i));
    }
    return retour;
};

void Database::EcraserData(Fichier source)
{
    std::cout << "DEPART" << std::endl << std::endl;
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

    if (/*source.GetNbLigne() <= 0*/ true)
    {
        std::ifstream myfiletest;
        myfiletest.open(source.GetNom());
        std::string lignetest;
        std::getline(myfiletest, lignetest);
        std::getline(myfiletest, lignetest);
        std::getline(myfile, ligne);

        while(true)
        {
            std::cout << "depart de la " << last << "eme ligne" << std::endl;
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
            if(ligne == lignetest)
                break;
        }
    }
    std::cout << "FIN";
}

void Database::AjouterData(Fichier source)
{
}
