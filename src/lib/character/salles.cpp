#include "salles.h"

Salles::Salles()
 : Salles(0, "/0",
          0, 0)
{

}

Salles::Salles(unsigned int id,
               std::string nom,
               unsigned int horaires1,
               unsigned int horaires2)
 : m_id(id), m_nom(nom)
{
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}

Salles::Salles(const Salles& salles)
 : m_id(salles.m_id),
 m_nom(salles.m_nom),
 m_horaires_tab(salles.m_horaires_tab)
{

}

Salles::~Salles()
{

}

std::string Salles::GetNom()
{
    return m_nom;
}

unsigned int Salles::GetId()
{
    return m_id;
}

TabDynInt Salles::GetHoraires()
{
    return m_horaires_tab;
}

void Salles::SetHoraires(unsigned int horaires1, unsigned int horaires2)
{
    m_horaires_tab.Clear();
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}

void Salles::AddHoraires(unsigned int horaires1, unsigned int horaires2)
{
    m_horaires_tab.Add(horaires1);
    m_horaires_tab.Add(horaires2);
}