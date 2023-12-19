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
            unsigned int niveau_scolaire,
            std::string nom,
            TabDynIntUnsigned prof,
            TabDynIntUnsigned matiere,
            TabDynIntUnsigned salle);
    Groupes(const Groupes& groupes);
    ~Groupes();

    unsigned int GetId() const;
    unsigned int GetNiveauScolaire() const;
    std::string GetNom() const;
    TabDynIntUnsigned GetProf() const;
    TabDynIntUnsigned GetMatiere() const;
    TabDynIntUnsigned GetSalle() const;

    void SetId(unsigned int id);
    void SetNiveauScolaire(unsigned int niveau_scolaire);
    void SetNom(std::string nom);
    void SetProf(TabDynIntUnsigned prof);
    void SetMatiere(TabDynIntUnsigned matiere);
    void SetSalle(TabDynIntUnsigned salle);


private:
    unsigned int m_id;
    unsigned int m_niveau_scolaire;
    std::string m_nom;
    TabDynIntUnsigned m_prof;
    TabDynIntUnsigned m_matiere;
    TabDynIntUnsigned m_salle;

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

/* SPLIT */

#endif