#include "dict_dyn.h"

DictDynIntString::DictDynIntString()
    : TabDyn()
{

}

DictDynIntString::DictDynIntString(unsigned int nbElemMax)
    : TabDyn(nbElemMax),
      m_keys(nbElemMax),
      m_values(nbElemMax)
{

}

DictDynIntString::DictDynIntString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
    : TabDyn(nbElemMax, add_with_multiple, addition),
      m_keys(nbElemMax),
      m_values(nbElemMax)
{

}

DictDynIntString::DictDynIntString(const DictDynIntString &dictDynIntString)
    : TabDyn(dictDynIntString),
        m_keys(dictDynIntString.GetKeys()),
        m_values(dictDynIntString.GetValues())
{

}

DictDynIntString::~DictDynIntString()
{

}

void DictDynIntString::Append(int key, std::string value)
{
    AddAppend(key, value, false);
}

void DictDynIntString::Add(int key, std::string value)
{
    AddAppend(key, value, true);
}

std::string DictDynIntString::Get(int key) const
{
    for (unsigned int i = 0; i < m_nbElem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            return m_values.Get(i);
        }
    }
    return "/0";
}

TabDynInt DictDynIntString::GetKeys() const
{
    return m_keys;
}

TabDynString DictDynIntString::GetValues() const
{
    return m_values;
}

void DictDynIntString::Set(int key, std::string value)
{
    for (unsigned int i = 0; i < m_nbElem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            m_values.Set(i, value);
            return;
        }
    }
}

std::string DictDynIntString::Pop(int key)
{
    for (int i = 0; i < m_nbElem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            m_keys.Pop(i);
            return m_values.Get(i);
        }
    }
    return "/0";
}

void DictDynIntString::Remove(int key, int num)
{
    if (num < m_nbElem)
    {
//        m_keys.Remove(key, num);
//        m_values.Remove(key, num);
        m_nbElem--;
    }
}

void DictDynIntString::Remove(int key)
{
    for (int i = 0; i < m_nbElem; i++)
    {
        if (m_keys.Get(i) == key)
        {
//            m_keys.Remove(key);
//            m_values.Remove(key);
            return;
        }
    }
}

void DictDynIntString::Remove(int key, bool first)
{
    if (first)
    {
//        Remove(key);
    }
    else
    {
        for (int i = m_nbElem - 1; i >= 0; i--)
        {
            if (m_keys.Get(i) == key)
            {
//                Remove(key, i);
                return;
            }
        }
    }
}

void DictDynIntString::AddAppend(int key, std::string value, bool addition)
{
    if (m_nbElem < m_nbElemMax)
    {
        if (addition)
        {
            for (unsigned int i = 0; i < m_nbElem; i++)
            {
                if (m_keys.Get(i) == key)
                {
//                    m_values[i] += value;
                    return;
                }
            }
        }
        m_keys.Set(m_nbElem - 1, key);
        m_values.Set(m_nbElem - 1, value);
        m_nbElem++;
    }
    else
    {
        std::cout << "Erreur : le tableau est plein" << std::endl;
    }
}

void DictDynIntString::Delete(int i)
{
//    m_keys;
}