#include "profs.h"

Profs::Profs()
 : Profs(0, "/0",
         "/0", 0,
         0, 0)
{

}

Profs::Profs(unsigned int id,
             std::string prenom,
             std::string nom,
             unsigned int nb_heure,
             unsigned int horaires1,
             unsigned int horaires2)
 : m_id(id), m_prenom(prenom),
 m_nom(nom), m_nb_heure(nb_heure)
{
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}

Profs::Profs(const Profs& profs)
 : m_id(profs.m_id),
 m_prenom(profs.m_prenom),
 m_nom(profs.m_nom),
 m_nb_heure(profs.m_nb_heure),
 m_horaires_tab(profs.m_horaires_tab)
{

}

Profs::~Profs()
{

}

unsigned int Profs::GetNbHeure()
{
    return m_nb_heure;
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

TabDynInt Profs::GetHoraires()
{
    return m_horaires_tab;
}

void Profs::SetId(unsigned int id)
{
    m_id = id;
}

void Profs::SetNbHeure(unsigned int nb_heure)
{
    m_nb_heure = nb_heure;
}

void Profs::SetHoraires(unsigned int horaires1, unsigned int horaires2)
{
    m_horaires_tab.Clear();
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}

void Profs::AddHoraires(unsigned int horaires1, unsigned int horaires2)
{
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}

void Profs::SetPrenom(std::string prenom)
{
    m_prenom = prenom;
}

void Profs::SetNom(std::string nom)
{
    m_nom = nom;
}
