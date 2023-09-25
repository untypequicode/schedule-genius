#include "eleves.hpp"


Eleve::Eleve() 
	: m_prenom(""),
	m_nom(""),
	m_niveau(""),
	m_quantite_matiere(0),
	m_matieres(new std::string[0])
{

}

Eleve::Eleve(std::string prenom, std::string nom, std::string niveau,int quantite_matiere)
	: m_prenom(prenom),
	m_nom(nom),
	m_niveau(niveau),
	m_quantite_matiere(quantite_matiere),
	m_matieres(new std::string[quantite_matiere])
 {

}

Eleve::Eleve(Eleve& const eleve)
	: m_prenom(eleve.m_prenom),
	m_nom(eleve.m_nom),
	m_niveau(eleve.m_niveau),
	m_quantite_matiere(eleve.m_quantite_matiere),
	m_matieres(new std::string[eleve.m_quantite_matiere])
{
	for (int i = 0; i < eleve.m_quantite_matiere; i++) {
		m_matieres[i] = eleve.GetMatiere(i);
	}
}

void Eleve::SetMatiere(std::string matiere, int index) {
	if (0 <= index < m_quantite_matiere) {
		m_matieres[index] = matiere;
	}
}

std::string Eleve::GetMatiere(int index) {
	if (0 <= index < m_quantite_matiere) {
		return m_matieres[index];
	}
	return "";
}

Eleve::~Eleve()
{
	delete[] m_matieres;
}