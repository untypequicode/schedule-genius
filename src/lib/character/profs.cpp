#include "profs.h"

Profs::Profs()
 : Profs(0, "/0", "/0", 0)
{

}

Profs::Profs(unsigned int id, std::string prenom, std::string nom, unsigned int nb_heure)
 : m_id(id), m_prenom(prenom), m_nom(nom), m_nb_heure(nb_heure)
{

}



Profs::~Profs()
{

}

void Profs::SetNbHeure(unsigned int nb_heure)
{
    m_nb_heure = nb_heure;
}

unsigned int Profs::GetId() const
{
    return m_id;
}

std::string Profs::GetPrenom() const
{
    return m_prenom;
}

std::string Profs::GetNom() const
{
    return m_nom;
}

unsigned int Profs::GetNbHeure()
{
    return m_nb_heure;
}

void Profs::SetId(unsigned int id)
{
    m_id = id;
}

