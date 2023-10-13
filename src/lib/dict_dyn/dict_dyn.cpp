#include "dict_dyn.h"

DictDynIntString::DictDynIntString()
    : TabDyn()
{

}

DictDynIntString::DictDynIntString(unsigned int nbElemMax)
    : TabDyn(nbElemMax),
      m_keys(new int[nbElemMax]),
      m_values(new std::string[nbElemMax])
{

}

DictDynIntString::DictDynIntString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
    : TabDyn(nbElemMax, add_with_multiple, addition),
      m_keys(new int[nbElemMax]),
      m_values(new std::string[nbElemMax])
{

}

DictDynIntString::DictDynIntString(const DictDynIntString &dictDynIntString)
    : TabDyn(dictDynIntString),
        m_keys(new int[dictDynIntString.m_nbElemMax]),
        m_values(new std::string[dictDynIntString.m_nbElemMax])
{

}

DictDynIntString::~DictDynIntString()
{
    if (m_security)
    {
        if (m_keys != nullptr)
        {
            delete[] m_keys;
        }
        if (m_values != nullptr)
        {
            delete[] m_values;
        }
    }
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
        if (m_keys[i] == key)
        {
            return m_values[i];
        }
    }
    return "/0";
}

int* DictDynIntString::GetKeys() const
{
    return m_keys;
}

std::string* DictDynIntString::GetValues() const
{
    return m_values;
}

void DictDynIntString::Set(int key, std::string value)
{
    for (unsigned int i = 0; i < m_nbElem; i++)
    {
        if (m_keys[i] == key)
        {
            m_values[i] = value;
            return;
        }
    }
}

std::string DictDynIntString::Pop(int key)
{
    for (int i = 0; i < m_nbElem; i++)
    {
        if (m_keys[i] == key)
        {
            //m_keys.Pop(i);
            std::string value = m_values[i];
            Remove(key, i);
            return value;
        }
    }
    return "/0";
}

void DictDynIntString::Remove(int key, int num)
{
    if (num < m_nbElem)
    {
        for (unsigned int i = num; i < m_nbElem - 1; i++)
        {
            m_keys[i] = m_keys[i + 1];
            m_values[i] = m_values[i + 1];
        }
        m_nbElem--;
    }
}

void DictDynIntString::Remove(int key)
{
    for (int i = 0; i < m_nbElem; i++)
    {
        if (m_keys[i] == key)
        {
            Remove(key, i);
            return;
        }
    }
}

void DictDynIntString::Remove(int key, bool first)
{
    if (first)
    {
        Remove(key);
    }
    else
    {
        for (int i = m_nbElem - 1; i >= 0; i--)
        {
            if (m_keys[i] == key)
            {
                Remove(key, i);
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
                if (m_keys[i] == key)
                {
                    m_values[i] += value;
                    return;
                }
            }
        }
        m_keys[m_nbElem] = key;
        m_values[m_nbElem] = value;
        m_nbElem++;
    }
    else
    {
        std::cout << "Erreur : le tableau est plein" << std::endl;
    }
}