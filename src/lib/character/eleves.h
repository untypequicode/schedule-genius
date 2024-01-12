#ifndef DEF_ELEVE
#define DEF_ELEVE

#include "../dict_dyn/dict_dyn.h"

#include "../outil/comparaison.h"

class Eleve
{
public:
    Eleve();
    Eleve(const Eleve& eleve);
    Eleve(unsigned int id,
          unsigned int annee,
          unsigned int niveau_scolaire,
          std::string prenom,
          std::string nom,
          TabDynIntUnsigned matieres,
          TabDynIntUnsigned groupes);
    //Eleve
    ~Eleve();

    unsigned int GetId() const;
    unsigned int GetAnnee() const;
    unsigned int GetNiveauScolaire() const;
    std::string GetPrenom() const;
    std::string GetNom() const;
    TabDynIntUnsigned GetMatieres() const;
    TabDynIntUnsigned GetGroupes() const;

    void SetId(unsigned int id);
    void SetAnnee(unsigned int annee);
    void SetNiveauScolaire(unsigned int niveau_scolaire);
    void SetPrenom(std::string prenom);
    void SetNom(std::string nom);
    void SetMatieres(TabDynIntUnsigned matieres);
    void SetGroupes(TabDynIntUnsigned groupes);

private:
    unsigned int m_id;
    unsigned int m_annee;
    unsigned int m_niveau_scolaire;
    std::string m_nom;
    std::string m_prenom;
    TabDynIntUnsigned m_matieres;
    TabDynIntUnsigned m_groupes;

};

/* SPLIT */

class TabDynEleve : public TabDyn
{
public :
    TabDynEleve();
    TabDynEleve(unsigned int nb_elem_max);
    TabDynEleve(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynEleve(const TabDynEleve& tab_dyn_ref);
    ~TabDynEleve();

    void Copy(TabDynEleve& tab_dyn_ref);
    void Add(Eleve value);
    void Add(Eleve value, bool add_with_multiple);
    Eleve Get(unsigned int index) const;
    Eleve* GetTab() const;
    void Set(unsigned int index, Eleve value);

    Eleve Pop();
    Eleve Pop(int index);
    void Remove(Eleve value, int num);
    void Remove(Eleve value);
    void Remove(Eleve value, bool is_first);

private :
    Eleve* m_tab;
};

/* SPLIT */

class DictDynIntUnsignedEleve : public DictDyn
{
public:
    DictDynIntUnsignedEleve();
    //crée un dictionnaire vide
    DictDynIntUnsignedEleve(unsigned int nb_elem_max);
    //crée un dictionnaire vide avec une taille
    DictDynIntUnsignedEleve(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    //crée un dictionnaire vide avec une taille et des paramètres
    DictDynIntUnsignedEleve(const DictDynIntUnsignedEleve& dict_dyn_ref);
    //crée un dictionnaire à partir d'un autre dictionnaire
    ~DictDynIntUnsignedEleve();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    //change les paramètres du dictionnaire
    void SetSecurity(bool security);
    //change le paramètre de sécurité du dictionnaire (pour destruction) attention aux faille de sécurité

    unsigned int GetNbElem() const;
    unsigned int GetNbElemMax() const;
    void Clear();
    void Clear(bool save_tab_memory);

    void Copy(DictDynIntUnsignedEleve& dict_dyn_ref);
    //copie un dictionnaire dans un autre
    void Add(int unsigned key, Eleve value);
    //ajoute un couple key : value au dictionnaire
    void Add(int unsigned key, Eleve value, bool add_with_multiple);
    //ajoute un couple key : value au dictionnaire avec des paramètres
    Eleve Get(int unsigned key) const;
    //renvoie la valeur associée à la clé
    TabDynIntUnsigned& GetTabKeys();
    //renvoie le tableau des clés
    TabDynEleve& GetTabValues();
    //renvoie le tableau des valeurs
    void Set(int unsigned key, Eleve value);
    //change la valeur associée à la clé

    DictDynIntUnsignedEleve& FiltreValue(std::string condition, Eleve value, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la valeur
    DictDynIntUnsignedEleve& FiltreValue(const TabDynString& condition, const TabDynEleve& value, const TabDynString& OrAnd, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la valeur
    DictDynIntUnsignedEleve& FiltreAndValue(const TabDynString& condition, const TabDynEleve& value, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte toutes les conditions
    DictDynIntUnsignedEleve& FiltreOrValue(const TabDynString& condition, const TabDynEleve& value, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les valeur respecte au moins une des conditions
    DictDynIntUnsignedEleve& FiltreKey(std::string condition, int unsigned value, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré selon une condition sur la clé
    DictDynIntUnsignedEleve& FiltreKey(const TabDynString& condition, const TabDynIntUnsigned& value, const TabDynString& OrAnd, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré selon plusieurs conditions sur la clé
    DictDynIntUnsignedEleve& FiltreAndKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les clés respecte toutes les conditions
    DictDynIntUnsignedEleve& FiltreOrKey(const TabDynString& condition, const TabDynIntUnsigned& value, DictDynIntUnsignedEleve& dict_dyn_result);
    // renvoie un dictionnaire filtré dont les clés respecte au moins une des conditions

    Eleve Pop(int unsigned key);
    void Remove(Eleve value, int num);
    void Remove(Eleve value);
    void Remove(Eleve value, bool is_first);

    bool IfKey(int unsigned key, std::string condition, int unsigned value);
    // renvoie si la clé respecte la condition
    bool IfValue(int unsigned key, std::string condition, Eleve value);
    // renvoie si la valeur respecte la condition

protected:
    TabDynIntUnsigned m_tab_keys;
    TabDynEleve m_tab_values;
};

DictDynIntUnsignedEleve& fusion(DictDynIntUnsignedEleve& dict_dyn_ref, DictDynIntUnsignedEleve& dict_dyn_ref2, DictDynIntUnsignedEleve& dict_dyn_result);
DictDynIntUnsignedEleve& fusionSort(DictDynIntUnsignedEleve& dict_dyn_ref, DictDynIntUnsignedEleve& dict_dyn_ref2, DictDynIntUnsignedEleve& dict_dyn_result);

/* SPLIT */

#endif