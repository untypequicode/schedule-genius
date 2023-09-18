#include "eleves.hpp"
#include <iostream>



Eleve::Eleve(int taille_tableau)
	: m_taille_tableau(taille_tableau),
	m_nom(""),
	m_prenom(""),
	m_niveau(""),
	m_matieres(new std::string[taille_tableau])
 {

}

Eleve::~Eleve()
{
	delete[] m_matieres;
}