#ifndef DEF_GROUPES
#define DEF_GROUPES

#include "../tab_dyn/tab_dyn.h"
#include "profs.h"
#include "matieres_temp.h"
#include "salles.h"

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
    unsigned int GetNiveauScolaire();

    std::string GetNom();

    TabDynString GetMatiere();
    TabDynInt GetHoraire();

    Profs GetProf();

    void SetId(unsigned int id);
    void SetNom(std::string nom);
    void SetMatiere(TabDynString matiere);
    void SetHoraire(TabDynInt horaire);
    void SetProf(Profs prof);
    void SetNiveauScolaire(unsigned int niveau_scolaire);

private:
    unsigned int m_id;
    unsigned int m_niveau_scolaire;
    std::string m_nom;
    TabDynString m_matiere;
    TabDynInt m_horaire;
    Profs m_prof;
    MatieresTemp m_matiere_temp;
    Salles m_salle;
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