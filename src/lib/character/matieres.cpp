#include "matieres.h"

Matieres::Matieres()
 : Matieres("/0", 0, 0)
{

}

Matieres::Matieres(unsigned int id,
                   unsigned int nb_heure,
                   unsigned int niveau_scolaire,
                   std::string nom)
 : m_id(id), m_nb_heure(nb_heure), m_niveau_scolaire(niveau_scolaire), m_nom(nom)
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
