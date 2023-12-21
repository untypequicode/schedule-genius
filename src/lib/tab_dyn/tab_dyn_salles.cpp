#include "../character/salles.h"

TabDynSalles::TabDynSalles()
        : TabDyn(),
          m_tab(new Salles[0])
{

}

TabDynSalles::TabDynSalles(unsigned int nb_elem_max)
        : TabDyn(nb_elem_max),
          m_tab(new Salles[nb_elem_max])
{

}

TabDynSalles::TabDynSalles(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : TabDyn(nb_elem_max, add_with_multiple, number_addition),
          m_tab(new Salles[nb_elem_max])
{

}

TabDynSalles::TabDynSalles(const TabDynSalles& tab_dyn_ref)
        : TabDyn(tab_dyn_ref),
          m_tab(new Salles[tab_dyn_ref.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(tab_dyn_ref.Get(i));
//        m_tab[i] = tab_dyn_ref.m_tab[i];
    }
}

TabDynSalles::~TabDynSalles()
{
    if (m_security and m_tab != nullptr and m_tab != NULL)
    {
        delete[] m_tab;
    }
}

void TabDynSalles::Copy(TabDynSalles& tab_dyn_ref)
{
    for (unsigned int i = 0; i < tab_dyn_ref.m_nb_elem; i++)
    {
        Add(m_tab[i], false);
    }
}

void TabDynSalles::Add(Salles value)
{
    Add(value, true);
}

void TabDynSalles::Add(Salles value, bool add_with_multiple)
{
    if (m_nb_elem_max == 0)
    {
        if (add_with_multiple)
        {
            m_tab = new Salles[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new Salles[1];
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
        Salles* new_tab;
        if (add_with_multiple)
        {
            if (m_add_with_multiple)
            {
                new_tab = new Salles[m_nb_elem_max * m_number_addition];
            }
            else
            {
                new_tab = new Salles[m_nb_elem_max + m_number_addition];
            }
        }
        else
        {
            new_tab = new Salles[m_nb_elem_max + 1];
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

Salles TabDynSalles::Get(unsigned int index) const
{
    if (index < m_nb_elem)
    {
        return m_tab[index];
    }
    return Salles();
}

Salles* TabDynSalles::GetTab() const
{
    return m_tab;
}

void TabDynSalles::Set(unsigned int index, Salles value)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = value;
    }
}

Salles TabDynSalles::Pop()
{
    return Pop(m_nb_elem - 1);
}

Salles TabDynSalles::Pop(int index)
{
    if (index < m_nb_elem)
    {
        Salles value = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return value;
    }
    return Salles();
}

void TabDynSalles::Remove(Salles value, int num)
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

void TabDynSalles::Remove(Salles value)
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

void TabDynSalles::Remove(Salles value, bool first)
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