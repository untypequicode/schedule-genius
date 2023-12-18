//
// Created by PC-VINCENT on 10/10/2023.
//

#include "database.h"

Database::Database()
    :m_eleve(TabDynEleve(0))
{

};

Database::Database(const Database& database)
    :m_eleve(database.m_eleve)
{

};

Database::~Database()
{

};

unsigned int Database::GetTaille() const
{
    return m_eleve.GetNbElem();
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

    return retour;
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

            Groupes groupetest;
            Eleve eleve(convertToInt(data.Get(0)), data.Get(1), data.Get(2), data.Get(3), groupetest);
            m_eleve.Add(eleve);
            data.Clear();
//            std::cout << "Matieres facultatives : " << std::endl;
//            for (unsigned int i = 0; i < matieres.GetNbElem(); i++)
//            {
//                retour.Get(last).AddMatiere(matieres.Get(i));
//                std::cout << matieres.Get(i) << std::endl;
//            }
            matieres.Clear();
            indice = 0;
            last++;
            std::getline(myfiletest, lignetest);
            if(ligne == lignetest)
                break;
        }
    }
    m_eleve.Pop();
}

void Database::AjouterData(Fichier source)
{

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

            Groupes groupetest;
            Eleve eleve(convertToInt(data.Get(0)), data.Get(1), data.Get(2), data.Get(3), groupetest);
            m_eleve.Add(eleve);
            data.Clear();
//            std::cout << "Matieres facultatives : " << std::endl;
//            for (unsigned int i = 0; i < matieres.GetNbElem(); i++)
//            {
//                retour.Get(last).AddMatiere(matieres.Get(i));
//                std::cout << matieres.Get(i) << std::endl;
//            }
            matieres.Clear();
            indice = 0;
            last++;
            std::getline(myfiletest, lignetest);
            if(ligne == lignetest)
                break;
        }
    }
    m_eleve.Pop();
}

void Database::SELECT(std::string table, std::string parametre)
{
    if (table == "eleve")
        TabDynEleve select = m_eleve; //TODO
}

void Database::SELECT(std::string table, std::string parametre, std::string condition, int valeur)
{
    if(table == "eleve") {
        if (parametre == "ID") {
            if (condition == "<" or condition == "<=")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetId() < valeur)
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            if(condition == "=" or condition == "==" or condition == "<=" or condition == ">=")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetId() == valeur)
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            if(condition == ">" or condition == ">=")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetId() > valeur)
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else if(condition == "!=")
            {
                for(unsigned int i =0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetId() != valeur)
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else
            {
                std::cerr << "Erreur : condition non reconnue" << std::endl;
            }
        }
        else if(parametre == "prenom")
        {
            if(condition == "=" or condition == "==")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetPrenom() == convertToString(valeur))
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else if(condition == "!=")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetPrenom() != convertToString(valeur))
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else
            {
                std::cerr << "Erreur : condition non reconnue" << std::endl;
            }
        }
        else if(condition == "nom")
        {
            if(condition == "=" or condition == "==")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetNom() == convertToString(valeur))
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else
            {
                std::cerr << "Erreur : condition non reconnue" << std::endl;
            }
        }
        else if(condition == "niveau_scolaire")
        {
            if(condition == "=" or condition == "==")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetNiveauScolaire() == convertToString(valeur))
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else if(condition == "!=")
            {
                for(unsigned int i = 0; i < m_eleve.GetNbElem(); i++)
                {
                    if(m_eleve.Get(i).GetNiveauScolaire() != convertToString(valeur))
                    {
                        std::cout << m_eleve.Get(i).GetId() << " " << m_eleve.Get(i).GetPrenom() << " " << m_eleve.Get(i).GetNom() << " " << m_eleve.Get(i).GetNiveauScolaire() << std::endl;
                    }
                }
            }
            else
            {
                std::cerr << "Erreur : condition non reconnue" << std::endl;
            }
        }
        else
        {
            std::cerr << "Erreur : parametre non reconnu" << std::endl;
        }
    }
}

void Database::SELECT(std::string table, std::string parametre, std::string condition, std::string valeur)
{
    return;
}