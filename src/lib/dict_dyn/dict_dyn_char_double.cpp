#include "dict_dyn.h"

DictDynCharDouble::DictDynCharDouble()
    : DictDyn(),
      m_tab_keys(),
      m_tab_values()
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

unsigned int DictDynCharDouble::GetNbElem() const
{
  if (m_tab_keys.GetNbElem() < m_tab_values.GetNbElem())
    {
        return m_tab_keys.GetNbElem();
    }
  return m_tab_values.GetNbElem();
}

unsigned int DictDynCharDouble::GetNbElemMax() const
{
  if (m_tab_keys.GetNbElemMax() < m_tab_values.GetNbElemMax())
    {
    return m_tab_keys.GetNbElemMax();
  }
  return m_tab_values.GetNbElemMax();
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
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
    m_tab_keys.Add(key, add_with_multiple);
    m_tab_values.Add(value, add_with_multiple);

}

double DictDynCharDouble::Get(char key) const
{
    for (int i = 0; i < GetNbElem(); i++){
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
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

bool DictDynCharDouble::IfValue(char key, std::string condition, double value_id)
{
    if(condition == "=" or condition == "==" or condition == "is")
      return (Get(key) == value_id);
    else if(condition == "!=" or condition == "is not")
      return (Get(key) != value_id);
    else if(condition == "<")
      return (Get(key) < value_id);
    else if(condition == "<=")
      return (Get(key) <= value_id);
    else if(condition == ">")
      return (Get(key) > value_id);
    else if(condition == ">=")
      return (Get(key) >= value_id);
    else
        std::cerr << "Error: condition not found" << std::endl;
    return false;
}

bool DictDynCharDouble::TestIfValue(unsigned int index, std::string condition, double value_id)
{
    if(condition == "==" or condition == "=" or condition == "is")
      return (m_tab_values.Get(index) == value_id);
    else if(condition == "!=" or condition == "is not")
      return (m_tab_values.Get(index) != value_id);
    else if(condition == "<")
      return(m_tab_values.Get(index) < value_id);
    else if(condition == "<=")
      return(m_tab_values.Get(index) <= value_id);
    else if(condition == ">")
      return(m_tab_values.Get(index) > value_id);
    else if(condition == ">=")
      return(m_tab_values.Get(index) >= value_id);
    else
      std::cerr << "Error: condition not found" << std::endl;
    return false;
}

bool DictDynCharDouble::IfKey(char key, std::string condition, char value)
{
    if(condition == "=" or condition == "==" or condition == "is")
        return (key == value);
    else if(condition == "!=" or condition == "is not")
        return (key != value);
    else if(condition == "<")
        return(key < value);
    else if(condition == "<=")
        return(key <= value);
    else if(condition == ">")
        return(key > value);
    else if(condition == ">=")
        return(key >= value);
    else
      std::cerr << "Error: condition not found" << std::endl;
    return false;
}

bool DictDynCharDouble::TestIfKey(unsigned int index, std::string condition, char value)
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
    return false;
}

DictDynCharDouble DictDynCharDouble::FiltreValue(std::string condition, double value)
{
    DictDynCharDouble dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(TestIfValue(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreValue(TabDynString condition, TabDynDouble value, TabDynString OrAnd)
{
    DictDynCharDouble dict_dyn_result;
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
                DictDynCharDouble a = DictDynCharDouble();
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

DictDynCharDouble DictDynCharDouble::FiltreKey(TabDynString condition, TabDynChar value, TabDynString OrAnd)
{
    DictDynCharDouble dict_dyn_result;
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
                DictDynCharDouble a = DictDynCharDouble();
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

DictDynCharDouble DictDynCharDouble::FiltreAndValue(TabDynString condition, TabDynDouble value)
{
    DictDynCharDouble dict_dyn_result;
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

DictDynCharDouble DictDynCharDouble::FiltreOrValue(TabDynString condition, TabDynDouble value)
{
    DictDynCharDouble dict_dyn_result;
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

DictDynCharDouble DictDynCharDouble::FiltreKey(std::string condition, char value)
{
    DictDynCharDouble dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(TestIfKey(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreAndKey(TabDynString condition, TabDynChar value)
{
    DictDynCharDouble dict_dyn_result;
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

DictDynCharDouble DictDynCharDouble::FiltreOrKey(TabDynString condition, TabDynChar value)
{
    DictDynCharDouble dict_dyn_result;
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

DictDynCharDouble fusion(DictDynCharDouble dict_dyn_ref, DictDynCharDouble dict_dyn_ref2)
{
    char key;
    DictDynCharDouble dict_dyn_result;
    
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

double DictDynCharDouble::Pop(char key)
{
    for (int i = 0; i < GetNbElem(); i++){
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

void DictDynCharDouble::Remove(double value)
{
    for (int i = 0; i < GetNbElem(); i++){
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