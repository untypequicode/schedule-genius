#include "tab_dyn.hpp"


TabDyn::TabDyn()
	: m_nbElem(0),
	m_nbElemMax(0)
{

}

TabDyn::TabDyn(unsigned int nbElemMax)
	: m_nbElem(0),
	m_nbElemMax(nbElemMax)
{

}

TabDyn::~TabDyn()
{

}

unsigned int TabDyn::getNbElem() const
{
	return m_nbElem;
}

unsigned int TabDyn::getNbElemMax() const
{
	return m_nbElemMax;
}