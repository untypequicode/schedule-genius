#include "../character/eleves.h"

DictDynIntUnsignedEleve::DictDynIntUnsignedEleve()
    : DictDyn()
{

}

DictDynIntUnsignedEleve::DictDynIntUnsignedEleve(unsigned int nb_elem_max)
    : DictDyn(nb_elem_max),
      m_tab_keys(nb_elem_max),
      m_tab_values(nb_elem_max)
{

}

DictDynIntUnsignedEleve::DictDynIntUnsignedEleve(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : DictDyn(nb_elem_max, add_with_multiple, number_addition),
      m_tab_keys(nb_elem_max, add_with_multiple, number_addition),
      m_tab_values(nb_elem_max, add_with_multiple, number_addition)
{

}

DictDynIntUnsignedEleve::DictDynIntUnsignedEleve(const DictDynIntUnsignedEleve& dict_dyn_ref)
    : DictDyn(dict_dyn_ref),
      m_tab_keys(dict_dyn_ref.m_tab_keys),
      m_tab_values(dict_dyn_ref.m_tab_values)
{

}

DictDynIntUnsignedEleve::~DictDynIntUnsignedEleve()
{

}

void DictDynIntUnsignedEleve::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_tab_keys.SetParam(add_with_multiple, number_addition);
    m_tab_values.SetParam(add_with_multiple, number_addition);
}

void DictDynIntUnsignedEleve::SetSecurity(bool security)
{
    m_tab_keys.SetSecurity(security);
    m_tab_values.SetSecurity(security);
}

void DictDynIntUnsignedEleve::Copy(DictDynIntUnsignedEleve &dict_dyn_ref){
    m_tab_keys.Copy(dict_dyn_ref.m_tab_keys);
    m_tab_values.Copy(dict_dyn_ref.m_tab_values);
}

void DictDynIntUnsignedEleve::Add(int unsigned key, Eleve value)
{
    Add(key, value, true);
}

void DictDynIntUnsignedEleve::Add(int unsigned key, Eleve value, bool add_with_multiple)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
    m_tab_keys.Add(key, add_with_multiple);
    m_tab_values.Add(value, add_with_multiple);
}

Eleve DictDynIntUnsignedEleve::Get(int unsigned key) const
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            return m_tab_values.Get(i);
        }
    }
    return Eleve();
}

TabDynIntUnsigned DictDynIntUnsignedEleve::GetTabKeys() const
{
    return m_tab_keys;
}

TabDynEleve DictDynIntUnsignedEleve::GetTabValues() const
{
    return m_tab_values;
}

void DictDynIntUnsignedEleve::Set(int unsigned key, Eleve value)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

Eleve DictDynIntUnsignedEleve::Pop(int unsigned key)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_keys.Pop(i);
            return m_tab_values.Pop(i);
        }
    }
    return Eleve();
}

void DictDynIntUnsignedEleve::Remove(Eleve value, int num)
{
    int count = 0;
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i).GetId() == value.GetId()){
            count++;
            if(count == num){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}

void DictDynIntUnsignedEleve::Remove(Eleve value)
{
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i).GetId() == value.GetId()){
            m_tab_keys.Pop(i);
            m_tab_values.Pop(i);
            i--;
        }
    }
}

void DictDynIntUnsignedEleve::Remove(Eleve value, bool is_first)
{
    if(is_first){
        for (int i = 0; i < m_tab_values.GetNbElem(); i++){
            if(m_tab_values.Get(i).GetId() == value.GetId()){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
    else{
        for (int i = m_tab_values.GetNbElem() - 1; i >= 0 ; i++){
            if(m_tab_values.Get(i).GetId() == value.GetId()){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}