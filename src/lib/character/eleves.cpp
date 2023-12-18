#include "eleves.h"

Eleve::Eleve()
        : m_id(/0),
          m_annee(/0),
          m_niveau_scolaire(/0),
          m_prenom("/0"),
          m_nom("/0"),
          m_matieres(),
          m_groupes()
{

}

Eleve::Eleve(unsigned int id,
             unsigned int annee,
             unsigned int niveau_scolaire,
             std::string prenom,
             std::string nom,
             TabDynIntUnsigned matieres,
             TabDynIntUnsigned groupes)
        : m_id(id),
          m_annee(annee),
          m_niveau_scolaire(niveau_scolaire),
          m_prenom(prenom),
          m_nom(nom),
          m_matieres(matieres),
          m_groupes(groupes)
{




}

Eleve::Eleve(const Eleve& eleve)
        : m_id(eleve.m_id),
          m_annee(eleve.m_annee),
          m_niveau_scolaire(eleve.m_niveau_scolaire),
          m_prenom(eleve.m_prenom),
          m_nom(eleve.m_nom),
          m_matieres(eleve.m_matieres),
          m_groupes(eleve.m_groupes)
{
    
}

Eleve::~Eleve()
{

}
}