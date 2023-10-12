#include "prof.h"

Prof::Prof()
 : Prof(0, "/0", "/0", 0)
{

}

Prof::Prof(unsigned int id, std::string prenom, std::string nom, unsigned int nb_heure)
 : m_id(id), m_prenom(prenom), m_nom(nom), m_nb_heure(nb_heure)
{

}

Prof::~Prof()
{

}

void Prof::SetNbHeure(unsigned int nb_heure)
{
    m_nb_heure = nb_heure;
}

unsigned int Prof::GetId() const
{
    return m_id;
}

std::string Prof::GetPrenom() const
{
    return m_prenom;
}

std::string Prof::GetNom() const
{
    return m_nom;
}

unsigned int Prof::GetNbHeure()
{
    return m_nb_heure;
}

void Prof::SetId(unsigned int id)
{
    m_id = id;
}

