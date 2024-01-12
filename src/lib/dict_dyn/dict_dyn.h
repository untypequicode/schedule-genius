#ifndef DEF_DICT_DYN
#define DEF_DICT_DYN

#include "../tab_dyn/tab_dyn.h"

#include "../outil/comparaison.h"

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
    TabDynChar& GetTabKeys();
    //renvoie le tableau des clés
    TabDynDouble& GetTabValues();
    //renvoie le tableau des valeurs
    void Set(char key, double value);
    //change la valeur associée à la clé

    DictDynCharDouble& FiltreValue(std::string condition, double value, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynCharDouble& FiltreValue(const TabDynString& condition, const TabDynDouble& value, const TabDynString& OrAnd, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynCharDouble& FiltreAndValue(const TabDynString& condition, const TabDynDouble& value, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynCharDouble& FiltreOrValue(const TabDynString& condition, const TabDynDouble& value, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynCharDouble& FiltreKey(std::string condition, char value, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynCharDouble& FiltreKey(const TabDynString& condition, const TabDynChar& value, const TabDynString& OrAnd, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynCharDouble& FiltreAndKey(const TabDynString& condition, const TabDynChar& value, DictDynCharDouble& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynCharDouble& FiltreOrKey(const TabDynString& condition, const TabDynChar& value, DictDynCharDouble& dict_dyn_result);
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
};

DictDynCharDouble& fusion(DictDynCharDouble& dict_dyn_ref, DictDynCharDouble& dict_dyn_ref2, DictDynCharDouble& dict_dyn_result);

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
    TabDynChar& GetTabKeys();
    //renvoie le tableau des clés
    TabDynInt& GetTabValues();
    //renvoie le tableau des valeurs
    void Set(char key, int value);
    //change la valeur associée à la clé

    DictDynCharInt& FiltreValue(std::string condition, int value, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynCharInt& FiltreValue(const TabDynString& condition, const TabDynInt& value, const TabDynString& OrAnd, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynCharInt& FiltreAndValue(const TabDynString& condition, const TabDynInt& value, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynCharInt& FiltreOrValue(const TabDynString& condition, const TabDynInt& value, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynCharInt& FiltreKey(std::string condition, char value, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynCharInt& FiltreKey(const TabDynString& condition, const TabDynChar& value, const TabDynString& OrAnd, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynCharInt& FiltreAndKey(const TabDynString& condition, const TabDynChar& value, DictDynCharInt& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynCharInt& FiltreOrKey(const TabDynString& condition, const TabDynChar& value, DictDynCharInt& dict_dyn_result);
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
};

DictDynCharInt& fusion(DictDynCharInt& dict_dyn_ref, DictDynCharInt& dict_dyn_ref2, DictDynCharInt& dict_dyn_result);



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
    TabDynIntUnsigned& GetTabKeys();
    //renvoie le tableau des clés
    TabDynString& GetTabValues();
    //renvoie le tableau des valeurs
    void Set(int unsigned key, std::string value);
    //change la valeur associée à la clé

    DictDynIntUnsignedString& FiltreValue(std::string condition, std::string value, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynIntUnsignedString& FiltreValue(const TabDynString& condition, const TabDynString& value, const TabDynString& OrAnd, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynIntUnsignedString& FiltreAndValue(const TabDynString& condition, const TabDynString& value, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynIntUnsignedString& FiltreOrValue(const TabDynString& condition, const TabDynString& value, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynIntUnsignedString& FiltreKey(std::string condition, int unsigned value, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynIntUnsignedString& FiltreKey(const TabDynString& condition, const TabDynIntUnsigned& value, const TabDynString& OrAnd, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynIntUnsignedString& FiltreAndKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedString& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynIntUnsignedString& FiltreOrKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedString& dict_dyn_result);
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
};

DictDynIntUnsignedString& fusion(DictDynIntUnsignedString& dict_dyn_ref, DictDynIntUnsignedString& dict_dyn_ref2, DictDynIntUnsignedString& dict_dyn_result);



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
    TabDynIntUnsigned& GetTabKeys();
    //renvoie le tableau des clés
    TabDynFloat& GetTabValues();
    //renvoie le tableau des valeurs
    void Set(int unsigned key, float value);
    //change la valeur associée à la clé

    DictDynIntUnsignedFloat& FiltreValue(std::string condition, float value, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynIntUnsignedFloat& FiltreValue(const TabDynString& condition, const TabDynFloat& value, const TabDynString& OrAnd, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynIntUnsignedFloat& FiltreAndValue(const TabDynString& condition, const TabDynFloat& value, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynIntUnsignedFloat& FiltreOrValue(const TabDynString& condition, const TabDynFloat& value, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynIntUnsignedFloat& FiltreKey(std::string condition, int unsigned value, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynIntUnsignedFloat& FiltreKey(const TabDynString& condition, const TabDynIntUnsigned& value, const TabDynString& OrAnd, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynIntUnsignedFloat& FiltreAndKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedFloat& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynIntUnsignedFloat& FiltreOrKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedFloat& dict_dyn_result);
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
};

DictDynIntUnsignedFloat& fusion(DictDynIntUnsignedFloat& dict_dyn_ref, DictDynIntUnsignedFloat& dict_dyn_ref2, DictDynIntUnsignedFloat& dict_dyn_result);

/* SPLIT */

#endif