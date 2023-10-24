#include "dict_dyn.h"

DictDyn::DictDyn()
    : m_nb_elem(0),
      m_nb_elem_max(0)
{

}

DictDyn::DictDyn(unsigned int nb_elem_max)
    : m_nb_elem(0),
      m_nb_elem_max(nb_elem_max)
{

}

DictDyn::DictDyn(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : m_nb_elem(0),
      m_nb_elem_max(nb_elem_max)
{

}

DictDyn::DictDyn(const DictDyn& dict_dyn)
    : m_nb_elem(dict_dyn.m_nb_elem),
      m_nb_elem_max(dict_dyn.m_nb_elem_max)
{

}

DictDyn::~DictDyn()
{

}

unsigned int DictDyn::GetNbElem() const
{
    return m_nb_elem;
}

unsigned int DictDyn::GetNbElemMax() const
{
    return m_nb_elem_max;
}

void DictDyn::Clear()
{
    m_nb_elem = 0;
    m_nb_elem_max = 0;
}

void DictDyn::Clear(bool save_tab_memory)
{
    m_nb_elem = 0;
    if (not save_tab_memory)
    {
        m_nb_elem_max = 0;
    }
}