#include "tab_dyn.h"

TabDynDouble::TabDynDouble()
        : TabDyn()
{

}

TabDynDouble::TabDynDouble(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new double[nbElemMax])
{

}

TabDynDouble::TabDynDouble(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new double[nbElemMax])
{

}

TabDynDouble::TabDynDouble(const TabDynDouble& tabDynDouble)
        : TabDyn(tabDynDouble),
          m_tab(new double[tabDynDouble.m_nbElemMax])
{
    for (unsigned int i = 0; i < tabDynDouble.m_nbElem; i++)
    {
        m_tab[i] = tabDynDouble.m_tab[i];
    }
}

TabDynDouble::~TabDynDouble()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynDouble::Copy(TabDynDouble tab_ref)
{
    for (unsigned int i = 0; i < tab_ref.GetNbElem(); i++)
    {
        Append(tab_ref.Get(i));
    }
}

void TabDynDouble::Append(double c)
{
    AddAppend(c, false);
}

void TabDynDouble::Add(double c)
{
    AddAppend(c, true);
}

double TabDynDouble::Get(unsigned int index) const
{
    if (index < m_nbElem)
    {
        return m_tab[index];
    }
    return '\0';
}

double* TabDynDouble::GetTab() const
{
    return m_tab;
}

void TabDynDouble::Set(unsigned int index, double c)
{
    if (index < m_nbElem)
    {
        m_tab[index] = c;
    }
}

double TabDynDouble::Pop()
{
    return Pop(m_nbElem - 1);
}

double TabDynDouble::Pop(int index)
{
    if (index < m_nbElem)
    {
        double c = m_tab[index];
        for (unsigned int i = index; i < m_nbElem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nbElem--;
        return c;
    }
    return '\0';
}

void TabDynDouble::Remove(double elem, int num)
{
    int count = 0;
    for (unsigned int i = 0; i < m_nbElem; i++)
    {
        if (m_tab[i] == elem)
        {
            count++;
            if (count == num)
            {
                Pop(i);
                return;
            }
        }
    }
}

void TabDynDouble::Remove(double elem)
{
    for (unsigned int i = 0; i < m_nbElem; i++)
    {
        if (m_tab[i] == elem)
        {
            Pop(i);
            i--;
        }
    }
}

void TabDynDouble::Remove(double elem, bool first)
{
    if (first)
    {
        for (unsigned int i = 0; i < m_nbElem; i++)
        {
            if (m_tab[i] == elem)
            {
                Pop(i);
                return;
            }
        }
    }
    else
    {
        for (unsigned int i = m_nbElem - 1; i >= 0; i--)
        {
            if (m_tab[i] == elem)
            {
                Pop(i);
                break;
            }
        }
    }
}

void TabDynDouble::AddAppend(double c, bool addition)
{
    if (m_nbElemMax == 0)
    {
        if (addition)
        {
            m_tab = new double[m_addition];
            m_nbElemMax = m_addition;
        }
        else
        {
            m_tab = new double[1];
            m_nbElemMax = 1;
        }
        m_tab[0] = c;
        m_nbElem = 1;
    }
    else if (m_nbElem < m_nbElemMax)
    {
        m_tab[m_nbElem] = c;
        m_nbElem++;
    }
    else if (m_nbElem == m_nbElemMax)
    {
        double* new_tab;
        if (addition)
        {
            if (m_add_with_multiple)
            {
                new_tab = new double[m_nbElemMax * m_addition];
            }
            else
            {
                new_tab = new double[m_nbElemMax + m_addition];
            }
        }
        else
        {
            new_tab = new double[m_nbElemMax + 1];
        }
        for (unsigned int i = 0; i < m_nbElem; i++)
        {
            new_tab[i] = m_tab[i];
        }
        delete[] m_tab;
        new_tab[m_nbElem] = c;
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
    }
}