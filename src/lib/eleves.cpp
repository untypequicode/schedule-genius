#include "eleves.hpp"

Eleve::Eleve()
	: m_id(0),
	m_prenom("inconnu"),
	m_nom("inconnu"),
	m_niveau_scolaire("inconnu")
{

}

Eleve::Eleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire)
	: m_id(id),
	m_prenom(prenom),
	m_nom(nom),
	m_niveau_scolaire(niveau_scolaire)
{

}

Eleve::Eleve(const Eleve& eleve)
	: m_id(eleve.getId()),
	m_prenom(eleve.getPrenom()),
	m_nom(eleve.getNom()),
	m_niveau_scolaire(eleve.getNiveauScolaire())
{

}

Eleve::~Eleve()
{
	
}

unsigned int Eleve::getId() const
{
	return m_id;
}

std::string Eleve::getPrenom() const
{
	return m_prenom;
}

std::string Eleve::getNom() const
{
	return m_nom;
}

std::string Eleve::getNiveauScolaire() const
{
	return m_niveau_scolaire;
}

unsigned int Eleve::getNbMatiere() const
{
	return m_matieres.GetNbElem();
}

unsigned int Eleve::getNbMatiereMax() const
{
	return m_matieres.GetNbElemMax();
}

std::string* Eleve::getMatieres() const
{
	return m_matieres.GetTab();
}

void Eleve::addMatiere(std::string matiere)
{
	m_matieres.Append(matiere);
	std::cout << "Nombre de matiere : " << m_matieres.GetNbElem() << " - Nombre de matiere max : " << m_matieres.GetNbElemMax() << std::endl;
}

std::string Eleve::getMatiere(unsigned int id) const
{
	return m_matieres.Get(id);
}