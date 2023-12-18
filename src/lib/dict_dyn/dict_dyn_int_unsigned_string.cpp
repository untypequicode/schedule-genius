#include "dict_dyn.h"

DictDynIntUnsignedString::DictDynIntUnsignedString()
    : DictDyn()
{

}

DictDynIntUnsignedString::DictDynIntUnsignedString(unsigned int nb_elem_max)
    : DictDyn(nb_elem_max),
      m_tab_keys(nb_elem_max),
      m_tab_values(nb_elem_max)
{

}

DictDynIntUnsignedString::DictDynIntUnsignedString(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : DictDyn(nb_elem_max, add_with_multiple, number_addition),
      m_tab_keys(nb_elem_max, add_with_multiple, number_addition),
      m_tab_values(nb_elem_max, add_with_multiple, number_addition)
{

}

DictDynIntUnsignedString::DictDynIntUnsignedString(const DictDynIntUnsignedString& dict_dyn_ref)
    : DictDyn(dict_dyn_ref),
      m_tab_keys(dict_dyn_ref.m_tab_keys),
      m_tab_values(dict_dyn_ref.m_tab_values)
{

}

DictDynIntUnsignedString::~DictDynIntUnsignedString()
{

}

void DictDynIntUnsignedString::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_tab_keys.SetParam(add_with_multiple, number_addition);
    m_tab_values.SetParam(add_with_multiple, number_addition);
}

void DictDynIntUnsignedString::SetSecurity(bool security)
{
    m_tab_keys.SetSecurity(security);
    m_tab_values.SetSecurity(security);
}

void DictDynIntUnsignedString::Copy(DictDynIntUnsignedString &dict_dyn_ref){
    m_tab_keys.Copy(dict_dyn_ref.m_tab_keys);
    m_tab_values.Copy(dict_dyn_ref.m_tab_values);
}

void DictDynIntUnsignedString::Add(int unsigned key, std::string value)
{
    Add(key, value, true);
}

void DictDynIntUnsignedString::Add(int unsigned key, std::string value, bool add_with_multiple)
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

std::string DictDynIntUnsignedString::Get(int unsigned key) const
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            return m_tab_values.Get(i);
        }
    }
    return "\0";
}

TabDynIntUnsigned DictDynIntUnsignedString::GetTabKeys() const
{
    return m_tab_keys;
}

TabDynString DictDynIntUnsignedString::GetTabValues() const
{
    return m_tab_values;
}

void DictDynIntUnsignedString::Set(int unsigned key, std::string value)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

bool DictDynIntUnsignedString::IfValue(int unsigned cle ,std::string condition, std::string value)
{
    if(condition == "=" or condition == "==" or condition == "is")
        return (Get(cle) == value);
    else if(condition == "!=" or condition == "is not")
        return (Get(cle) != value);
    else if(condition == "<")
        return(Get(cle) < value);
    else if(condition == "<=")
        return(Get(cle) <= value);
    else if(condition == ">")
        return(Get(cle) > value);
    else if(condition == ">=")
        return(Get(cle) >= value);
    else
        std::cerr << "Error: condition not found" << std::endl;
}

bool DictDynIntUnsignedString::TestIfValue(unsigned int index, std::string condition, std::string value)
{
    if(condition == "==" or condition == "=" or condition == "is")
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

bool DictDynIntUnsignedString::IfKey(int unsigned cle, std::string condition, int unsigned value)
{
    if(condition == "=" or condition == "==" or condition == "is")
        return (cle == value);
    else if(condition == "!=" or condition == "is not")
        return (cle != value);
    else if(condition == "<")
        return(cle < value);
    else if(condition == "<=")
        return(cle <= value);
    else if(condition == ">")
        return(cle > value);
    else if(condition == ">=")
        return(cle >= value);
    else
        std::cerr << "Error: condition not found" << std::endl;
}

bool DictDynIntUnsignedString::TestIfKey(unsigned int index, std::string condition, int unsigned value)
{
    if (condition == "=" or condition == "==" or condition == "is")
        return (m_tab_keys.Get(index) == value);
    else if (condition == "!=" or condition == "is not")
        return (m_tab_keys.Get(index) != value);
    else if (condition == "<")
        return (m_tab_keys.Get(index) < value);
    else if (condition == "<=")
        return (m_tab_keys.Get(index) <= value);
    else if (condition == ">")
        return (m_tab_keys.Get(index) > value);
    else if (condition == ">=")
        return (m_tab_keys.Get(index) >= value);
    else
        std::cerr << "Error: condition not found" << std::endl;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreValue(std::string condition, std::string value)
{
    DictDynIntUnsignedString dict_dyn_result;
    for (unsigned int i = 0; i < m_nb_elem; i++){
        if(IfValue(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreValue(TabDynString condition, TabDynString value, TabDynString OrAnd)
{
    DictDynIntUnsignedString dict_dyn_result;
    bool test;
    unsigned int index = 0;
    for (unsigned int i = 0; i < m_nb_elem; i++) {
        test = IfValue(i, condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test) {
                index++;
                test = IfValue(i, condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = IfValue(i, condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden, only 'and' and 'or' are allowed" << std::endl;
                DictDynIntUnsignedString a = DictDynIntUnsignedString();
                return a;
            }
        }
        index = 0;
        if(test)
        {
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
            test = false;
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreKey(TabDynString condition, TabDynIntUnsigned value, TabDynString OrAnd)
{
    DictDynIntUnsignedString dict_dyn_result;
    bool test;
    unsigned int index = 0;
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        test = IfKey(i, condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test)
            {
                index++;
                test = IfKey(i, condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = IfKey(m_tab_keys.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden, only 'and' and 'or' are allowed" << std::endl;
                DictDynIntUnsignedString a = DictDynIntUnsignedString();
                return a;
            }
        }
        index = 0;
        if(test)
        {
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
            test = false;
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreAndValue(TabDynString condition, TabDynString value)
{
    DictDynIntUnsignedString dict_dyn_result;
    bool test = true;
    for(unsigned int i = 0; i < m_nb_elem; i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(!IfValue(i, condition.Get(j), value.Get(j)))
            {
                test = false;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = true;
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreOrValue(TabDynString condition, TabDynString value)
{
    DictDynIntUnsignedString dict_dyn_result;
    bool test = false;
    for(unsigned int i = 0; i < m_nb_elem; i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(IfValue(i, condition.Get(j), value.Get(j)))
            {
                test = true;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = false;
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreKey(std::string condition, int unsigned value)
{
    DictDynIntUnsignedString dict_dyn_result;
    for (unsigned int i = 0; i < m_nb_elem; i++){
        if(IfKey(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreAndKey(TabDynString condition, TabDynIntUnsigned value)
{
    DictDynIntUnsignedString dict_dyn_result;
    bool test = true;
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(!IfKey(i, condition.Get(j), value.Get(j))){
                test = false;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = true;
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString DictDynIntUnsignedString::FiltreOrKey(TabDynString condition, TabDynIntUnsigned value)
{
    DictDynIntUnsignedString dict_dyn_result;
    bool test = false;
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(IfKey(i, condition.Get(j), value.Get(j))){
                test = true;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = false;
    }
    return dict_dyn_result;
}

DictDynIntUnsignedString fusion(DictDynIntUnsignedString dict_dyn_ref, DictDynIntUnsignedString dict_dyn_ref2)
{
    int unsigned key;
    DictDynIntUnsignedString dict_dyn_result;
    
    for (unsigned int i = 0; i < dict_dyn_ref2.GetNbElem(); i++) {
        key = dict_dyn_ref2.GetTabKeys().Get(i);
        dict_dyn_result.Add(key, dict_dyn_ref2.Get(key));
        dict_dyn_ref.Pop(key);
    }
    for(unsigned int i = 0; i < dict_dyn_ref.GetNbElem(); i++)
    {
        key = dict_dyn_ref.GetTabKeys().Get(i);
        dict_dyn_result.Add(key, dict_dyn_ref.Get(key));

    }
    return dict_dyn_result;
}

std::string DictDynIntUnsignedString::Pop(int unsigned key)
{
    for (int i = 0; i < m_tab_keys.GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_keys.Pop(i);
            m_nb_elem--;
            return m_tab_values.Pop(i);
        }
    }
    return "\0";
}

void DictDynIntUnsignedString::Remove(std::string value, int num)
{
    int count = 0;
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            count++;
            if(count == num){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                m_nb_elem--;
                return;
            }
        }
    }
}

void DictDynIntUnsignedString::Remove(std::string value)
{
    for (int i = 0; i < m_tab_values.GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            m_tab_keys.Pop(i);
            m_tab_values.Pop(i);
            i--;
            m_nb_elem--;
        }
    }
}

void DictDynIntUnsignedString::Remove(std::string value, bool is_first)
{
    if(is_first){
        for (int i = 0; i < m_tab_values.GetNbElem(); i++){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                m_nb_elem--;
                return;
            }
        }
    }
    else{
        for (int i = m_tab_values.GetNbElem() - 1; i >= 0 ; i--){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                m_nb_elem--;
                return;
            }
        }
    }
}