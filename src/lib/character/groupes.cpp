#include "groupes.h"

Groupes::Groupes()
 : m_id(0),
   m_nom(""),
   m_matiere(),
   m_horaire(),
   m_prof(),
   m_niveau_scolaire(0)
{

}

Groupes::Groupes(unsigned int id,
                 std::string nom,
                 TabDynString matiere,
                 TabDynInt horaire,
                 Profs prof,
                 unsigned int niveau_scolaire)
 : m_id(id),
   m_nom(nom),
   m_matiere(matiere),
   m_horaire(horaire),
   m_prof(prof),
   m_niveau_scolaire(niveau_scolaire)
{

}

Groupes::~Groupes()
{

}

unsigned int Groupes::GetId()
{
    return m_id;
}

std::string Groupes::GetNom()
{
    return m_nom;
}

TabDynString Groupes::GetMatiere()
{
    return m_matiere;
}

TabDynInt Groupes::GetHoraire()
{
    return m_horaire;
}

Profs Groupes::GetProf()
{
    return m_prof;
}

unsigned int Groupes::GetNiveauScolaire()
{
    return m_niveau_scolaire;
}
