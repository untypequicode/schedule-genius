#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string.h>
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
    TabDyn(unsigned int nb_elem_max);
    TabDyn(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDyn(const TabDyn& tab_dyn);
    ~TabDyn();

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void SetParam(bool add_with_multiple, unsigned int number_addition);
    void Clear();
    void Clear(bool save_tab_memory);
    void SetSecurity(bool security);

protected :
    unsigned int m_nb_elem;
    unsigned int m_nb_elem_max;
    bool m_add_with_multiple;
    unsigned int m_number_addition;
    bool m_security;
};

/* SPLIT */

class TabDynChar : public TabDyn
{
public :
    TabDynChar();
    TabDynChar(unsigned int nb_elem_max);
    TabDynChar(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynChar(const TabDynChar& tab_dyn_ref);
    ~TabDynChar();

    void Copy(TabDynChar& tab_dyn_ref);
    void Add(char value);
    void Add(char value, bool add_with_multiple);
    char Get(unsigned int index) const;
    char* GetTab() const;
    void Set(unsigned int index, char value);

    char Pop();
    char Pop(int index);
    void Remove(char value, int num);
    void Remove(char value);
    void Remove(char value, bool is_first);

private :
    char* m_tab;
};

/* SPLIT */

class TabDynString : public TabDyn
{
public :
    TabDynString();
    TabDynString(unsigned int nb_elem_max);
    TabDynString(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynString(const TabDynString& tab_dyn_ref);
    ~TabDynString();

    void Copy(TabDynString& tab_dyn_ref);
    void Add(std::string value);
    void Add(std::string value, bool add_with_multiple);
    std::string Get(unsigned int index) const;
    std::string* GetTab() const;
    void Set(unsigned int index, std::string value);

    std::string Pop();
    std::string Pop(int index);
    void Remove(std::string value, int num);
    void Remove(std::string value);
    void Remove(std::string value, bool is_first);

private :
    std::string* m_tab;
};



class TabDynDouble : public TabDyn
{
public :
    TabDynDouble();
    TabDynDouble(unsigned int nb_elem_max);
    TabDynDouble(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynDouble(const TabDynDouble& tab_dyn_ref);
    ~TabDynDouble();

    void Copy(TabDynDouble& tab_dyn_ref);
    void Add(double value);
    void Add(double value, bool add_with_multiple);
    double Get(unsigned int index) const;
    double* GetTab() const;
    void Set(unsigned int index, double value);

    double Pop();
    double Pop(int index);
    void Remove(double value, int num);
    void Remove(double value);
    void Remove(double value, bool is_first);

private :
    double* m_tab;
};



class TabDynIntUnsigned : public TabDyn
{
public :
    TabDynIntUnsigned();
    TabDynIntUnsigned(unsigned int nb_elem_max);
    TabDynIntUnsigned(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynIntUnsigned(const TabDynIntUnsigned& tab_dyn_ref);
    ~TabDynIntUnsigned();

    void Copy(TabDynIntUnsigned& tab_dyn_ref);
    void Add(int unsigned value);
    void Add(int unsigned value, bool add_with_multiple);
    int unsigned Get(unsigned int index) const;
    int unsigned* GetTab() const;
    void Set(unsigned int index, int unsigned value);

    int unsigned Pop();
    int unsigned Pop(int index);
    void Remove(int unsigned value, int num);
    void Remove(int unsigned value);
    void Remove(int unsigned value, bool is_first);

private :
    int unsigned* m_tab;
};



class TabDynInt : public TabDyn
{
public :
    TabDynInt();
    TabDynInt(unsigned int nb_elem_max);
    TabDynInt(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynInt(const TabDynInt& tab_dyn_ref);
    ~TabDynInt();

    void Copy(TabDynInt& tab_dyn_ref);
    void Add(int value);
    void Add(int value, bool add_with_multiple);
    int Get(unsigned int index) const;
    int* GetTab() const;
    void Set(unsigned int index, int value);

    int Pop();
    int Pop(int index);
    void Remove(int value, int num);
    void Remove(int value);
    void Remove(int value, bool is_first);

private :
    int* m_tab;
};



class TabDynFloat : public TabDyn
{
public :
    TabDynFloat();
    TabDynFloat(unsigned int nb_elem_max);
    TabDynFloat(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynFloat(const TabDynFloat& tab_dyn_ref);
    ~TabDynFloat();

    void Copy(TabDynFloat& tab_dyn_ref);
    void Add(float value);
    void Add(float value, bool add_with_multiple);
    float Get(unsigned int index) const;
    float* GetTab() const;
    void Set(unsigned int index, float value);

    float Pop();
    float Pop(int index);
    void Remove(float value, int num);
    void Remove(float value);
    void Remove(float value, bool is_first);

private :
    float* m_tab;
};

/* SPLIT */

#endif