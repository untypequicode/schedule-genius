#include "eleves.h"

Eleve::Eleve()
        : m_id(0),
          m_annee(0),
          m_niveau_scolaire(0),
          m_prenom("/0"),
          m_nom("/0"),
          m_matieres(TabDynIntUnsigned()),
          m_groupes(TabDynIntUnsigned())
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

Eleve::~Eleve()
{

}

unsigned int Eleve::GetId() const
{
    return m_id;
}

unsigned int Eleve::GetAnnee() const
{
    return m_annee;
}

unsigned int Eleve::GetNiveauScolaire() const
{
    return m_niveau_scolaire;
}

std::string Eleve::GetPrenom() const
{
    return m_prenom;
}

std::string Eleve::GetNom() const
{
    return m_nom;
}

TabDynIntUnsigned Eleve::GetMatieres() const
{
    return m_matieres;
}

TabDynIntUnsigned Eleve::GetGroupes() const
{
    return m_groupes;
}