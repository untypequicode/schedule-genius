#ifndef DEF_MATIERES
#define DEF_MATIERES

#include "../tab_dyn/tab_dyn.h"

class Matieres
{
public:
    Matieres();
    Matieres(std::string nom, unsigned int id,unsigned int nb_heure);
    Matieres(const Matieres& matieres);
    ~Matieres();

    std::string GetNom();
    unsigned int GetId();
    unsigned int GetNbHeure();

    void SetNbHeure(unsigned int nb_heure);
    void SetNom(std::string nom);
    void SetId(unsigned int id);

private:
    std::string m_nom;
    unsigned int m_id;
    unsigned int m_nb_heure;
};

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

#endif