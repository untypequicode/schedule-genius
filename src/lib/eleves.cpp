#include "eleves.hpp"
#include <iostream>



Eleve::Eleve(std::string prenom, std::string nom, std::string niveau,int quantite_matiere)
	: m_prenom(prenom),
	m_nom(nom),
	m_niveau(niveau),
	m_quantite_matiere(quantite_matiere),
	m_matieres(new std::string[quantite_matiere])
 {

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