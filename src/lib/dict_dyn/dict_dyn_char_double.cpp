#include "dict_dyn.h"

DictDynCharDouble::DictDynCharDouble()
    : DictDyn()
{

}

DictDynCharDouble::DictDynCharDouble(unsigned int nb_elem_max)
    : DictDyn(nb_elem_max),
      m_tab_keys(nb_elem_max),
      m_tab_values(nb_elem_max)
{

}

DictDynCharDouble::DictDynCharDouble(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : DictDyn(nb_elem_max, add_with_multiple, number_addition),
      m_tab_keys(nb_elem_max, add_with_multiple, number_addition),
      m_tab_values(nb_elem_max, add_with_multiple, number_addition)
{

}

DictDynCharDouble::DictDynCharDouble(const DictDynCharDouble& dict_dyn_ref)
    : DictDyn(dict_dyn_ref),
      m_tab_keys(dict_dyn_ref.m_tab_keys),
      m_tab_values(dict_dyn_ref.m_tab_values)
{

}

DictDynCharDouble::~DictDynCharDouble()
{

}

void DictDynCharDouble::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_tab_keys.SetParam(add_with_multiple, number_addition);
    m_tab_values.SetParam(add_with_multiple, number_addition);
}

void DictDynCharDouble::SetSecurity(bool security)
{
    m_tab_keys.SetSecurity(security);
    m_tab_values.SetSecurity(security);
}

void DictDynCharDouble::Copy(DictDynCharDouble &dict_dyn_ref){
    m_tab_keys.Copy(dict_dyn_ref.m_tab_keys);
    m_tab_values.Copy(dict_dyn_ref.m_tab_values);
}

void DictDynCharDouble::Add(char key, double value)
{
    Add(key, value, true);
}

void DictDynCharDouble::Add(char key, double value, bool add_with_multiple)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
    m_tab_keys.Add(key, add_with_multiple);
    m_tab_values.Add(value, add_with_multiple);
    m_nb_elem++;

}

double DictDynCharDouble::Get(char key) const
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            return m_tab_values.Get(i);
        }
    }
    return '\0';
}

TabDynChar DictDynCharDouble::GetTabKeys() const
{
    return m_tab_keys;
}

TabDynDouble DictDynCharDouble::GetTabValues() const
{
    return m_tab_values;
}

void DictDynCharDouble::Set(char key, double value)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

bool DictDynCharDouble::IfElement(unsigned int index ,std::string condition, double value)
{
    if(condition == "=" or condition == "==" or condition == "is")
        return (m_tab_values.Get(index) == value);
    else if(condition == "!=" or condition == "is not")
        return (m_tab_values.Get(index) != value);
    else if(condition == "<")
        return(m_tab_values.Get(index) < value);
    else if(condition == "<=")
        return(m_tab_values.Get(index) <= value);
    else if(condition == ">")
        return(m_tab_values.Get(index) > value);
    else if(condition == ">=")
        return(m_tab_values.Get(index) >= value);
    else
        std::cerr << "Error: condition not found" << std::endl;
}

bool DictDynCharDouble::IfKey(unsigned int index, std::string condition, char value)
{
    if(condition == "=" or condition == "==" or condition == "is")
        return (m_tab_keys.Get(index) == value);
    else if(condition == "!=" or condition == "is not")
        return (m_tab_keys.Get(index) != value);
    else if(condition == "<")
        return(m_tab_keys.Get(index) < value);
    else if(condition == "<=")
        return(m_tab_keys.Get(index) <= value);
    else if(condition == ">")
        return(m_tab_keys.Get(index) > value);
    else if(condition == ">=")
        return(m_tab_keys.Get(index) >= value);
    else
        std::cerr << "Error: condition not found" << std::endl;
}

DictDynCharDouble DictDynCharDouble::FiltreElement(std::string condition, double value)
{
    DictDynCharDouble dict_dyn_result;
    for (unsigned int i = 0; i < m_nb_elem; i++){
        if(IfElement(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreKey(std::string condition, char value)
{
    DictDynCharDouble dict_dyn_result;
    for (unsigned int i = 0; i < m_nb_elem; i++){
        if(IfKey(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

double DictDynCharDouble::Pop(char key)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_keys.Pop(i);
            return m_tab_values.Pop(i);
        }
    }
    return '\0';
}

void DictDynCharDouble::Remove(double value, int num)
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

void DictDynCharDouble::Remove(double value)
{
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            m_tab_keys.Pop(i);
            m_tab_values.Pop(i);
            i--;
        }
    }
}

void DictDynCharDouble::Remove(double value, bool is_first)
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
        for (int i = m_tab_values.GetNbElem() - 1; i >= 0 ; i--){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}