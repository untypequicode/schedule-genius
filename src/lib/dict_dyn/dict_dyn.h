#ifndef DEF_DICT_DYN
#define DEF_DICT_DYN

#include "../tab_dyn/tab_dyn.h"

class DictDyn
{
public:
    DictDyn();
    DictDyn(unsigned int nb_elem_max);
    DictDyn(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDyn(const DictDyn& dict_dyn);
    ~DictDyn();

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void Clear();
    void Clear(bool save_tab_memory);

protected:
    unsigned int m_nb_elem;
    unsigned int m_nb_elem_max;
};

/* SPLIT */

class DictDynCharDouble : public DictDyn
{
public:
    DictDynCharDouble();
    DictDynCharDouble(unsigned int nb_elem_max);
    DictDynCharDouble(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDynCharDouble(const DictDynCharDouble& dict_dyn_ref);
    ~DictDynCharDouble();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    void SetSecurity(bool security);

    void Copy(DictDynCharDouble& dict_dyn_ref);
    void Add(char key, double value);
    void Add(char key, double value, bool add_with_multiple);
    double Get(char key) const;
    TabDynChar GetTabKeys() const;
    TabDynDouble GetTabValues() const;
    void Set(char key, double value);

    DictDynCharDouble FiltreElement(std::string condition, double value);
    DictDynCharDouble FiltreKey(std::string condition, char value);

    double Pop(char key);
    void Remove(double value, int num);
    void Remove(double value);
    void Remove(double value, bool is_first);

    bool IfKey(char cle, std::string condition, char value);
    bool IfElement(char cle, std::string condition, double value);

protected:
    TabDynChar m_tab_keys;
    TabDynDouble m_tab_values;
    bool IfElement(unsigned int index, std::string condition, double value);
    bool IfKey(unsigned int index, std::string condition, char value);
};

/* SPLIT */

class DictDynCharInt : public DictDyn
{
public:
    DictDynCharInt();
    DictDynCharInt(unsigned int nb_elem_max);
    DictDynCharInt(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDynCharInt(const DictDynCharInt& dict_dyn_ref);
    ~DictDynCharInt();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    void SetSecurity(bool security);

    void Copy(DictDynCharInt& dict_dyn_ref);
    void Add(char key, int value);
    void Add(char key, int value, bool add_with_multiple);
    int Get(char key) const;
    TabDynChar GetTabKeys() const;
    TabDynInt GetTabValues() const;
    void Set(char key, int value);

    int Pop(char key);
    void Remove(int value, int num);
    void Remove(int value);
    void Remove(int value, bool is_first);

protected:
    TabDynChar m_tab_keys;
    TabDynInt m_tab_values;
};


/* SPLIT */

#endif