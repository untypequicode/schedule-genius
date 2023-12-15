#include "../character/matieres_temp.h"

TabDynMatieresTemp::TabDynMatieresTemp()
        : TabDyn()
{

}

TabDynMatieresTemp::TabDynMatieresTemp(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new MatieresTemp[nb_elem_max])
{

}

TabDynMatieresTemp::TabDynMatieresTemp(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new MatieresTemp[nb_elem_max])
{

}

TabDynMatieresTemp::TabDynMatieresTemp(const TabDynMatieresTemp& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new MatieresTemp[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynMatieresTemp::~TabDynMatieresTemp()
{
    if (m_security and m_tab != nullptr and m_tab != NULL)
    {
        delete[] m_tab;
    }
}

void TabDynMatieresTemp::Copy(TabDynMatieresTemp& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynMatieresTemp::Add(MatieresTemp value)
{
    Add(value, true);
}

void TabDynMatieresTemp::Add(MatieresTemp value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new MatieresTemp[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new MatieresTemp[1];
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
        MatieresTemp* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new MatieresTemp[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new MatieresTemp[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new MatieresTemp[m_nb_elem_max + 1];
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

MatieresTemp TabDynMatieresTemp::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return MatieresTemp();
}

MatieresTemp* TabDynMatieresTemp::GetTab() const
{
    return m_tab;
}

void TabDynMatieresTemp::Set(unsigned int index, MatieresTemp value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
    }
}

MatieresTemp TabDynMatieresTemp::Pop()
{
    return Pop(m_nb_elem - 1);
}

MatieresTemp TabDynMatieresTemp::Pop(int index)
{
    if (index < m_nb_elem)
    {
        MatieresTemp value = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return value;
    }
    return MatieresTemp();
}

void TabDynMatieresTemp::Remove(MatieresTemp value, int num)
{
    int count = 0;
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_tab[i].GetId() == value.GetId())
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

void TabDynMatieresTemp::Remove(MatieresTemp value)
{
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_tab[i].GetId() == value.GetId())
        {
            Pop(i);
            i--;
        }
    }
}

void TabDynMatieresTemp::Remove(MatieresTemp value, bool first)
{
    if (first)
    {
        for (unsigned int i = 0; i < m_nb_elem; i++)
        {
            if (m_tab[i].GetId() == value.GetId())
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
            if (m_tab[i].GetId() == value.GetId())
            {
                Pop(i);
                break;
            }
        }
    }
}