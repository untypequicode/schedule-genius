#ifndef DEF_ELEVE
#define DEF_ELEVE

#include "../dict_dyn/dict_dyn.h"
// inclure les groupes
#include "groupes.h"

class Eleve
{
public:
    Eleve();
    Eleve(unsigned int id,
          std::string prenom,
          std::string nom,
          std::string niveau_scolaire,
          Groupes groupes);
    //Eleve(std::string prenom, std::string nom, std::string niveau_scolaire);
    Eleve(const Eleve& eleve);
    ~Eleve();

    unsigned int GetId() const;
    std::string GetPrenom() const;
    std::string GetNom() const;
    std::string GetNiveauScolaire() const;
    unsigned int GetNbMatiere() const;
    unsigned int GetNbMatiereMax() const;

    void SetEleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire);
    void SetId(unsigned int id);
    void SetPrenom(std::string prenom);
    void SetNom(std::string nom);
    void SetNiveauScolaire(std::string niveau_scolaire);

    void CopyMatiere(TabDynString tab_dyn_ref);
    void SetSecurity(bool security);
    void AddMatiere(std::string value);
    void AddMatiere(std::string value, bool add_with_addition);
    std::string GetMatiere(unsigned int i) const;
    std::string* GetMatieres() const;
    void SetMatiere(unsigned int i, std::string value);
    std::string PopMatiere();
    std::string PopMatiere(int index);
    void RemoveMatiere(std::string value, int num);
    void RemoveMatiere(std::string value);
    void RemoveMatiere(std::string value, bool is_first);



private:
    unsigned int m_id;
    unsigned int m_nb_matiere;
    unsigned int horaire1;
    unsigned int horaire2;
    std::string m_prenom;
    std::string m_nom;
    std::string m_niveau_scolaire;
    TabDynString m_matieres;
    TabDynInt m_horaires;
    Groupes m_groupes;

};

/* SPLIT */

class DictDynIntUnsignedInt : public DictDyn
{
public:
    DictDynIntUnsignedInt();
    DictDynIntUnsignedInt(unsigned int nb_elem_max);
    DictDynIntUnsignedInt(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDynIntUnsignedInt(const DictDynIntUnsignedInt& dict_dyn_ref);
    ~DictDynIntUnsignedInt();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    void SetSecurity(bool security);

    void Copy(DictDynIntUnsignedInt& dict_dyn_ref);
    void Add(int unsigned key, int value);
    void Add(int unsigned key, int value, bool add_with_multiple);
    int Get(int unsigned key) const;
    TabDynIntUnsigned GetTabKeys() const;
    TabDynInt GetTabValues() const;
    void Set(int unsigned key, int value);

    int Pop(int unsigned key);
    void Remove(int value, int num);
    void Remove(int value);
    void Remove(int value, bool is_first);

protected:
    TabDynIntUnsigned m_tab_keys;
    TabDynInt m_tab_values;
};




class DictDynIntUnsignedString : public DictDyn
{
public:
    DictDynIntUnsignedString();
    DictDynIntUnsignedString(unsigned int nb_elem_max);
    DictDynIntUnsignedString(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDynIntUnsignedString(const DictDynIntUnsignedString& dict_dyn_ref);
    ~DictDynIntUnsignedString();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    void SetSecurity(bool security);

    void Copy(DictDynIntUnsignedString& dict_dyn_ref);
    void Add(int unsigned key, std::string value);
    void Add(int unsigned key, std::string value, bool add_with_multiple);
    std::string Get(int unsigned key) const;
    TabDynIntUnsigned GetTabKeys() const;
    TabDynString GetTabValues() const;
    void Set(int unsigned key, std::string value);

    std::string Pop(int unsigned key);
    void Remove(std::string value, int num);
    void Remove(std::string value);
    void Remove(std::string value, bool is_first);

protected:
    TabDynIntUnsigned m_tab_keys;
    TabDynString m_tab_values;
};



/* SPLIT */

#endif