#include "tab_dyn.h"

TabDynIntUnsigned::TabDynIntUnsigned()
        : TabDyn()
{

}

TabDynIntUnsigned::TabDynIntUnsigned(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new int unsigned[nbElemMax])
{

}

TabDynIntUnsigned::TabDynIntUnsigned(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new int unsigned[nbElemMax])
{

}

TabDynIntUnsigned::TabDynIntUnsigned(const TabDynIntUnsigned& tabDynIntUnsigned)
        : TabDyn(tabDynIntUnsigned),
          m_tab(new int unsigned[tabDynIntUnsigned.m_nbElemMax])
{
    for (unsigned int i = 0; i < tabDynIntUnsigned.m_nbElem; i++)
    {
        m_tab[i] = tabDynIntUnsigned.m_tab[i];
    }
}

TabDynIntUnsigned::~TabDynIntUnsigned()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynIntUnsigned::Copy(TabDynIntUnsigned tab_ref)
{
    for (unsigned int i = 0; i < tab_ref.GetNbElem(); i++)
    {
        Append(tab_ref.Get(i));
    }
}

void TabDynIntUnsigned::Append(int unsigned c)
{
    AddAppend(c, false);
}

void TabDynIntUnsigned::Add(int unsigned c)
{
    AddAppend(c, true);
}

int unsigned TabDynIntUnsigned::Get(unsigned int index) const
{
    if (index < m_nbElem)
    {
        return m_tab[index];
    }
    return '\0';
}

int unsigned* TabDynIntUnsigned::GetTab() const
{
    return m_tab;
}

void TabDynIntUnsigned::Set(unsigned int index, int unsigned c)
{
    if (index < m_nbElem)
    {
        m_tab[index] = c;
    }
}

int unsigned TabDynIntUnsigned::Pop()
{
    return Pop(m_nbElem - 1);
}

int unsigned TabDynIntUnsigned::Pop(int index)
{
    if (index < m_nbElem)
    {
        int unsigned c = m_tab[index];
        for (unsigned int i = index; i < m_nbElem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nbElem--;
        return c;
    }
    return '\0';
}

void TabDynIntUnsigned::Remove(int unsigned elem, int num)
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

void TabDynIntUnsigned::Remove(int unsigned elem)
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

void TabDynIntUnsigned::Remove(int unsigned elem, bool first)
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

void TabDynIntUnsigned::AddAppend(int unsigned c, bool addition)
{
    if (m_nbElemMax == 0)
    {
        if (addition)
        {
            m_tab = new int unsigned[m_addition];
            m_nbElemMax = m_addition;
        }
        else
        {
            m_tab = new int unsigned[1];
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
        int unsigned* new_tab;
        if (addition)
        {
            if (m_add_with_multiple)
            {
                new_tab = new int unsigned[m_nbElemMax * m_addition];
            }
            else
            {
                new_tab = new int unsigned[m_nbElemMax + m_addition];
            }
        }
        else
        {
            new_tab = new int unsigned[m_nbElemMax + 1];
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