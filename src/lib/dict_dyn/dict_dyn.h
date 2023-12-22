#ifndef DEF_DICT_DYN
#define DEF_DICT_DYN

#include "../tab_dyn/tab_dyn.h"

//#include "../outil/comparaison.h"

class DictDyn
{
public:
    DictDyn();
    DictDyn(unsigned int nb_elem_max);
    DictDyn(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDyn(const DictDyn& dict_dyn);
    ~DictDyn();
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

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void Clear();
    void Clear(bool save_tab_memory);

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

    bool IfKey(char key, std::string condition, char value);
    // renvoie si la clé respecte la condition
    bool IfValue(char key, std::string condition, double value);
    // renvoie si la valeur respecte la condition

protected:
    TabDynChar m_tab_keys;
    TabDynDouble m_tab_values;

    bool TestIfValue(unsigned int index, std::string condition, double value);
    bool TestIfKey(unsigned int index, std::string condition, char value);
};

DictDynCharDouble fusion(DictDynCharDouble dict_dyn_ref, DictDynCharDouble dict_dyn_ref2);

/* SPLIT */

class DictDynCharInt : public DictDyn
{
public:
    DictDynCharInt();
    //crée un dictionnaire vide
    DictDynCharInt(unsigned int nb_elem_max);
    //crée un dictionnaire vide avec une taille
    DictDynCharInt(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    //crée un dictionnaire vide avec une taille et des paramètres
    DictDynCharInt(const DictDynCharInt& dict_dyn_ref);
    //crée un dictionnaire à partir d'un autre dictionnaire
    ~DictDynCharInt();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    //change les paramètres du dictionnaire
    void SetSecurity(bool security);
    //change le paramètre de sécurité du dictionnaire (pour destruction) attention aux faille de sécurité

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void Clear();
    void Clear(bool save_tab_memory);

    void Copy(DictDynCharInt& dict_dyn_ref);
    //copie un dictionnaire dans un autre
    void Add(char key, int value);
    //ajoute un couple key : value au dictionnaire
    void Add(char key, int value, bool add_with_multiple);
    //ajoute un couple key : value au dictionnaire avec des paramètres
    int Get(char key) const;
    //renvoie la valeur associée à la clé
    TabDynChar GetTabKeys() const;
    //renvoie le tableau des clés
    TabDynInt GetTabValues() const;
    //renvoie le tableau des valeurs
    void Set(char key, int value);
    //change la valeur associée à la clé

    DictDynCharInt FiltreValue(std::string condition, int value);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynCharInt FiltreValue(TabDynString condition, TabDynInt value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynCharInt FiltreAndValue(TabDynString condition, TabDynInt value);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynCharInt FiltreOrValue(TabDynString condition, TabDynInt value);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynCharInt FiltreKey(std::string condition, char value);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynCharInt FiltreKey(TabDynString condition, TabDynChar value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynCharInt FiltreAndKey(TabDynString condition, TabDynChar value);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynCharInt FiltreOrKey(TabDynString condition, TabDynChar value);
    // renvoie un dictionnaire filtré dont les clés respecte au moins une des conditions

    int Pop(char key);
    void Remove(int value, int num);
    void Remove(int value);
    void Remove(int value, bool is_first);

    bool IfKey(char key, std::string condition, char value);
    // renvoie si la clé respecte la condition
    bool IfValue(char key, std::string condition, int value);
    // renvoie si la valeur respecte la condition

protected:
    TabDynChar m_tab_keys;
    TabDynInt m_tab_values;

    bool TestIfValue(unsigned int index, std::string condition, int value);
    bool TestIfKey(unsigned int index, std::string condition, char value);
};

DictDynCharInt fusion(DictDynCharInt dict_dyn_ref, DictDynCharInt dict_dyn_ref2);



class DictDynIntUnsignedString : public DictDyn
{
public:
    DictDynIntUnsignedString();
    //crée un dictionnaire vide
    DictDynIntUnsignedString(unsigned int nb_elem_max);
    //crée un dictionnaire vide avec une taille
    DictDynIntUnsignedString(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    //crée un dictionnaire vide avec une taille et des paramètres
    DictDynIntUnsignedString(const DictDynIntUnsignedString& dict_dyn_ref);
    //crée un dictionnaire à partir d'un autre dictionnaire
    ~DictDynIntUnsignedString();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    //change les paramètres du dictionnaire
    void SetSecurity(bool security);
    //change le paramètre de sécurité du dictionnaire (pour destruction) attention aux faille de sécurité

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void Clear();
    void Clear(bool save_tab_memory);

    void Copy(DictDynIntUnsignedString& dict_dyn_ref);
    //copie un dictionnaire dans un autre
    void Add(int unsigned key, std::string value);
    //ajoute un couple key : value au dictionnaire
    void Add(int unsigned key, std::string value, bool add_with_multiple);
    //ajoute un couple key : value au dictionnaire avec des paramètres
    std::string Get(int unsigned key) const;
    //renvoie la valeur associée à la clé
    TabDynIntUnsigned GetTabKeys() const;
    //renvoie le tableau des clés
    TabDynString GetTabValues() const;
    //renvoie le tableau des valeurs
    void Set(int unsigned key, std::string value);
    //change la valeur associée à la clé

    DictDynIntUnsignedString FiltreValue(std::string condition, std::string value);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynIntUnsignedString FiltreValue(TabDynString condition, TabDynString value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynIntUnsignedString FiltreAndValue(TabDynString condition, TabDynString value);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynIntUnsignedString FiltreOrValue(TabDynString condition, TabDynString value);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynIntUnsignedString FiltreKey(std::string condition, int unsigned value);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynIntUnsignedString FiltreKey(TabDynString condition, TabDynIntUnsigned value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynIntUnsignedString FiltreAndKey(TabDynString condition, TabDynIntUnsigned value);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynIntUnsignedString FiltreOrKey(TabDynString condition, TabDynIntUnsigned value);
    // renvoie un dictionnaire filtré dont les clés respecte au moins une des conditions

    std::string Pop(int unsigned key);
    void Remove(std::string value, int num);
    void Remove(std::string value);
    void Remove(std::string value, bool is_first);

    bool IfKey(int unsigned key, std::string condition, int unsigned value);
    // renvoie si la clé respecte la condition
    bool IfValue(int unsigned key, std::string condition, std::string value);
    // renvoie si la valeur respecte la condition

protected:
    TabDynIntUnsigned m_tab_keys;
    TabDynString m_tab_values;

    bool TestIfValue(unsigned int index, std::string condition, std::string value);
    bool TestIfKey(unsigned int index, std::string condition, int unsigned value);
};

DictDynIntUnsignedString fusion(DictDynIntUnsignedString dict_dyn_ref, DictDynIntUnsignedString dict_dyn_ref2);



class DictDynIntUnsignedFloat : public DictDyn
{
public:
    DictDynIntUnsignedFloat();
    //crée un dictionnaire vide
    DictDynIntUnsignedFloat(unsigned int nb_elem_max);
    //crée un dictionnaire vide avec une taille
    DictDynIntUnsignedFloat(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    //crée un dictionnaire vide avec une taille et des paramètres
    DictDynIntUnsignedFloat(const DictDynIntUnsignedFloat& dict_dyn_ref);
    //crée un dictionnaire à partir d'un autre dictionnaire
    ~DictDynIntUnsignedFloat();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    //change les paramètres du dictionnaire
    void SetSecurity(bool security);
    //change le paramètre de sécurité du dictionnaire (pour destruction) attention aux faille de sécurité

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void Clear();
    void Clear(bool save_tab_memory);

    void Copy(DictDynIntUnsignedFloat& dict_dyn_ref);
    //copie un dictionnaire dans un autre
    void Add(int unsigned key, float value);
    //ajoute un couple key : value au dictionnaire
    void Add(int unsigned key, float value, bool add_with_multiple);
    //ajoute un couple key : value au dictionnaire avec des paramètres
    float Get(int unsigned key) const;
    //renvoie la valeur associée à la clé
    TabDynIntUnsigned GetTabKeys() const;
    //renvoie le tableau des clés
    TabDynFloat GetTabValues() const;
    //renvoie le tableau des valeurs
    void Set(int unsigned key, float value);
    //change la valeur associée à la clé

    DictDynIntUnsignedFloat FiltreValue(std::string condition, float value);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynIntUnsignedFloat FiltreValue(TabDynString condition, TabDynFloat value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynIntUnsignedFloat FiltreAndValue(TabDynString condition, TabDynFloat value);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynIntUnsignedFloat FiltreOrValue(TabDynString condition, TabDynFloat value);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynIntUnsignedFloat FiltreKey(std::string condition, int unsigned value);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynIntUnsignedFloat FiltreKey(TabDynString condition, TabDynIntUnsigned value, TabDynString OrAnd);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynIntUnsignedFloat FiltreAndKey(TabDynString condition, TabDynIntUnsigned value);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynIntUnsignedFloat FiltreOrKey(TabDynString condition, TabDynIntUnsigned value);
    // renvoie un dictionnaire filtré dont les clés respecte au moins une des conditions

    float Pop(int unsigned key);
    void Remove(float value, int num);
    void Remove(float value);
    void Remove(float value, bool is_first);

    bool IfKey(int unsigned key, std::string condition, int unsigned value);
    // renvoie si la clé respecte la condition
    bool IfValue(int unsigned key, std::string condition, float value);
    // renvoie si la valeur respecte la condition

protected:
    TabDynIntUnsigned m_tab_keys;
    TabDynFloat m_tab_values;

    bool TestIfValue(unsigned int index, std::string condition, float value);
    bool TestIfKey(unsigned int index, std::string condition, int unsigned value);
};

DictDynIntUnsignedFloat fusion(DictDynIntUnsignedFloat dict_dyn_ref, DictDynIntUnsignedFloat dict_dyn_ref2);

/* SPLIT */

#endif