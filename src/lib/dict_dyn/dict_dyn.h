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
    //crée un dictionnaire vide
    DictDynCharDouble(unsigned int nb_elem_max);
    //crée un dictionnaire vide avec une taille
    DictDynCharDouble(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    //crée un dictionnaire vide avec une taille et des paramètres
    DictDynCharDouble(const DictDynCharDouble& dict_dyn_ref);
    //crée un dictionnaire à partir d'un autre dictionnaire

    ~DictDynCharDouble();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    //change les paramètres du dictionnaire
    void SetSecurity(bool security);
    //change le paramètre de sécurité du dictionnaire (pour destruction) attention aux faille de sécurité

    void Copy(DictDynCharDouble& dict_dyn_ref);
    //copie un dictionnaire dans un autre
    void Add(char key, double value);
    //ajoute un couple key : value au dictionnaire
    void Add(char key, double value, bool add_with_multiple);
    //ajoute un couple key : value au dictionnaire avec des paramètres
    double Get(char key) const;
    //renvoie la valeur associée à la clé
    TabDynChar GetTabKeys() const;
    //renvoie le tableau des clés
    TabDynDouble GetTabValues() const;
    //renvoie le tableau des valeurs
    void Set(char key, double value);
    //change la valeur associée à la clé

    DictDynCharDouble FiltreValue(std::string condition, double value);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynCharDouble FiltreValue(TabDynString condition, TabDynDouble value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynCharDouble FiltreAndValue(TabDynString condition, TabDynDouble value);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynCharDouble FiltreOrValue(TabDynString condition, TabDynDouble value);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynCharDouble FiltreKey(std::string condition, char value);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynCharDouble FiltreKey(TabDynString condition, TabDynChar value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynCharDouble FiltreAndKey(TabDynString condition, TabDynChar value);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynCharDouble FiltreOrKey(TabDynString condition, TabDynChar value);
    // renvoie un dictionnaire filtré dont les clés respecte au moins une des conditions

    double Pop(char key);
    void Remove(double value, int num);
    void Remove(double value);
    void Remove(double value, bool is_first);

    bool IfKey(char cle, std::string condition, char value);
    // renvoie si la clé respecte la condition
    bool IfValue(char cle, std::string condition, double value);
    // renvoie si la valeur respecte la condition

protected:
    TabDynChar m_tab_keys;
    TabDynDouble m_tab_values;
    bool IfValue(unsigned int index, std::string condition, double value);
    bool IfKey(unsigned int index, std::string condition, char value);
};
DictDynCharDouble fusion(DictDynCharDouble dict_dyn_ref, DictDynCharDouble dict_dyn_ref2);

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