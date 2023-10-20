#include "../character/eleves.h"

TabDynEleve::TabDynEleve()
        : TabDyn()
{

}

TabDynEleve::TabDynEleve(unsigned int nbElemMax)
        : TabDyn(nbElemMax),
          m_tab(new Eleve[nbElemMax])
{

}

TabDynEleve::TabDynEleve(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
        : TabDyn(nbElemMax, add_with_multiple, addition),
          m_tab(new Eleve[nbElemMax])
{

}

TabDynEleve::TabDynEleve(const TabDynEleve& tabDynEleve)
        : TabDyn(tabDynEleve),
          m_tab(new Eleve[tabDynEleve.m_nb_elem_max])
{
    for (unsigned int i = 0; i < tabDynEleve.m_nb_elem; i++)
    {
        m_tab[i] = tabDynEleve.m_tab[i];
    }
}

TabDynEleve::~TabDynEleve()
{
    if (m_security)
    {
        if (m_tab != nullptr)
        {
            delete[] m_tab;
        }
    }
}

void TabDynEleve::Add(Eleve eleve)
{
    Add(eleve, true);
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

void TabDynEleve::Set(unsigned int index, Eleve i)
{
    if (index < m_nb_elem)
    {
        m_tab[index] = i;
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
        Eleve elem = m_tab[index];
        for (unsigned int i = index; i < m_nb_elem - 1; i++)
        {
            m_tab[i] = m_tab[i + 1];
        }
        m_nb_elem--;
        return elem;
    }
    return Eleve();
}

void TabDynEleve::Remove(Eleve elem, int num)
{
    int count = 0;
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_tab[i].GetId() == elem.GetId())
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

void TabDynEleve::Remove(Eleve elem)
{
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_tab[i].GetId() == elem.GetId())
        {
            Pop(i);
            i--;
        }
    }
}

void TabDynEleve::Remove(Eleve elem, bool first)
{
    if (first)
    {
        for (unsigned int i = 0; i < m_nb_elem; i++)
        {
            if (m_tab[i].GetId() == elem.GetId())
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
            if (m_tab[i].GetId() == elem.GetId())
            {
                Pop(i);
                break;
            }
        }
    }
}

void TabDynEleve::Add(Eleve eleve, bool addition)
{
    if (m_nb_elem_max == 0)
    {
        if (addition)
        {
            m_tab = new Eleve[m_number_addition];
            m_nb_elem_max = m_number_addition;
        }
        else
        {
            m_tab = new Eleve[1];
            m_nb_elem_max = 1;
        }
        m_tab[0] = eleve;
        m_nb_elem = 1;
    }
    else if (m_nb_elem < m_nb_elem_max)
    {
        m_tab[m_nb_elem] = eleve;
        m_nb_elem++;
    }
    else if (m_nb_elem == m_nb_elem_max)
    {
        Eleve* new_tab;
        if (addition)
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
        new_tab[m_nb_elem] = eleve;
        if (addition)
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
    }
}