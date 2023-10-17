#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string>
#include <iostream>

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
    void Clear(bool save_tab_memory);
    void SetSecurity(bool security);

protected :
    unsigned int m_nbElem;
    unsigned int m_nbElemMax;
    bool m_add_with_multiple;
    unsigned int m_addition;
    bool m_security;
};

/* SPLIT */


class TabDynChar : public TabDyn
{
public :
    TabDynChar();
    TabDynChar(unsigned int nbElemMax);
    TabDynChar(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
    TabDynChar(const TabDynChar& tabDynChar);
    ~TabDynChar();

    void Copy(TabDynChar tab_ref);
    void Append(char c);
    void Add(char c);
    char Get(unsigned int index) const;
    char* GetTab() const;
    void Set(unsigned int index, char c);
    char Pop();
    char Pop(int index);
    void Remove(char elem, int num);
    void Remove(char elem);
    void Remove(char elem, bool first);

private :
    void AddAppend(char c, bool addition);

    char* m_tab;
};

/* SPLIT */
/* SPLIT */


#endif