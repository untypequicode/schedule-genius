#ifndef DEF_MATIERES_TEMP
#define DEF_MATIERES_TEMP

#include "../tab_dyn/tab_dyn.h"
#include "profs.h"

class MatieresTemp
{
public:
    MatieresTemp();
    MatieresTemp(std::string nom, unsigned int id);
    MatieresTemp(const MatieresTemp& matieres_temp);
    ~MatieresTemp();

    unsigned int GetId();
    std::string GetNom();

    void SetId(unsigned int id);
    void SetNom(std::string nom);

private:
    unsigned int m_id;
    std::string m_nom;
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

/* SPLIT */

#endif