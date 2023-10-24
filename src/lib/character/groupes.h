#ifndef DEF_GROUPES
#define DEF_GROUPES

#include "../tab_dyn/tab_dyn.h"
#include "profs.h"

class Groupes
{
public:
    Groupes();
    Groupes(unsigned int id,
            std::string nom,
            TabDynString matiere,
            TabDynInt horaire,
            Profs prof,
            unsigned int niveau_scolaire);
    Groupes(const Groupes& groupes);
    ~Groupes();

    unsigned int GetId();
    std::string GetNom();
    TabDynString GetMatiere();
    TabDynInt GetHoraire();
    Profs GetProf();
    unsigned int GetNiveauScolaire();

private:
    unsigned int m_id;
    std::string m_nom;
    TabDynString m_matiere;
    TabDynInt m_horaire;
    Profs m_prof;
    unsigned int m_niveau_scolaire;
};

/* SPLIT */

class TabDynGroupes : public TabDyn
{
public :
    TabDynGroupes();
    TabDynGroupes(unsigned int nb_elem_max);
    TabDynGroupes(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynGroupes(const TabDynGroupes& tab_dyn_ref);
    ~TabDynGroupes();

    void Copy(TabDynGroupes& tab_dyn_ref);
    void Add(Groupes value);
    void Add(Groupes value, bool add_with_multiple);
    Groupes Get(unsigned int index) const;
    Groupes* GetTab() const;
    void Set(unsigned int index, Groupes value);

    Groupes Pop();
    Groupes Pop(int index);
    void Remove(Groupes value, int num);
    void Remove(Groupes value);
    void Remove(Groupes value, bool is_first);

private :
    Groupes* m_tab;
};


/* SPLIT */

#endif