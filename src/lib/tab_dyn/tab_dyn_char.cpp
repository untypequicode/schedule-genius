#include "tab_dyn.h"

TabDynChar::TabDynChar()
        : TabDyn()
{

}

TabDynChar::TabDynChar(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new char[nb_elem_max])
{

}

TabDynChar::TabDynChar(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new char[nb_elem_max])
{

}

TabDynChar::TabDynChar(const TabDynChar& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new char[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynChar::~TabDynChar()
{
    if (m_security and m_tab != nullptr)
    {
        delete[] m_tab;
    }
}

void TabDynChar::Copy(TabDynChar& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynChar::Add(char value)
{
    Add(value, true);
}

void TabDynChar::Add(char value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new char[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new char[1];
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
        char* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new char[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new char[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new char[m_nb_elem_max + 1];
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

char TabDynChar::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return '\0';
}

char* TabDynChar::GetTab() const
{
    return m_tab;
}

void TabDynChar::Set(unsigned int index, char value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
    }
}

char TabDynChar::Pop()
{
    return Pop(m_nb_elem - 1);
}

char TabDynChar::Pop(int index)
{
    if (index < m_nb_elem)
    {
        char value = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return value;
    }
    return '\0';
}

void TabDynChar::Remove(char value, int num)
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

void TabDynChar::Remove(char value)
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

void TabDynChar::Remove(char value, bool first)
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