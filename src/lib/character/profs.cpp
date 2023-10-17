#include "profs.h"

Profs::Profs()
 : Profs(0, "/0", "/0", 0)
{

}

Profs::Profs(unsigned int id, std::string prenom, std::string nom, unsigned int nb_heure)
 : m_id(id), m_prenom(prenom), m_nom(nom), m_nb_heure(nb_heure)
{

}

Profs::Profs(const Profs& profs)
 : m_id(profs.m_id), m_prenom(profs.m_prenom), m_nom(profs.m_nom), m_nb_heure(profs.m_nb_heure)
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

void SetHoraires(unsigned int horaires1, unsigned int horaires2)
{
    m_horaires_tab.Clear();
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}

void AddHoraires(unsigned int horaires1, unsigned int horaires2)
{
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}