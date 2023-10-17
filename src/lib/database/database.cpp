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

TabDynString Database::GetAllData(unsigned int index) const
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
    m_eleve.Clear();
    TabDynEleve retour;
    std::ifstream myfile;
    TabDynString data;
    data.Add("");
    unsigned int indice = 0;
    std::string ligne = "";
    myfile.open(source.GetNom());

    if (source.GetNbLigne() <= 0)
    {
        std::ifstream myfiletest;
        myfiletest.open(source.GetNom());
        std::string lignetest;
        std::getline(myfiletest, lignetest);

        while (ligne != lignetest)
        {
            std::getline(myfile, ligne);
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
                    retour.Add(Eleve(convertToInt(data.Get(0)), data.Get(1), data.Get(2), data.Get(3)));
                    data.Clear();
                }
            }
        }
    }
}

void Database::AjouterData(Fichier source)
{
}
