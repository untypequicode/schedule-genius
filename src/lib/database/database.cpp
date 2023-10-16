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
    unsigned int indice = 0;
    std::ifstream myfile;
    if (myfile)
    {
        myfile.open(source.GetNom());
        TabDynString data(5);
        std::string ligne = "";
        if (source.GetNbLigne() <= 0)
        {
            std::ifstream myfiletest;
            {
                myfiletest.open(source.GetNom());
                std::string lignetest;
                std::getline(myfile, lignetest);
                while (ligne != lignetest)
                {
                    TabDynString matiere(0);
                    std::getline(myfile, ligne);
                    for(char carac : ligne)
                    {
                        if (indice < 5)
                        {
                            if (carac != ';')
                            {
                                data.Add(data.Pop(indice) + carac);
                            }

                            else
                            {
                                indice += 1;
                            }
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
                    eleve.CopyMatiere(matiere);
                    m_eleve.Add(eleve);
                    std::getline(myfiletest, lignetest);
                    data.Clear(false);
                    matiere.Clear(false);
                    indice = 0;
                }
            }
        }
        else
        {
            for (unsigned int i = 0; i < source.GetNbLigne(); i++)
            {
                TabDynString matiere(0);
                std::getline(myfile, ligne);
                for (char carac : ligne)
                {
                    if (indice < 6)
                    {
                        if (carac != ';')
                        {
                            data.Add(data.Pop(indice) + carac);
                        }
                        else
                        {
                            indice += 1;
                        }
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

                Eleve eleve(1, data.Pop(0), data.Pop(0), data.Pop(0));
                data.Clear(false);
                eleve.CopyMatiere(matiere);
                std::cout << eleve.GetPrenom() << std::endl;
//                m_eleve.Add(eleve);
                indice = 0;
            }
        }
    }
}

void Database::AjouterData(Fichier source)
{
    unsigned int indice = 0;
    TabDynString matiere(0);
    std::ifstream myfile;
    if (myfile)
    {
        myfile.open(source.GetNom());
        TabDynString data(5);
        std::string ligne = "";

        if (source.GetNbLigne() <= 0)
        {
            std::ifstream myfiletest;
            {
                myfiletest.open(source.GetNom());
                std::string lignetest;
                std::getline(myfile, lignetest);

                while (ligne != lignetest)
                {
                    std::getline(myfile, ligne);
                    for(char carac : ligne)
                    {
                        if (indice < 5)
                        {
                            if (carac != ';')
                            {
                                data.Add(data.Pop(indice) + carac);
                            }

                            else
                            {
                                indice += 1;
                            }
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
                    m_eleve.Add(eleve);
                    eleve.CopyMatiere(matiere);
                    std::getline(myfiletest, lignetest);
                    data.Clear(false);
                    matiere.Clear(false);
                    indice = 0;
                }
            }
        }

        else
        {
            for (unsigned int i = 0; i < source.GetNbLigne(); i++)
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

                        else
                        {
                            indice += 1;
                        }
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
                data.Clear(false);
                eleve.CopyMatiere(matiere);
                matiere.Clear(false);
                m_eleve.Add(eleve);
                indice = 0;
            }
        }
    }
}
