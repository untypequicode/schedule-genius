#include "tab_dyn.h"

TabDynInt::TabDynInt()
        : TabDyn()
{

}

TabDynInt::TabDynInt(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new int[nbElemMax])
{

}

TabDynInt::TabDynInt(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new int[nbElemMax])
{

}

TabDynInt::TabDynInt(const TabDynInt& tabDynInt)
        : TabDyn(tabDynInt),
          m_tab(new int[tabDynInt.m_nbElemMax])
{
    for (unsigned int i = 0; i < tabDynInt.m_nbElem; i++)
    {
        m_tab[i] = tabDynInt.m_tab[i];
    }
}

TabDynInt::~TabDynInt()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynInt::Copy(TabDynInt tab_ref)
{
    for (unsigned int i = 0; i < tab_ref.GetNbElem(); i++)
    {
        Append(tab_ref.Get(i));
    }
}

void TabDynInt::Append(int c)
{
    AddAppend(c, false);
}

void TabDynInt::Add(int c)
{
    AddAppend(c, true);
}

int TabDynInt::Get(unsigned int index) const
{
    if (index < m_nbElem)
    {
        return m_tab[index];
    }
    return '\0';
}

int* TabDynInt::GetTab() const
{
    return m_tab;
}

void TabDynInt::Set(unsigned int index, int c)
{
    if (index < m_nbElem)
    {
        m_tab[index] = c;
    }
}

int TabDynInt::Pop()
{
    return Pop(m_nbElem - 1);
}

int TabDynInt::Pop(int index)
{
    if (index < m_nbElem)
    {
        int c = m_tab[index];
        for (unsigned int i = index; i < m_nbElem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nbElem--;
        return c;
    }
    return '\0';
}

void TabDynInt::Remove(int elem, int num)
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

void TabDynInt::Remove(int elem)
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

void TabDynInt::Remove(int elem, bool first)
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

void TabDynInt::AddAppend(int c, bool addition)
{
    if (m_nbElemMax == 0)
    {
        if (addition)
        {
            m_tab = new int[m_addition];
            m_nbElemMax = m_addition;
        }
        else
        {
            m_tab = new int[1];
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
        int* new_tab;
        if (addition)
        {
            if (m_add_with_multiple)
            {
                new_tab = new int[m_nbElemMax * m_addition];
            }
            else
            {
                new_tab = new int[m_nbElemMax + m_addition];
            }
        }
        else
        {
            new_tab = new int[m_nbElemMax + 1];
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