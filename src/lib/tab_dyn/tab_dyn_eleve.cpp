#include "tab_dyn.hpp"

TabDynEleve::TabDynEleve()
	: TabDyn()
{

}

TabDynEleve::TabDynEleve(unsigned int nbElemMax)
	: TabDyn(nbElemMax),
	m_tab(new Eleve[nbElemMax])
{

}

TabDynEleve::TabDynEleve(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
	: TabDyn(nbElemMax, add_with_multiple, addition),
	m_tab(new Eleve[nbElemMax])
{

}

TabDynEleve::TabDynEleve(const TabDynEleve& tabDynEleve)
	: TabDyn(tabDynEleve),
	m_tab(new Eleve[tabDynEleve.m_nbElemMax])
{
	for (unsigned int i = 0; i < tabDynEleve.m_nbElem; i++)
	{
		m_tab[i] = tabDynEleve.m_tab[i];
	}
}

TabDynEleve::~TabDynEleve()
{
	if (m_tab != nullptr)
	{
		if (m_security)
		{
			delete[] m_tab;
		}
	}
}

void TabDynEleve::Append(Eleve i)
{
	AddAppend(i, false);
}

void TabDynEleve::Add(Eleve i)
{
	AddAppend(i, true);
}

Eleve TabDynEleve::Get(unsigned int index) const
{
	if (index < m_nbElem)
	{
		return m_tab[index];
	}
	else
	{
		return Eleve();
	}
}

Eleve* TabDynEleve::GetTab() const
{
	return m_tab;
}

void TabDynEleve::Set(unsigned int index, Eleve i)
{
	if (index < m_nbElem)
	{
		m_tab[index] = i;
	}
}

Eleve TabDynEleve::Pop()
{
	if (m_nbElem > 0)
	{
		Eleve elem = m_tab[m_nbElem - 1];
		m_nbElem--;
		return elem;
	}
	else
	{
		return Eleve();
	}
}

Eleve TabDynEleve::Pop(int index)
{
	if (index < m_nbElem)
	{
		Eleve elem = m_tab[index];
		for (unsigned int i = index; i < m_nbElem - 1; i++)
		{
			m_tab[i] = m_tab[i + 1];
		}
		m_nbElem--;
		return elem;
	}
	else
	{
		return Eleve();
	}
}

void TabDynEleve::Remove(Eleve elem, int num)
{
	int count = 0;
	for (unsigned int i = 0; i < m_nbElem; i++)
	{
		if (m_tab[i].getId() == elem.getId())
		{
			count++;
			if (count == num)
			{
				for (unsigned int j = i; j < m_nbElem - 1; j++)
				{
					m_tab[j] = m_tab[j + 1];
				}
				m_nbElem--;
				break;
			}
		}
	}
}

void TabDynEleve::Remove(Eleve elem)
{
	for (unsigned int i = 0; i < m_nbElem; i++)
	{
		if (m_tab[i].getId() == elem.getId())
		{
			for (unsigned int j = i; j < m_nbElem - 1; j++)
			{
				m_tab[j] = m_tab[j + 1];
			}
			m_nbElem--;
			i--;
		}
	}
}

void TabDynEleve::Remove(Eleve elem, bool first)
{
	if (first)
	{
		for (unsigned int i = 0; i < m_nbElem; i++)
		{
			if (m_tab[i].getId() == elem.getId())
			{
				for (unsigned int j = i; j < m_nbElem - 1; j++)
				{
					m_tab[j] = m_tab[j + 1];
				}
				m_nbElem--;
				break;
			}
		}
	}
	else
	{
		for (unsigned int i = m_nbElem - 1; i >= 0; i--)
		{
			if (m_tab[i].getId() == elem.getId())
			{
				for (unsigned int j = i; j < m_nbElem - 1; j++)
				{
					m_tab[j] = m_tab[j + 1];
				}
				m_nbElem--;
				break;
			}
		}
	}
}

void TabDynEleve::AddAppend(Eleve i, bool addition)
{
	if (m_nbElemMax == 0)
	{
		if (addition)
		{
			m_tab = new Eleve[m_addition];
			m_nbElemMax = m_addition;
		}
		else
		{
			m_tab = new Eleve[1];
			m_nbElemMax = 1;
		}
		m_tab[0] = i;
		m_nbElem = 1;
	}
	else if (m_nbElem < m_nbElemMax)
	{
		m_tab[m_nbElem] = i;
		m_nbElem++;
	}
	else if (m_nbElem == m_nbElemMax)
	{
		Eleve* new_tab;
		if (addition)
		{
			if (m_add_with_multiple)
			{
				new_tab = new Eleve[m_nbElemMax * m_addition];
			}
			else
			{
				new_tab = new Eleve[m_nbElemMax + m_addition];
			}
		}
		else
		{
			new_tab = new Eleve[m_nbElemMax +1];
		}
		for (unsigned int i = 0; i < m_nbElem; i++)
		{
			new_tab[i] = m_tab[i];
		}
		delete[] m_tab;
		new_tab[m_nbElem] = i;
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
		m_tab = new_tab;
	}
}