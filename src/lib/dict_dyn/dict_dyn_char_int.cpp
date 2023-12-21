#include "dict_dyn.h"

DictDynCharInt::DictDynCharInt()
    : DictDyn(),
      m_tab_keys(),
      m_tab_values()
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

unsigned int DictDynCharInt::GetNbElem() const
{
  if (m_tab_keys.GetNbElem() < m_tab_values.GetNbElem())
    {
        return m_tab_keys.GetNbElem();
    }
  return m_tab_values.GetNbElem();
}

unsigned int DictDynCharInt::GetNbElemMax() const
{
  if (m_tab_keys.GetNbElemMax() < m_tab_values.GetNbElemMax())
    {
    return m_tab_keys.GetNbElemMax();
  }
  return m_tab_values.GetNbElemMax();
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
    for (int i = 0; i < GetNbElem(); i++){
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
    for (int i = 0; i < GetNbElem(); i++){
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
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

bool DictDynCharInt::IfValue(char key, std::string condition, int value_id)
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

bool DictDynCharInt::TestIfValue(unsigned int index, std::string condition, int value_id)
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

bool DictDynCharInt::IfKey(char key, std::string condition, char value)
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

bool DictDynCharInt::TestIfKey(unsigned int index, std::string condition, char value)
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

DictDynCharInt DictDynCharInt::FiltreValue(std::string condition, int value)
{
    DictDynCharInt dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(TestIfValue(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharInt DictDynCharInt::FiltreValue(TabDynString condition, TabDynInt value, TabDynString OrAnd)
{
    DictDynCharInt dict_dyn_result;
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
                DictDynCharInt a = DictDynCharInt();
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

DictDynCharInt DictDynCharInt::FiltreKey(TabDynString condition, TabDynChar value, TabDynString OrAnd)
{
    DictDynCharInt dict_dyn_result;
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
                DictDynCharInt a = DictDynCharInt();
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

DictDynCharInt DictDynCharInt::FiltreAndValue(TabDynString condition, TabDynInt value)
{
    DictDynCharInt dict_dyn_result;
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

DictDynCharInt DictDynCharInt::FiltreOrValue(TabDynString condition, TabDynInt value)
{
    DictDynCharInt dict_dyn_result;
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

DictDynCharInt DictDynCharInt::FiltreKey(std::string condition, char value)
{
    DictDynCharInt dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(TestIfKey(i, condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharInt DictDynCharInt::FiltreAndKey(TabDynString condition, TabDynChar value)
{
    DictDynCharInt dict_dyn_result;
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

DictDynCharInt DictDynCharInt::FiltreOrKey(TabDynString condition, TabDynChar value)
{
    DictDynCharInt dict_dyn_result;
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

DictDynCharInt fusion(DictDynCharInt dict_dyn_ref, DictDynCharInt dict_dyn_ref2)
{
    char key;
    DictDynCharInt dict_dyn_result;
    
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

int DictDynCharInt::Pop(char key)
{
    for (int i = 0; i < GetNbElem(); i++){
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

void DictDynCharInt::Remove(int value)
{
    for (int i = 0; i < GetNbElem(); i++){
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