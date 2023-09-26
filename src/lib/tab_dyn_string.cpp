#include "tab_dyn.hpp"

TabDynString::TabDynString()
	: TabDyn()
{

}

TabDynString::TabDynString(unsigned int nbElemMax)
	: TabDyn(nbElemMax), m_tab(new std::string[nbElemMax])
{

}

TabDynString::TabDynString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
	: TabDyn(nbElemMax,add_with_multiple, addition),
	m_tab(new std::string[nbElemMax])
{

}

TabDynString::TabDynString(const TabDynString& tabDynString)
	: TabDyn(tabDynString), m_tab(new std::string[tabDynString.m_nbElemMax])
{
	for (unsigned int i = 0; i < tabDynString.m_nbElem; i++)
	{
		m_tab[i] = tabDynString.m_tab[i];
	}
}

TabDynString::~TabDynString()
{
	delete[] m_tab;
}

void TabDynString::AddAppend(std::string str, bool addition)
{
	if (m_nbElemMax == 0)
	{
		if (addition)
		{
			m_tab = new std::string[m_addition];
			m_nbElemMax = m_addition;
		}
		else
		{
			m_tab = new std::string[1];
			m_nbElemMax = 1;
		}
		m_tab[0] = str;
		m_nbElem = 1;
	}
	else if (m_nbElem < m_nbElemMax)
	{
		m_tab[m_nbElem] = str;
		m_nbElem++;
	}
	else if (m_nbElem == m_nbElemMax)
	{
		std::string* new_tab;
		if (addition)
		{
			new_tab = new std::string[m_nbElemMax * 2];
		}
		else
		{
			new_tab = new std::string[m_nbElemMax + 1];
		}
		for (unsigned int i = 0; i < m_nbElem; i++)
			{
			new_tab[i] = m_tab[i];
			}
		new_tab[m_nbElem] = str;
		if (addition)
		{
			if (m_add_with_multiple)
			{
				m_nbElemMax *= m_addition;
			}
			else
			{
				m_nbElemMax += m_addition;
			}
		}
		else
		{
			m_nbElemMax++;
		}
		m_nbElem++;
		delete[] m_tab;
		m_tab = new_tab;
	}
}

void TabDynString::Append(std::string str)
{
	AddAppend(str, false);
}

void TabDynString::Add(std::string str)
{
	AddAppend(str, true);
}

std::string TabDynString::Get(unsigned int index) const
{
	if (index < m_nbElem)
	{
		return m_tab[index];
	}
	else
	{
		return "";
	}
}

std::string* TabDynString::GetTab() const
{
	return m_tab;
}

void TabDynString::Set(unsigned int index, std::string str)
{
	if (index < m_nbElem)
	{
		m_tab[index] = str;
	}
}