#ifndef DEF_MATIERES
#define DEF_MATIERES

#include "../tab_dyn/tab_dyn.h"

class Matieres
{
public:
    Matieres();
    Matieres(unsigned int id,
             unsigned int nb_heure,
             unsigned int niveau_scolaire,
             std::string nom);
    Matieres(const Matieres& matieres);
    ~Matieres();

private:
    unsigned int m_id;
    unsigned int m_nb_heure;
    unsigned int m_niveau_scolaire;
    std::string m_nom;


/* SPLIT */

class TabDynMatieres : public TabDyn
{
public :
    TabDynMatieres();
    TabDynMatieres(unsigned int nb_elem_max);
    TabDynMatieres(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynMatieres(const TabDynMatieres& tab_dyn_ref);
    ~TabDynMatieres();

    void Copy(TabDynMatieres& tab_dyn_ref);
    void Add(Matieres value);
    void Add(Matieres value, bool add_with_multiple);
    Matieres Get(unsigned int index) const;
    Matieres* GetTab() const;
    void Set(unsigned int index, Matieres value);

    Matieres Pop();
    Matieres Pop(int index);
    void Remove(Matieres value, int num);
    void Remove(Matieres value);
    void Remove(Matieres value, bool is_first);

private :
    Matieres* m_tab;
};

/* SPLIT */

/* SPLIT */

#endif