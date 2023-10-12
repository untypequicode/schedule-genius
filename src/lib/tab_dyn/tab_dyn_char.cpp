#include "tab_dyn.h"

TabDynChar::TabDynChar()
        : TabDyn()
{

}

TabDynChar::TabDynChar(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new char[nbElemMax])
{

}

TabDynChar::TabDynChar(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new char[nbElemMax])
{

}

TabDynChar::TabDynChar(const TabDynChar& tabDynChar)
        : TabDyn(tabDynChar),
          m_tab(new char[tabDynChar.m_nbElemMax])
{
    for (unsigned int i = 0; i < tabDynChar.m_nbElem; i++)
    {
        m_tab[i] = tabDynChar.m_tab[i];
    }
}

TabDynChar::~TabDynChar()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynChar::Append(char c)
{
    AddAppend(c, false);
}

void TabDynChar::Add(char c)
{
    AddAppend(c, true);
}

char TabDynChar::Get(unsigned int index) const
{
    if (index < m_nbElem)
    {
        return m_tab[index];
    }
    return '\0';
}

char* TabDynChar::GetTab() const
{
    return m_tab;
}

void TabDynChar::Set(unsigned int index, char c)
{
    if (index < m_nbElem)
    {
        m_tab[index] = c;
    }
}

char TabDynChar::Pop()
{
    return Pop(m_nbElem - 1);
}

char TabDynChar::Pop(int index)
{
    if (index < m_nbElem)
    {
        char c = m_tab[index];
        for (unsigned int i = index; i < m_nbElem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nbElem--;
        return c;
    }
    return '\0';
}

void TabDynChar::Remove(char elem, int num)
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

void TabDynChar::Remove(char elem)
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

void TabDynChar::Remove(char elem, bool first)
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

void TabDynChar::AddAppend(char c, bool addition)
{
    if (m_nbElemMax == 0)
    {
        if (addition)
        {
            m_tab = new char[m_addition];
            m_nbElemMax = m_addition;
        }
        else
        {
            m_tab = new char[1];
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
        char* new_tab;
        if (addition)
        {
            if (m_add_with_multiple)
            {
                new_tab = new char[m_nbElemMax * m_addition];
            }
            else
            {
                new_tab = new char[m_nbElemMax + m_addition];
            }
        }
        else
        {
            new_tab = new char[m_nbElemMax + 1];
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