#include "matieres.h"

Matieres::Matieres()
    : m_id(0), m_nb_heure(0), m_niveau_scolaire(0), m_nom("/0")
{

}

Matieres::Matieres(unsigned int id,
                   unsigned int nb_heure,
                   unsigned int niveau_scolaire,
                   std::string nom)
    : m_id(id), m_nb_heure(nb_heure),
    m_niveau_scolaire(niveau_scolaire), m_nom(nom)
{

}

Matieres::Matieres(const Matieres& matieres)
 : m_id(matieres.GetId()),
 m_nb_heure(matieres.GetNbHeure()),
 m_niveau_scolaire(matieres.GetNiveauScolaire()),
 m_nom(matieres.GetNom())
{

}

Matieres::~Matieres()
{

}

unsigned int Matieres::GetId() const
{
    return m_id;
}

unsigned int Matieres::GetNbHeure() const
{
    return m_nb_heure;
}

unsigned int Matieres::GetNiveauScolaire() const
{
    return m_niveau_scolaire;
}

std::string Matieres::GetNom() const
{
    return m_nom;
}
