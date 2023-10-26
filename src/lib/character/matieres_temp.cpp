#include "matieres_temp.h"

MatieresTemp::MatieresTemp()
 : MatieresTemp("/0", 0)
{

}

MatieresTemp::MatieresTemp(std::string nom, unsigned int id)
 : m_nom(nom), m_id(id)
{

}

MatieresTemp::MatieresTemp(const MatieresTemp& matieres_temp)
 : m_nom(matieres_temp.m_nom), m_id(matieres_temp.m_id)
{

}

MatieresTemp::~MatieresTemp()
{

}