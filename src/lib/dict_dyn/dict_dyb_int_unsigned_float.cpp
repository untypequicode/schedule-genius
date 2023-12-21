#include "dict_dyn.h"

DictDynIntUnsignedFloat::DictDynIntUnsignedFloat()
    : DictDyn(),
      m_tab_keys(),
      m_tab_values()
{

}

DictDynIntUnsignedFloat::DictDynIntUnsignedFloat(unsigned int nb_elem_max)
    : DictDyn(nb_elem_max),
      m_tab_keys(nb_elem_max),
      m_tab_values(nb_elem_max)
{

}

DictDynIntUnsignedFloat::DictDynIntUnsignedFloat(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : DictDyn(nb_elem_max, add_with_multiple, number_addition),
      m_tab_keys(nb_elem_max, add_with_multiple, number_addition),
      m_tab_values(nb_elem_max, add_with_multiple, number_addition)
{

}

DictDynIntUnsignedFloat::DictDynIntUnsignedFloat(const DictDynIntUnsignedFloat& dict_dyn_ref)
    : DictDyn(dict_dyn_ref),
      m_tab_keys(dict_dyn_ref.m_tab_keys),
      m_tab_values(dict_dyn_ref.m_tab_values)
{

}

DictDynIntUnsignedFloat::~DictDynIntUnsignedFloat()
{

}

void DictDynIntUnsignedFloat::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_tab_keys.SetParam(add_with_multiple, number_addition);
    m_tab_values.SetParam(add_with_multiple, number_addition);
}

void DictDynIntUnsignedFloat::SetSecurity(bool security)
{
    m_tab_keys.SetSecurity(security);
    m_tab_values.SetSecurity(security);
}

unsigned int DictDynIntUnsignedFloat::GetNbElem() const
{
  if (m_tab_keys.GetNbElem() < m_tab_values.GetNbElem())
    {
        return m_tab_keys.GetNbElem();
    }
  return m_tab_values.GetNbElem();
}

unsigned int DictDynIntUnsignedFloat::GetNbElemMax() const
{
  if (m_tab_keys.GetNbElemMax() < m_tab_values.GetNbElemMax())
    {
    return m_tab_keys.GetNbElemMax();
  }
  return m_tab_values.GetNbElemMax();
}

void DictDynIntUnsignedFloat::Copy(DictDynIntUnsignedFloat &dict_dyn_ref){
    m_tab_keys.Copy(dict_dyn_ref.m_tab_keys);
    m_tab_values.Copy(dict_dyn_ref.m_tab_values);
}

void DictDynIntUnsignedFloat::Add(int unsigned key, float value)
{
    Add(key, value, true);
}

void DictDynIntUnsignedFloat::Add(int unsigned key, float value, bool add_with_multiple)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
    m_tab_keys.Add(key, add_with_multiple);
    m_tab_values.Add(value, add_with_multiple);

}

float DictDynIntUnsignedFloat::Get(int unsigned key) const
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            return m_tab_values.Get(i);
        }
    }
    return '\0';
}

TabDynIntUnsigned DictDynIntUnsignedFloat::GetTabKeys() const
{
    return m_tab_keys;
}

TabDynFloat DictDynIntUnsignedFloat::GetTabValues() const
{
    return m_tab_values;
}

void DictDynIntUnsignedFloat::Set(int unsigned key, float value)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

bool DictDynIntUnsignedFloat::IfValue(int unsigned cle, std::string condition, float value)
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

bool DictDynIntUnsignedFloat::TestIfValue(unsigned int index, std::string condition, float value)
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

bool DictDynIntUnsignedFloat::IfKey(int unsigned cle, std::string condition, int unsigned value)
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

bool DictDynIntUnsignedFloat::TestIfKey(unsigned int index, std::string condition, int unsigned value)
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

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreValue(std::string condition, float value)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(TestIfValue(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreValue(TabDynString condition, TabDynFloat value, TabDynString OrAnd)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    bool test;
    unsigned int index = 0;
    for (unsigned int i = 0; i < GetNbElem(); i++) {
        test = TestIfValue(i, condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test) {
                index++;
                test = TestIfValue(i, condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = TestIfValue(i, condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden, only 'and' and 'or' are allowed" << std::endl;
                DictDynIntUnsignedFloat a = DictDynIntUnsignedFloat();
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

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreKey(TabDynString condition, TabDynIntUnsigned value, TabDynString OrAnd)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    bool test;
    unsigned int index = 0;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        test = TestIfKey(i, condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test)
            {
                index++;
                test = TestIfKey(i, condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = TestIfKey(m_tab_keys.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden, only 'and' and 'or' are allowed" << std::endl;
                DictDynIntUnsignedFloat a = DictDynIntUnsignedFloat();
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

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreAndValue(TabDynString condition, TabDynFloat value)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    bool test = true;
    for(unsigned int i = 0; i < GetNbElem(); i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(!TestIfValue(i, condition.Get(j), value.Get(j)))
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

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreOrValue(TabDynString condition, TabDynFloat value)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    bool test = false;
    for(unsigned int i = 0; i < GetNbElem(); i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(TestIfValue(i, condition.Get(j), value.Get(j)))
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

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreKey(std::string condition, int unsigned value)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(TestIfKey(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreAndKey(TabDynString condition, TabDynIntUnsigned value)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    bool test = true;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(!TestIfKey(i, condition.Get(j), value.Get(j))){
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

DictDynIntUnsignedFloat DictDynIntUnsignedFloat::FiltreOrKey(TabDynString condition, TabDynIntUnsigned value)
{
    DictDynIntUnsignedFloat dict_dyn_result;
    bool test = false;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(TestIfKey(i, condition.Get(j), value.Get(j))){
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

DictDynIntUnsignedFloat fusion(DictDynIntUnsignedFloat dict_dyn_ref, DictDynIntUnsignedFloat dict_dyn_ref2)
{
    int unsigned key;
    DictDynIntUnsignedFloat dict_dyn_result;
    
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

float DictDynIntUnsignedFloat::Pop(int unsigned key)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_keys.Pop(i);
            return m_tab_values.Pop(i);
        }
    }
    return '\0';
}

void DictDynIntUnsignedFloat::Remove(float value, int num)
{
    int count = 0;
    for (int i = 0; i < GetNbElem(); i++){
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

void DictDynIntUnsignedFloat::Remove(float value)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            m_tab_keys.Pop(i);
            m_tab_values.Pop(i);
            i--;
        }
    }
}

void DictDynIntUnsignedFloat::Remove(float value, bool is_first)
{
    if(is_first){
        for (int i = 0; i < GetNbElem(); i++){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
    else{
        for (int i = GetNbElem() - 1; i >= 0 ; i--){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}