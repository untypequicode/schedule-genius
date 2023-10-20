#include "eleves.h"

Eleve::Eleve()
        : m_id('\0'),
          m_prenom("\0"),
          m_nom("\0"),
          m_niveau_scolaire("\0"),
          m_matieres()
{

}

Eleve::Eleve(unsigned int id,
             std::string prenom,
             std::string nom,
             std::string niveau_scolaire)
        : m_id(id),
          m_prenom(prenom),
          m_nom(nom),
          m_niveau_scolaire(niveau_scolaire),
          m_matieres()
{

}

Eleve::Eleve(const Eleve& eleve)
        : m_id(eleve.GetId()),
          m_prenom(eleve.GetPrenom()),
          m_nom(eleve.GetNom()),
          m_niveau_scolaire(eleve.GetNiveauScolaire()),
          m_matieres(eleve.m_matieres)
{
    
}

Eleve::~Eleve()
{

}

unsigned int Eleve::GetId() const
{
    return m_id;
}

std::string Eleve::GetPrenom() const
{
    return m_prenom;
}

std::string Eleve::GetNom() const
{
    return m_nom;
}

std::string Eleve::GetNiveauScolaire() const
{
    return m_niveau_scolaire;
}

unsigned int Eleve::GetNbMatiere() const
{
    return m_matieres.GetNbElem();
}

unsigned int Eleve::GetNbMatiereMax() const
{
    return m_matieres.GetNbElemMax();
}

std::string* Eleve::GetMatieres() const
{
    return m_matieres.GetTab();
}

std::string Eleve::GetMatiere(unsigned int id) const
{
    return m_matieres.Get(id);
}

void Eleve::SetEleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire)
{
    m_id = id;
    m_prenom = prenom;
    m_nom = nom;
    m_niveau_scolaire = niveau_scolaire;
}

void Eleve::SetId(unsigned int id)
{
    m_id = id;
}

void Eleve::SetPrenom(std::string prenom)
{
    m_prenom = prenom;
}

void Eleve::SetNom(std::string nom)
{
    m_nom = nom;
}

void Eleve::SetNiveauScolaire(std::string niveau_scolaire)
{
    m_niveau_scolaire = niveau_scolaire;
}

void Eleve::CopyMatiere(TabDynString tab_ref)
{
    m_matieres.Copy(tab_ref);
}

void Eleve::SetSecurity(bool security)
{
    m_matieres.SetSecurity(security);
}

void Eleve::SetMatiere(unsigned int id, std::string matiere)
{
    m_matieres.Set(id, matiere);
}

void Eleve::AddMatiere(std::string matiere)
{
    m_matieres.Add(matiere, false);
}

void Eleve::AddMatiere(std::string value, bool add_with_addition)
{
    m_matieres.Add(value, add_with_addition);
}

std::string Eleve::PopMatiere()
{
    return m_matieres.Pop();
}

std::string Eleve::PopMatiere(int index)
{
    return m_matieres.Pop(index);
}

void Eleve::RemoveMatiere(std::string matiere, int num)
{
    m_matieres.Remove(matiere, num);
}

void Eleve::RemoveMatiere(std::string matiere)
{
    m_matieres.Remove(matiere);
}

void Eleve::RemoveMatiere(std::string matiere, bool first)
{
    m_matieres.Remove(matiere, first);
}