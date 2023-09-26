#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string>

/*
* Classe TabDyn
* Classe de base pour les tableaux dynamiques
* Contient le nombre d'éléments et le nombre d'éléments maximum
* Les classes filles contiennent le tableau
* 
* Constructeurs :
* TabDyn() : m_nbElem(0), m_nbElemMax(0)
* TabDyn(unsigned int nbElemMax) : m_nbElem(0), m_nbElemMax(nbElemMax)
* TabDyn(const TabDyn& tabDyn) : m_nbElem(tabDyn.m_nbElem), m_nbElemMax(tabDyn.m_nbElemMax)
* 
* Destructeur :
* ~TabDyn()
* 
* Méthodes :
* void SetParam(bool add_with_multiple, unsigned int addition)
* void Clear()
* 
* Accesseurs :
* unsigned int getNbElem() const
* unsigned int getNbElemMax() const
* 
* Attributs :
* unsigned int m_nbElem;
* unsigned int m_nbElemMax;
* 
* Remarques :
* Les classes filles contiennent le tableau
* 
* Exemple :
* TabDynString tab(10);
* std::cout << tab.getNbElem() << std::endl;
* std::cout << tab.getNbElemMax() << std::endl;
* TabDynString tab2;
* std::cout << tab2.getNbElem() << std::endl;
* std::cout << tab2.getNbElemMax() << std::endl;
* 
* Sortie :
* 0
* 10
* 0
* 0
*/
class TabDyn
{
public :
	TabDyn();
	TabDyn(unsigned int nbElemMax);
	TabDyn(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
	TabDyn(const TabDyn& tabDyn);
	~TabDyn();

	unsigned int GetNbElem() const;
	unsigned int GetNbElemMax() const;
	void SetParam(bool add_with_multiple, unsigned int addition);
	void Clear();

protected :
	unsigned int m_nbElem;
	unsigned int m_nbElemMax;
	bool m_add_with_multiple;
	unsigned int m_addition;
};

/*
* Classe TabDynString
* Classe fille de TabDyn
* Contient un tableau de std::string
* 
* Constructeurs :
* TabDynString()
* TabDynString(unsigned int nbElemMax)
* TabDynString(const TabDynString& tabDynString)
* 
* Destructeur :
* ~TabDynString()
* 
* Méthodes :
* void Append(std::string str)
* void Add(std::string str)
* std::string Get(unsigned int index) const
* std::string* GetTab() const
* void Set(unsigned int index, std::string str)
* 
* Attributs :
* std::string* m_tab;
* 
* Remarques :
* 
* Exemple :
* TabDynString tab(10);
* std::cout << tab.getNbElem() << std::endl;
* std::cout << tab.getNbElemMax() << std::endl;
* TabDynString tab2;
* std::cout << tab2.getNbElem() << std::endl;
* std::cout << tab2.getNbElemMax() << std::endl;
* 
* Sortie :
* 0
* 10
* 0
* 0
*/
class TabDynString : public TabDyn
{
public :
	TabDynString();
	TabDynString(unsigned int nbElemMax);
	TabDynString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
	TabDynString(const TabDynString& tabDynString);
	~TabDynString();

	void Append(std::string str);
	void Add(std::string str);
	std::string Get(unsigned int index) const;
	std::string* GetTab() const;
	void Set(unsigned int index, std::string str);

private :
	void AddAppend(std::string str, bool addition);

	std::string* m_tab;
};

#endif