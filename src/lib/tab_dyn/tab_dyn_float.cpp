#include "tab_dyn.h"

TabDynFloat::TabDynFloat()
        : TabDyn()
{

}

TabDynFloat::TabDynFloat(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new float[nbElemMax])
{

}

TabDynFloat::TabDynFloat(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new float[nbElemMax])
{

}

TabDynFloat::TabDynFloat(const TabDynFloat& tabDynFloat)
        : TabDyn(tabDynFloat),
          m_tab(new float[tabDynFloat.m_nbElemMax])
{
    for (unsigned int i = 0; i < tabDynFloat.m_nbElem; i++)
    {
        m_tab[i] = tabDynFloat.m_tab[i];
    }
}

TabDynFloat::~TabDynFloat()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynFloat::Copy(TabDynFloat tab_ref)
{
    for (unsigned int i = 0; i < tab_ref.GetNbElem(); i++)
    {
        Append(tab_ref.Get(i));
    }
}

void TabDynFloat::Append(float c)
{
    AddAppend(c, false);
}

void TabDynFloat::Add(float c)
{
    AddAppend(c, true);
}

float TabDynFloat::Get(unsigned int index) const
{
    if (index < m_nbElem)
    {
        return m_tab[index];
    }
    return '\0';
}

float* TabDynFloat::GetTab() const
{
    return m_tab;
}

void TabDynFloat::Set(unsigned int index, float c)
{
    if (index < m_nbElem)
    {
        m_tab[index] = c;
    }
}

float TabDynFloat::Pop()
{
    return Pop(m_nbElem - 1);
}

float TabDynFloat::Pop(int index)
{
    if (index < m_nbElem)
    {
        float c = m_tab[index];
        for (unsigned int i = index; i < m_nbElem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nbElem--;
        return c;
    }
    return '\0';
}

void TabDynFloat::Remove(float elem, int num)
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

void TabDynFloat::Remove(float elem)
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

void TabDynFloat::Remove(float elem, bool first)
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

void TabDynFloat::AddAppend(float c, bool addition)
{
    if (m_nbElemMax == 0)
    {
        if (addition)
        {
            m_tab = new float[m_addition];
            m_nbElemMax = m_addition;
        }
        else
        {
            m_tab = new float[1];
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
        float* new_tab;
        if (addition)
        {
            if (m_add_with_multiple)
            {
                new_tab = new float[m_nbElemMax * m_addition];
            }
            else
            {
                new_tab = new float[m_nbElemMax + m_addition];
            }
        }
        else
        {
            new_tab = new float[m_nbElemMax + 1];
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