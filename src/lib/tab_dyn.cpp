#include "tab_dyn.hpp"


TabDyn::TabDyn()
	: m_nbElem(0),
	m_nbElemMax(0),
	m_add_with_multiple(true),
	m_addition(2)
{

}

TabDyn::TabDyn(unsigned int nbElemMax)
	: m_nbElem(0),
	m_nbElemMax(nbElemMax),
	m_add_with_multiple(true),
	m_addition(2)
{

}

TabDyn::TabDyn(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
	: m_nbElem(0),
	m_nbElemMax(nbElemMax),
	m_add_with_multiple(add_with_multiple),
	m_addition(addition)
{
	if (m_addition < 2)
		m_addition = 2;
}

TabDyn::TabDyn(const TabDyn& tabDyn)
	: m_nbElem(tabDyn.m_nbElem),
	m_nbElemMax(tabDyn.m_nbElemMax),
	m_add_with_multiple(tabDyn.m_add_with_multiple),
	m_addition(tabDyn.m_addition)
{

}

TabDyn::~TabDyn()
{

}

unsigned int TabDyn::GetNbElem() const
{
	return m_nbElem;
}

unsigned int TabDyn::GetNbElemMax() const
{
	return m_nbElemMax;
}

void TabDyn::SetParam(bool add_with_multiple, unsigned int addition)
{
	m_add_with_multiple = add_with_multiple;
	if (addition < 2)
	{
		m_addition = 2;
	}
	else
	{
		m_addition = addition;
	}
}