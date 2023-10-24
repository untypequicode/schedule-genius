#ifndef DEF_PROFS
#define DEF_PROFS
#include "../tab_dyn/tab_dyn.h"

class Profs
{
public:
    Profs();
    Profs(unsigned int id,
          std::string prenom,
          std::string nom,
          unsigned int nb_heure,
          unsigned int horaires1,
          unsigned int horaires2);
    Profs(const Profs& profs);
    ~Profs();

    std::string GetPrenom() const;
    std::string GetNom() const;
    unsigned int GetId() const;
    unsigned int GetNbHeure();
    TabDynInt GetHoraires();

    void SetHoraires(unsigned int horaires1,
                     unsigned int horaires2);
    void AddHoraires(unsigned int horaires1,
                     unsigned int horaires2);
    void SetNbHeure(unsigned int nb_heure);
    void SetId(unsigned int id);

private:
    unsigned int m_horaire1;
    unsigned int m_horaire2;
    unsigned int m_nb_heure;
    unsigned int m_id;
    TabDynInt m_horaires_tab;
    std::string m_prenom;
    std::string m_nom;
};

/* SPLIT */

class TabDynProfs : public TabDyn
{
public :
    TabDynProfs();
    TabDynProfs(unsigned int nb_elem_max);
    TabDynProfs(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynProfs(const TabDynProfs& tab_dyn_ref);
    ~TabDynProfs();

    void Copy(TabDynProfs& tab_dyn_ref);
    void Add(Profs value);
    void Add(Profs value, bool add_with_multiple);
    Profs Get(unsigned int index) const;
    Profs* GetTab() const;
    void Set(unsigned int index, Profs value);

    Profs Pop();
    Profs Pop(int index);
    void Remove(Profs value, int num);
    void Remove(Profs value);
    void Remove(Profs value, bool is_first);

private :
    Profs* m_tab;
};


/* SPLIT */

#endif