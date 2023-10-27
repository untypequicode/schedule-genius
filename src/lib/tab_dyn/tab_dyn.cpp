#include "tab_dyn.h"

TabDyn::TabDyn()
        : m_nb_elem(0),
          m_nb_elem_max(0),
          m_add_with_multiple(true),
          m_number_addition(2),
          m_security(false)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max)
        : m_nb_elem(0),
          m_nb_elem_max(nb_elem_max),
          m_add_with_multiple(true),
          m_number_addition(2),
          m_security(true)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
        : m_nb_elem(0),
          m_nb_elem_max(nb_elem_max),
          m_add_with_multiple(add_with_multiple),
          m_number_addition(number_addition),
          m_security(true)
{
    if (m_number_addition < 2)
        m_number_addition = 2;
}

TabDyn::TabDyn(const TabDyn& tab_dyn)
        : m_nb_elem(tab_dyn.m_nb_elem),
          m_nb_elem_max(tab_dyn.m_nb_elem_max),
          m_add_with_multiple(tab_dyn.m_add_with_multiple),
          m_number_addition(tab_dyn.m_number_addition),
          m_security(tab_dyn.m_security)
{

}

TabDyn::~TabDyn()
{

}

unsigned int TabDyn::GetNbElem() const
{
    return m_nb_elem;
}

unsigned int TabDyn::GetNbElemMax() const
{
    return m_nb_elem_max;
}

void TabDyn::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_add_with_multiple = add_with_multiple;
    if (number_addition < 2)
    {
        number_addition = 2;
    }
    else
    {
        number_addition = number_addition;
    }
}

void TabDyn::Clear()
{
    m_nb_elem = 0;
    m_nb_elem_max = 0;
}

void TabDyn::Clear(bool save_tab_memory)
{
    m_nb_elem = 0;
    if (not save_tab_memory)
    {
        m_nb_elem_max = 0;
    }
}

void TabDyn::SetSecurity(bool security)
{
    m_security = security;
}