#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string>

class TabDyn
{
public :
	TabDyn(unsigned int nbElemMax);

private :
	unsigned int m_nbElem;
	unsigned int m_nbElemMax;
};

#endif