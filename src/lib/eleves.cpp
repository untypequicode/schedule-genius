#include "eleves.hpp"

Eleve::Eleve()
	: m_id(0),
	m_prenom("inconnu"),
	m_nom("inconnu"),
	m_niveau_scolaire("inconnu"),
	m_nb_matiere(0),
	m_nb_matiere_max(0)
{

}

Eleve::Eleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire)
	: m_id(id),
	m_prenom(prenom),
	m_nom(nom),
	m_niveau_scolaire(niveau_scolaire),
	m_nb_matiere(0),
	m_nb_matiere_max(0)

{

}

Eleve::Eleve(const Eleve& eleve)
	: m_id(eleve.getId()),
	m_prenom(eleve.getPrenom()),
	m_nom(eleve.getNom()),
	m_niveau_scolaire(eleve.getNiveauScolaire()),
	m_nb_matiere(0),
	m_nb_matiere_max(0)
{

}

Eleve::~Eleve()
{
	delete[] m_matieres;
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
	return m_nb_matiere;
}

unsigned int Eleve::getNbMatiereMax() const
{
	return m_nb_matiere_max;
}

std::string* Eleve::getMatieres() const
{
	return m_matieres;
}

void Eleve::addMatiere(std::string matiere)
{
	if (m_nb_matiere_max == 0)
	{
		m_matieres = new std::string[2];
		m_nb_matiere_max = 2;
		m_matieres[0] = matiere;
		m_nb_matiere++;
	}
	else if (m_nb_matiere < m_nb_matiere_max) {
		m_matieres[m_nb_matiere] = matiere;
		m_nb_matiere++;
	}
	else if (m_nb_matiere == m_nb_matiere_max) {
		
		std::string* matieres = new std::string[m_nb_matiere_max * 2];
		for (unsigned int i = 0; i < m_nb_matiere; i++) {
			matieres[i] = m_matieres[i];
		}
		matieres[m_nb_matiere] = matiere;
		m_nb_matiere++;
		m_nb_matiere_max *= 2;
		delete[] m_matieres;
		m_matieres = matieres;
		std::cout << "Nombre maximum de matiere atteint" << std::endl;
	}
	std::cout << "Nombre de matiere : " << m_nb_matiere << " - Nombre de matiere max : " << m_nb_matiere_max << std::endl;
}

//std::string Eleve::getMatiere(unsigned int id) const
//{
//	return m_matieres[id];
//}