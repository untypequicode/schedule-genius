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
            return m_values.Pop(i);
        }
    }
    return "/0";
}

void DictDynIntString::Remove(std::string value, int num)
{
    if (num < m_nbElem)
    {
        int count = 0;
        for (int i = 0; i < m_nbElem; i++) {
            if (m_values.Get(i) == value) {
                count++;
                if (count == num) {
                    m_keys.Pop(i);
                    m_values.Pop(i);
                    return;
                }
            }
        }
    }
}

void DictDynIntString::Remove(std::string value)
{
    for (int i = 0; i < m_nbElem; i++)
    {
        if (m_values.Get(i) == value)
        {
            m_keys.Pop(i);
            m_values.Pop(i);
            i--;
        }
    }
}

void DictDynIntString::Remove(std::string value, bool first)
{
    if (first)
    {
        for (int i = 0; i < m_nbElem; i++)
        {
            if (m_values.Get(i) == value)
            {
                m_keys.Pop(i);
                return;
            }
        }
    }
    else
    {
        for (int i = m_nbElem - 1; i >= 0; i--)
        {
            if (m_values.Get(i) == value)
            {
                m_keys.Pop(i);
                return;
            }
        }
    }
}

void DictDynIntString::AddAppend(int key, std::string value, bool addition)
{
    for (unsigned int i = 0; i < m_nbElem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            m_values.Set(i, value);
            return;
        }
    }
    if (m_nbElem < m_nbElemMax)
    {
        m_values.Set(m_nbElem, value);
        m_keys.Set(m_nbElem, key);
        m_nbElem++;
    }
    else if (m_nbElem == m_nbElemMax)
    {
        if (addition)
        {
            m_keys.Add(key);
            m_values.Add(value);
        }
        else
        {
            m_keys.Append(key);
            m_values.Append(value);
        }
        m_nbElem++;
        m_nbElemMax = m_keys.GetNbElemMax();
    }
}