#include "groupes.hpp"

Groupe::Groupe(std::string niveau, std::string matiere)
	: m_niveau(niveau),
	m_matiere(matiere),
	m_nombre_eleves(0)
{
	m_eleves = new Eleve[500];
}

void Groupe::AddEleve(Eleve& eleve) {
	if (m_nombre_eleves >= 500) {
		std::cout << "Maximum atteint" << std::endl;
	}
	else {
		m_eleves[m_nombre_eleves] = eleve;
		m_nombre_eleves++;
	}
}

Eleve Groupe::GetEleve(int index) {
	if (0 <= index < m_nombre_eleves) {
		return m_eleves[index];
	}
}

Groupe::~Groupe()
{
	delete[] m_eleves;
}