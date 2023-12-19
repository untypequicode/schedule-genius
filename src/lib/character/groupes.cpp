#include "groupes.h"

Groupes::Groupes()
    : m_id(0),
      m_niveau_scolaire(0),
      m_nom("/0"),
      m_matiere(TabDynIntUnsigned()),
      m_salle(TabDynIntUnsigned()),
      m_prof(TabDynIntUnsigned())
{

}

Groupes::Groupes(unsigned int id,
                 unsigned int niveau_scolaire,
                 std::string nom,
                 TabDynIntUnsigned matiere,
                 TabDynIntUnsigned salle,
                 TabDynIntUnsigned prof)
    : m_id(id),
      m_nom(nom),
      m_matiere(matiere),
      m_salle(salle),
      m_prof(prof),
      m_niveau_scolaire(niveau_scolaire)
 {

 }

Groupes::Groupes(const Groupes &groupes)
    : m_id(groupes.GetId()),
      m_nom(groupes.GetNom()),
      m_matiere(groupes.GetMatiere()),
      m_salle(groupes.GetSalle()),
      m_prof(groupes.GetProf()),
      m_niveau_scolaire(groupes.GetNiveauScolaire())
{

}

Groupes::~Groupes()
{

}

unsigned int Groupes::GetId() const
{
    return m_id;
}

unsigned int Groupes::GetNiveauScolaire() const
{
    return m_niveau_scolaire;
}

std::string Groupes::GetNom() const
{
    return m_nom;
}

TabDynIntUnsigned Groupes::GetProf() const
{
    return m_prof;
}

TabDynIntUnsigned Groupes::GetMatiere() const
{
    return m_matiere;
}

TabDynIntUnsigned Groupes::GetSalle() const
{
    return m_salle;
}
