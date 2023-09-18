#include "eleves.hpp"
#include <iostream>



Eleve::Eleve(std::string prenom, std::string nom, std::string niveau,int taille_tableau)
	: m_prenom(prenom),
	m_nom(nom),
	m_niveau(niveau),
	m_taille_tableau(taille_tableau),
	m_matieres(new std::string[taille_tableau])
 {

}

Eleve::~Eleve()
{
	delete[] m_matieres;
}