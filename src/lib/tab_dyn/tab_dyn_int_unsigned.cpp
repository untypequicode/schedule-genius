#include "tab_dyn.h"

TabDynIntUnsigned::TabDynIntUnsigned()
        : TabDyn()
{

}

TabDynIntUnsigned::TabDynIntUnsigned(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new int unsigned[nb_elem_max])
{

}

TabDynIntUnsigned::TabDynIntUnsigned(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new int unsigned[nb_elem_max])
{

}

TabDynIntUnsigned::TabDynIntUnsigned(const TabDynIntUnsigned& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new int unsigned[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynIntUnsigned::~TabDynIntUnsigned()
{
    if (m_security and m_tab != nullptr)
    {
        delete[] m_tab;
    }
}

void TabDynIntUnsigned::Copy(TabDynIntUnsigned& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynIntUnsigned::Add(int unsigned value)
{
    Add(value, true);
}

void TabDynIntUnsigned::Add(int unsigned value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new int unsigned[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new int unsigned[1];
            m_nb_elem_max = 1;
        }
        m_tab[0] = value;
        m_nb_elem = 1;
        return;
    }
    else if (m_nb_elem < m_nb_elem_max)
    {
        m_tab[m_nb_elem] = value;
        m_nb_elem++;
        return;
    }
    else if (m_nb_elem == m_nb_elem_max)
    {
        int unsigned* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new int unsigned[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new int unsigned[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new int unsigned[m_nb_elem_max + 1];
        }
        for (unsigned int i = 0; i < m_nb_elem; i++)
        {
            new_tab[i] = m_tab[i];
        }
        delete[] m_tab;
        new_tab[m_nb_elem] = value;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                m_nb_elem_max *= m_number_addition;
            }
            else
            {
                m_nb_elem_max += m_number_addition;
            }
        }
        else
        {
            m_nb_elem_max++;
        }
        m_nb_elem++;
        m_tab = new_tab;
        return;
    }
}

int unsigned TabDynIntUnsigned::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return '\0';
}

int unsigned* TabDynIntUnsigned::GetTab() const
{
    return m_tab;
}

void TabDynIntUnsigned::Set(unsigned int index, int unsigned value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
    }
}

int unsigned TabDynIntUnsigned::Pop()
{
    return Pop(m_nb_elem - 1);
}

int unsigned TabDynIntUnsigned::Pop(int index)
{
    if (index < m_nb_elem)
    {
        int unsigned c = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return c;
    }
    return '\0';
}

void TabDynIntUnsigned::Remove(int unsigned value, int num)
{
    int count = 0;
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_tab[i] == value)
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

void TabDynIntUnsigned::Remove(int unsigned value)
{
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_tab[i] == value)
        {
            Pop(i);
            i--;
        }
    }
}

void TabDynIntUnsigned::Remove(int unsigned value, bool first)
{
    if (first)
    {
        for (unsigned int i = 0; i < m_nb_elem; i++)
        {
            if (m_tab[i] == value)
            {
                Pop(i);
                return;
            }
        }
    }
    else
    {
        for (unsigned int i = m_nb_elem - 1; i >= 0; i--)
        {
            if (m_tab[i] == value)
            {
                Pop(i);
                break;
            }
        }
    }
}