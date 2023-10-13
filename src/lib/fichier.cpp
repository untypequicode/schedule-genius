#include "fichier.h"

Fichier::Fichier()
        : m_name("empty.csv"),
          m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier)
        : m_name(nom_fichier),
          m_nb_ligne(0)
{

}

Fichier::Fichier(std::string nom_fichier, unsigned int nb_ligne)
        : m_name(nom_fichier),
          m_nb_ligne(nb_ligne)
{

}

Fichier::~Fichier()
{

}

int Fichier::GetNbLigne() const
{
    return m_nb_ligne;
}

std::string Fichier::GetNom() const
{
    return m_name;
}

std::string Fichier::Split(TabDynChar split)
{
    std::ifstream myfile;
    bool test = false;
    if (myfile)
    {
        myfile.open(m_name);
        std::string data = "";
        std::string ligne = "";

        if (m_nb_ligne <= 0)
        {
            std::ifstream myfiletest;
            {
                myfiletest.open(m_name);
                std::string lignetest;
                std::getline(myfile, lignetest);

                while (ligne != lignetest)
                {
                    std::getline(myfile, ligne);
                    for (char carac : ligne)
                    {
                        for(int i = 0; i < split.GetNbElem(); i++)
                        {
                            if (carac == split.Get(i))
                            {
                                test = true;
                            }
                        }

                        if (test)
                        {
                            data += " ";
                            test = false;
                        }

                        else
                        {
                            data += carac;
                        }
                    }
                    data += "\n";
                    std::getline(myfiletest, lignetest);
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
                    for (int i = 0; i < split.GetNbElem(); i++)
                    {
                        if (carac == split.Get(i))
                        {
                            test = true;
                        }
                    }

                    if (test)
                    {
                        data += " ";
                        test = false;
                    }

                    else
                    {
                        data += carac;
                    }
                }
                data += "\n";
            }
        }

        std::cout << data;
        return(data);
    }

    else
    {
        std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
        return "";
    }
}

std::string Fichier::GetTexte() const
{
    std::ifstream myfile;
    if (myfile)
    {
        myfile.open(m_name);
        std::string data = "";
        std::string ligne = "";

        if (m_nb_ligne <= 0)
        {
            std::ifstream myfiletest;
            {
                myfiletest.open(m_name);
                std::string lignetest;
                std::getline(myfile, lignetest);

                while (ligne != lignetest)
                {
                    std::getline(myfile, ligne);
                    for (char carac : ligne)
                    {
                        data += carac;
                    }
                    data += "\n";
                    std::getline(myfiletest, lignetest);
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
                    data += carac;
                }
                data += "\n";
            }
        }

        std::cout << data;
        return(data);
    }

    else
    {
        std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
        return "";
    }
}

TabDynString Fichier::GiveTab(TabDynChar split)
{
    TabDynString retour(0, 1, 100);
    std::ifstream myfile;
    bool test = false;
    if (myfile)
    {
        myfile.open(m_name);
        std::string data = "";
        std::string ligne = "";

        if (m_nb_ligne <= 0)
        {
            std::ifstream myfiletest;
            {
                myfiletest.open(m_name);
                std::string lignetest;
                std::getline(myfile, lignetest);

                while (ligne != lignetest)
                {
                    std::getline(myfile, ligne);
                    for (char carac : ligne)
                    {
                        for (int i = 0; i < split.GetNbElem(); i++)
                        {
                            if (carac == split.Get(i))
                            {
                                test = true;
                            }
                        }

                        if (test)
                        {
                            data += " ";
                            test = false;
                        }

                        else
                        {
                            data += carac;
                        }
                    }
                    retour.Add(data);
                    std::getline(myfiletest, lignetest);
                    data = "";
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
                    for (int i = 0; i < split.GetNbElem(); i++)
                    {
                        if (carac == split.Get(i))
                        {
                            test = true;
                        }
                    }

                    if (test)
                    {
                        data += " ";
                        test = false;
                    }

                    else
                    {
                        data += carac;
                    }
                }
                retour.Add(data);
                data = "";
            }
        }
        return(retour);
    }

    else
    {
        std::cerr << "OPENERROR : impossible d'ouvrir le fichier selectionné";
        return TabDynString(0);
    }
}

TabDynEleve Fichier::GenererEleve()
{
    TabDynEleve retour(m_nb_ligne);
    unsigned int indice = 0;
    TabDynString matiere(3);
    std::ifstream myfile;
    if (myfile)
    {
        myfile.open(m_name);
        TabDynString data(5);
        TabDynString matiere(2);
        std::string ligne = "";

        if (m_nb_ligne <= 0)
        {
            std::ifstream myfiletest;
            {
                myfiletest.open(m_name);
                std::string lignetest;
                std::getline(myfile, lignetest);

                while (ligne != lignetest)
                {
                    std::getline(myfile, ligne);
                    for (char carac : ligne)
                    {
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

                    Eleve eleve(convertToInt(data.Pop(0)), data.Pop(0), data.Pop(0), data.Pop(0));
                    std::getline(myfiletest, lignetest);
                    data.Clear();
                    retour.Add(eleve);
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
    return retour;
}

int convertToInt(std::string nombre)
{
    int convert = 0;
    for (char nb : nombre)
    {
        if (nb == '0')
        {
            convert *= 10;
        }

        else if (nb == '1')
        {
            convert = convert * 10 + 1;
        }

        else if (nb == '2')
        {
            convert = convert * 10 + 2;
        }

        else if (nb == '3')
        {
            convert = convert * 10 + 3;
        }

        else if (nb == '4')
        {
            convert = convert * 10 + 4;
        }

        else if (nb == '5')
        {
            convert = convert * 10 + 5;
        }

        else if (nb == '6')
        {
            convert = convert * 10 + 6;
        }

        else if (nb == '7')
        {
            convert = convert * 10 + 7;
        }

        else if (nb == '8')
        {
            convert = convert * 10 + 8;
        }

        else if (nb == '9')
        {
            convert = convert * 10 + 9;
        }
    }
    return convert;
}

std::string convertToString(int nombre)
{
    if (nombre == 0)
    {
        return "0";
    }

    std::string convert = "";
    char signe = ' ';

    if (nombre < 0)
    {
        nombre *= -1;
        signe = '-';
    }

    while(nombre != 0)
    {
        int nb = nombre % 10;
        nombre /= 10;

        if (nb == 0)
        {
            convert = "0" + convert;
        }

        else if (nb == 1)
        {
            convert = "1" + convert;
        }

        else if (nb == 2)
        {
            convert = "2" + convert;
        }

        else if (nb == 3)
        {
            convert = "3" + convert;
        }

        else if (nb == 4)
        {
            convert = "4" + convert;
        }

        else if (nb == 5)
        {
            convert = "5" + convert;
        }

        else if (nb == 6)
        {
            convert = "6" + convert;
        }

        else if (nb == 7)
        {
            convert = "7" + convert;
        }

        else if (nb == 8)
        {
            convert = "8" + convert;
        }

        else if (nb == 9)
        {
            convert = "9" + convert;
        }
    }
    return signe + convert;
}

std::string convertToString(unsigned int nombre) {
    if (nombre == 0) {
        return "0";
    }

    std::string convert = "";
    char signe = ' ';

    if (nombre < 0) {
        nombre *= -1;
        signe = '-';
    }

    while (nombre != 0) {
        int nb = nombre % 10;
        nombre /= 10;

        if (nb == 0) {
            convert = "0" + convert;
        } else if (nb == 1) {
            convert = "1" + convert;
        } else if (nb == 2) {
            convert = "2" + convert;
        } else if (nb == 3) {
            convert = "3" + convert;
        } else if (nb == 4) {
            convert = "4" + convert;
        } else if (nb == 5) {
            convert = "5" + convert;
        } else if (nb == 6) {
            convert = "6" + convert;
        } else if (nb == 7) {
            convert = "7" + convert;
        } else if (nb == 8) {
            convert = "8" + convert;
        } else if (nb == 9) {
            convert = "9" + convert;
        }
    }
    return signe + convert;
}