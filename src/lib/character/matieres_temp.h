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

class TabDynMatieresTemp : public TabDyn
{
public :
    TabDynMatieresTemp();
    TabDynMatieresTemp(unsigned int nb_elem_max);
    TabDynMatieresTemp(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynMatieresTemp(const TabDynMatieresTemp& tab_dyn_ref);
    ~TabDynMatieresTemp();

    void Copy(TabDynMatieresTemp& tab_dyn_ref);
    void Add(MatieresTemp value);
    void Add(MatieresTemp value, bool add_with_multiple);
    MatieresTemp Get(unsigned int index) const;
    MatieresTemp* GetTab() const;
    void Set(unsigned int index, MatieresTemp value);

    MatieresTemp Pop();
    MatieresTemp Pop(int index);
    void Remove(MatieresTemp value, int num);
    void Remove(MatieresTemp value);
    void Remove(MatieresTemp value, bool is_first);

private :
    MatieresTemp* m_tab;
};

/* SPLIT */

/* SPLIT */

#endif