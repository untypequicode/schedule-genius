#include "tab_dyn.h"

TabDynFloat::TabDynFloat()
        : TabDyn()
{

}

TabDynFloat::TabDynFloat(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new float[nb_elem_max])
{

}

TabDynFloat::TabDynFloat(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new float[nb_elem_max])
{

}

TabDynFloat::TabDynFloat(const TabDynFloat& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new float[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynFloat::~TabDynFloat()
{
    if (m_security and m_tab != nullptr)
    {
        delete[] m_tab;
    }
}

void TabDynFloat::Copy(TabDynFloat& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynFloat::Add(float value)
{
    Add(value, true);
}

void TabDynFloat::Add(float value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new float[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new float[1];
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
        float* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new float[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new float[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new float[m_nb_elem_max + 1];
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

float TabDynFloat::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return '\0';
}

float* TabDynFloat::GetTab() const
{
    return m_tab;
}

void TabDynFloat::Set(unsigned int index, float value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
    }
}

float TabDynFloat::Pop()
{
    return Pop(m_nb_elem - 1);
}

float TabDynFloat::Pop(int index)
{
    if (index < m_nb_elem)
    {
        float value = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return value;
    }
    return '\0';
}

void TabDynFloat::Remove(float value, int num)
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

void TabDynFloat::Remove(float value)
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

void TabDynFloat::Remove(float value, bool first)
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