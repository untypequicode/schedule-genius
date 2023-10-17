#include "matieres_temp.h"

Matieres_temp::Matieres_temp()
 : Matieres_temp("/0", 0)
{

}

Matieres_temp::Matieres_temp(std::string nom, unsigned int id)
 : m_nom(nom), m_id(id)
{

}

Matieres_temp::Matieres_temp(const Matieres_temp& matieres_temp)
 : m_nom(matieres_temp.m_nom), m_id(matieres_temp.m_id)
{

}

Matieres_temp::~Matieres_temp()
{

}