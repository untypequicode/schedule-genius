#include "dict_dyn.h"

DictDynCharInt::DictDynCharInt()
    : DictDyn()
{

}

DictDynCharInt::DictDynCharInt(unsigned int nb_elem_max)
    : DictDyn(nb_elem_max),
      m_tab_keys(nb_elem_max),
      m_tab_values(nb_elem_max)
{

}

DictDynCharInt::DictDynCharInt(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : DictDyn(nb_elem_max, add_with_multiple, number_addition),
      m_tab_keys(nb_elem_max, add_with_multiple, number_addition),
      m_tab_values(nb_elem_max, add_with_multiple, number_addition)
{

}

DictDynCharInt::DictDynCharInt(const DictDynCharInt& dict_dyn_ref)
    : DictDyn(dict_dyn_ref),
      m_tab_keys(dict_dyn_ref.m_tab_keys),
      m_tab_values(dict_dyn_ref.m_tab_values)
{

}

DictDynCharInt::~DictDynCharInt()
{

}

void DictDynCharInt::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_tab_keys.SetParam(add_with_multiple, number_addition);
    m_tab_values.SetParam(add_with_multiple, number_addition);
}

void DictDynCharInt::SetSecurity(bool security)
{
    m_tab_keys.SetSecurity(security);
    m_tab_values.SetSecurity(security);
}

void DictDynCharInt::Copy(DictDynCharInt &dict_dyn_ref){
    m_tab_keys.Copy(dict_dyn_ref.m_tab_keys);
    m_tab_values.Copy(dict_dyn_ref.m_tab_values);
}

void DictDynCharInt::Add(char key, int value)
{
    Add(key, value, true);
}

void DictDynCharInt::Add(char key, int value, bool add_with_multiple)
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

int DictDynCharInt::Get(char key) const
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            return m_tab_values.Get(i);
        }
    }
    return '\0';
}

TabDynChar DictDynCharInt::GetTabKeys() const
{
    return m_tab_keys;
}

TabDynInt DictDynCharInt::GetTabValues() const
{
    return m_tab_values;
}

void DictDynCharInt::Set(char key, int value)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

int DictDynCharInt::Pop(char key)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_keys.Pop(i);
            return m_tab_values.Pop(i);
        }
    }
    return '\0';
}

void DictDynCharInt::Remove(int value, int num)
{
    int count = 0;
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            count++;
            if(count == num){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}

void DictDynCharInt::Remove(int value)
{
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            m_tab_keys.Pop(i);
            m_tab_values.Pop(i);
            i--;
        }
    }
}

void DictDynCharInt::Remove(int value, bool is_first)
{
    if(is_first){
        for (int i = 0; i < m_tab_values.GetNbElem(); i++){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
    else{
        for (int i = m_tab_values.GetNbElem() - 1; i >= 0 ; i++){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}