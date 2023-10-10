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