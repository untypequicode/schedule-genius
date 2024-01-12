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

void DictDynIntUnsignedFloat::Clear() {
    m_tab_keys.Clear();
    m_tab_values.Clear();
}

void DictDynIntUnsignedFloat::Clear(bool save_tab_memory) {
    m_tab_keys.Clear(save_tab_memory);
    m_tab_values.Clear(save_tab_memory);
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

TabDynIntUnsigned& DictDynIntUnsignedFloat::GetTabKeys()
{
    return m_tab_keys;
}

TabDynFloat& DictDynIntUnsignedFloat::GetTabValues()
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

bool DictDynIntUnsignedFloat::IfValue(int unsigned key, std::string condition, float value_id)
{
    return comparaison(Get(key), condition, value_id);
}

bool DictDynIntUnsignedFloat::IfKey(int unsigned key, std::string condition, int unsigned value)
{
    return comparaison(key, condition, value);
}

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreValue(std::string condition, float value, DictDynIntUnsignedFloat& dict_dyn_result)
{
    for (unsigned int i = 0; i < GetNbElem(); i++){
      if(comparaison(m_tab_values.Get(i), condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreValue(const TabDynString& condition, const TabDynFloat& value, const TabDynString& OrAnd, DictDynIntUnsignedFloat& dict_dyn_result)
{
    for (unsigned int i = 0; i < condition.GetNbElem(); i++)
        std::cout << "condition : '" << condition.Get(i) << "'" << std::endl;

    bool test;
    unsigned int index;
    for (unsigned int i = 0; i < GetNbElem(); i++) {
        index = 0;
        test = comparaison(m_tab_values.Get(i), condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test) {
                index++;
                test = comparaison(m_tab_values.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = comparaison(m_tab_values.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden : '"<< OrAnd.Get(index) << "' , only 'and' and 'or' are allowed" << std::endl;
                std::cerr << "index :" << index;
                dict_dyn_result.Clear();
                return dict_dyn_result;
            }
        }
        if(test)
        {
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
            test = false;
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreKey(const TabDynString& condition, const TabDynIntUnsigned& value, const TabDynString& OrAnd, DictDynIntUnsignedFloat& dict_dyn_result)
{
    bool test;
    unsigned int index = 0;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        test = comparaison(m_tab_keys.Get(i), condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test)
            {
                index++;
                test = comparaison(m_tab_keys.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = comparaison(m_tab_keys.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden, only 'and' and 'or' are allowed" << std::endl;
                dict_dyn_result.Clear();
                return dict_dyn_result;
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

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreAndValue(const TabDynString& condition, const TabDynFloat& value, DictDynIntUnsignedFloat& dict_dyn_result)
{
    bool test = true;
    for(unsigned int i = 0; i < GetNbElem(); i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(!comparaison(m_tab_values.Get(i), condition.Get(j), value.Get(j)))
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

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreOrValue(const TabDynString& condition, const TabDynFloat& value, DictDynIntUnsignedFloat& dict_dyn_result)
{
    bool test = false;
    for(unsigned int i = 0; i < GetNbElem(); i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(comparaison(m_tab_values.Get(i), condition.Get(j), value.Get(j)))
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

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreKey(std::string condition, int unsigned value, DictDynIntUnsignedFloat& dict_dyn_result)
{
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(comparaison(m_tab_keys.Get(i), condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreAndKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedFloat& dict_dyn_result)
{
    bool test = true;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(!comparaison(m_tab_keys.Get(i), condition.Get(j), value.Get(j))){
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

DictDynIntUnsignedFloat& DictDynIntUnsignedFloat::FiltreOrKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedFloat& dict_dyn_result)
{
    bool test = false;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(comparaison(m_tab_keys.Get(i), condition.Get(j), value.Get(j))){
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

DictDynIntUnsignedFloat& fusion(DictDynIntUnsignedFloat& dict_dyn_ref, DictDynIntUnsignedFloat& dict_dyn_ref2, DictDynIntUnsignedFloat& dict_dyn_result)
{
    int unsigned key;

    if (dict_dyn_ref.GetNbElem() < dict_dyn_ref2.GetNbElem())
    {
        fusionSort(dict_dyn_ref, dict_dyn_ref2, dict_dyn_result);
    }
    else {
        fusionSort(dict_dyn_ref2, dict_dyn_ref, dict_dyn_result);
    }
    return dict_dyn_result;
}

DictDynIntUnsignedFloat& fusionSort(DictDynIntUnsignedFloat& dict_dyn_ref, DictDynIntUnsignedFloat& dict_dyn_ref2, DictDynIntUnsignedFloat& dict_dyn_result)
{
    int unsigned key;
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