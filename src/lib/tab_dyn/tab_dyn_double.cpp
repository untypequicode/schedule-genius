#include "tab_dyn.h"

TabDynDouble::TabDynDouble()
        : TabDyn()
{

}

TabDynDouble::TabDynDouble(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new double[nb_elem_max])
{

}

TabDynDouble::TabDynDouble(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new double[nb_elem_max])
{

}

TabDynDouble::TabDynDouble(const TabDynDouble& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new double[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynDouble::~TabDynDouble()
{
    if (m_security and m_tab != nullptr and m_tab != NULL)
    {
        delete[] m_tab;
    }
}

void TabDynDouble::Copy(TabDynDouble& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynDouble::Add(double value)
{
    Add(value, true);
}

void TabDynDouble::Add(double value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new double[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new double[1];
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
        double* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new double[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new double[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new double[m_nb_elem_max + 1];
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

double TabDynDouble::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return '\0';
}

double* TabDynDouble::GetTab() const
{
    return m_tab;
}

void TabDynDouble::Set(unsigned int index, double value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
        m_nb_elem += 1;
    }
}

double TabDynDouble::Pop()
{
    return Pop(m_nb_elem - 1);
}

double TabDynDouble::Pop(int index)
{
    if (index < m_nb_elem)
    {
        double value = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return value;
    }
    return '\0';
}

void TabDynDouble::Remove(double value, int num)
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

void TabDynDouble::Remove(double value)
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

void TabDynDouble::Remove(double value, bool first)
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