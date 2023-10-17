#include "tab_dyn.h"

TabDynString::TabDynString()
        : TabDyn()
{

}

TabDynString::TabDynString(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new std::string[nbElemMax])
{

}

TabDynString::TabDynString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new std::string[nbElemMax])
{

}

TabDynString::TabDynString(const TabDynString& tabDynString)
        : TabDyn(tabDynString),
          m_tab(new std::string[tabDynString.m_nbElemMax])
{
    for (unsigned int i = 0; i < tabDynString.m_nbElem; i++)
    {
        m_tab[i] = tabDynString.m_tab[i];
    }
}

TabDynString::~TabDynString()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynString::Copy(TabDynString tab_ref)
{
    for (unsigned int i = 0; i < tab_ref.GetNbElem(); i++)
    {
        Append(tab_ref.Get(i));
    }
}

void TabDynString::Append(std::string c)
{
    AddAppend(c, false);
}

void TabDynString::Add(std::string c)
{
    AddAppend(c, true);
}

std::string TabDynString::Get(unsigned int index) const
{
    if (index < m_nbElem)
    {
        return m_tab[index];
    }
    return "\0";
}

std::string* TabDynString::GetTab() const
{
    return m_tab;
}

void TabDynString::Set(unsigned int index, std::string c)
{
    if (index < m_nbElem)
    {
        m_tab[index] = c;
    }
}

std::string TabDynString::Pop()
{
    return Pop(m_nbElem - 1);
}

std::string TabDynString::Pop(int index)
{
    if (index < m_nbElem)
    {
        std::string c = m_tab[index];
        for (unsigned int i = index; i < m_nbElem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nbElem--;
        return c;
    }
    return "\0";
}

void TabDynString::Remove(std::string elem, int num)
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

void TabDynString::Remove(std::string elem)
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

void TabDynString::Remove(std::string elem, bool first)
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

void TabDynString::AddAppend(std::string c, bool addition)
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
        std::string* new_tab;
        if (addition)
        {
            if (m_add_with_multiple)
            {
                new_tab = new std::string[m_nbElemMax * m_addition];
            }
            else
            {
                new_tab = new std::string[m_nbElemMax + m_addition];
            }
        }
        else
        {
            new_tab = new std::string[m_nbElemMax + 1];
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