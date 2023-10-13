//
// Created by PC-VINCENT on 10/10/2023.
//

#include "database.h"

Database::Database()
    :m_taille(0),
    m_eleve(TabDynEleve(m_taille))

{

};

Database::Database(unsigned int taille)
    :m_taille(taille),
    m_eleve(TabDynEleve(m_taille))
{

};

Database::Database(const Database& database)
    :m_taille(database.m_taille),
    m_eleve(database.m_eleve)
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

void Database::AjusteTaille()
{
    m_taille = m_eleve.GetNbElem();
};

void Database::EcraserData(Fichier fichier)
{
    m_eleve.Clear();
    m_taille = fichier.GetNbLigne();
    {
        unsigned int indice = 0;
        TabDynString matiere(0);
        std::ifstream myfile;
        if (myfile)
        {
            myfile.open(fichier.GetNom());
            TabDynString data(5);
            std::string ligne = "";

            if (fichier.GetNbLigne() <= 0)
            {
                std::ifstream myfiletest;
                {
                    myfiletest.open(fichier.GetNom());
                    std::string lignetest;
                    std::getline(myfile, lignetest);

                    while (ligne != lignetest)
                    {
                        std::getline(myfile, ligne);
                        for(char carac : ligne)
                        {
                            m_taille += 1;
                            if (indice < 5)
                            {
                                if (carac != ';')
                                {
                                    data.Add(data.Pop(indice) + carac);
                                }
                            }

                            else if (indice < 5)
                            {
                                indice += 1;
                            }

                            else if (carac != ';')
                            {
                                matiere.Add(matiere.Pop() + carac);
                            }

                            else
                            {
                                matiere.Add("");
                            }

                        }

                        Eleve eleve(convertToInt(data.Pop(0)), data.Pop(0), data.Pop(0), data.Pop(0)));
                        m_eleve.Add(eleve)
                        std::getline(myfiletest, lignetest);
                        data.Clear();
                        indice = 0;
                    }
                }
            }

            else
            {

                for (unsigned int i = 0; i < m_nb_ligne; i++)
                {
                    std::getline(myfile, ligne);
                    for (char carac : ligne)
                    {
                        if (indice < 6)
                        {
                            if (carac != ';')
                            {
                                data.Add(data.Pop(indice) + carac);
                            }
                        }

                        else if (indice < 6)
                        {
                            indice += 1;
                        }

                        else if (carac != ';')
                        {
                            matiere.Add(matiere.Pop() + carac);
                        }

                        else
                        {
                            matiere.Add("");
                        }
                    }

                    Eleve eleve(convertToInt(data.Pop(0)), data.Pop(0), data.Pop(0), data.Pop(0));
                    data.Clear();
                    retour.Add(eleve);
                    indice = 0;
                }
            }
        }
    }
}
