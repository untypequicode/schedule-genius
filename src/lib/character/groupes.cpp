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

Groupes::Groupes(const Groupes &groupes)
 : m_id(groupes.m_id),
   m_nom(groupes.m_nom),
   m_matiere(groupes.m_matiere),
   m_horaire(groupes.m_horaire),
   m_prof(groupes.m_prof),
   m_niveau_scolaire(groupes.m_niveau_scolaire)
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

void Groupes::SetId(unsigned int id)
{
    m_id = id;
}

void Groupes::SetNom(std::string nom)
{
    m_nom = nom;
}

void Groupes::SetMatiere(TabDynString matiere)
{
    m_matiere = matiere;
}

void Groupes::SetHoraire(TabDynInt horaire)
{
    m_horaire = horaire;
}

void Groupes::SetProf(Profs prof)
{
    m_prof = prof;
}

void Groupes::SetNiveauScolaire(unsigned int niveau_scolaire)
{
    m_niveau_scolaire = niveau_scolaire;
}
