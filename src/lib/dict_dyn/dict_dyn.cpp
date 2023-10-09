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