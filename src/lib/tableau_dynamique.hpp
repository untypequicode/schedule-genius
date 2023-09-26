#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string>

class TabDyn
{
public :
	TabDyn();
	TabDyn(unsigned int nbElemMax);
	~TabDyn();

	unsigned int getNbElem() const;
	unsigned int getNbElemMax() const;

private :
	unsigned int m_nbElem;
	unsigned int m_nbElemMax;
};

#endif