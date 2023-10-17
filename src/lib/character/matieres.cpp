#include "matieres.h"

Matieres::Matieres()
 : Matieres("/0", 0, 0)
{

}

Matieres::Matieres(std::string nom, unsigned int id,unsigned int nb_heure)
 : m_nom(nom), m_id(id), m_nb_heure(nb_heure)
{

}

Matieres::Matieres(const Matieres& matieres)
 : m_nom(matieres.m_nom), m_id(matieres.m_id), m_nb_heure(matieres.m_nb_heure)
{

}

Matieres::~Matieres()
{

}

void Matieres::SetNbHeure(unsigned int nb_heure)
{
    m_nb_heure = nb_heure;
}

std::string Matieres::GetNom()
{
    return m_nom;
}

unsigned int Matieres::GetId()
{
    return m_id;
}

unsigned int Matieres::GetNbHeure()
{
    return m_nb_heure;
}
