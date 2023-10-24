#include "../character/eleves.h"

TabDynEleve::TabDynEleve()
        : TabDyn()
{

}

TabDynEleve::TabDynEleve(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new Eleve[nb_elem_max])
{

}

TabDynEleve::TabDynEleve(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new Eleve[nb_elem_max])
{

}

TabDynEleve::TabDynEleve(const TabDynEleve& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new Eleve[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynEleve::~TabDynEleve()
{
    if (m_security and m_tab != nullptr)
    {
        delete[] m_tab;
    }
}

void TabDynEleve::Copy(TabDynEleve& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynEleve::Add(Eleve value)
{
    Add(value, true);
}

void TabDynEleve::Add(Eleve value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new Eleve[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new Eleve[1];
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
        Eleve* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new Eleve[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new Eleve[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new Eleve[m_nb_elem_max + 1];
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

Eleve TabDynEleve::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return Eleve();
}

Eleve* TabDynEleve::GetTab() const
{
    return m_tab;
}

void TabDynEleve::Set(unsigned int index, Eleve value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
    }
}

Eleve TabDynEleve::Pop()
{
    return Pop(m_nb_elem - 1);
}

Eleve TabDynEleve::Pop(int index)
{
    if (index < m_nb_elem)
    {
        Eleve value = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return value;
    }
    return Eleve();
}

void TabDynEleve::Remove(Eleve value, int num)
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

void TabDynEleve::Remove(Eleve value)
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

void TabDynEleve::Remove(Eleve value, bool first)
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