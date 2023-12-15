#ifndef DEF_SALLES
#define DEF_SALLES
#include "../tab_dyn/tab_dyn.h"

class Salles
{
public:
    Salles();
    Salles(unsigned int id,
           std::string nom,
           unsigned int horaires1,
           unsigned int horaires2);
    Salles(const Salles& salles);
    ~Salles();

    std::string GetNom();

    unsigned int GetId();

    TabDynInt GetHoraires();

    void SetHoraires(unsigned int horaires1,
                     unsigned int horaires2);
    void AddHoraires(unsigned int horaires1,
                     unsigned int horaires2);
    void SetNom(std::string nom);

private:

    unsigned int m_horaire1;
    unsigned int m_horaire2;
    unsigned int m_id;
    TabDynInt m_horaires_tab;
    std::string m_nom;

};

/* SPLIT */

class TabDynSalles : public TabDyn
{
public :
    TabDynSalles();
    TabDynSalles(unsigned int nb_elem_max);
    TabDynSalles(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynSalles(const TabDynSalles& tab_dyn_ref);
    ~TabDynSalles();

    void Copy(TabDynSalles& tab_dyn_ref);
    void Add(Salles value);
    void Add(Salles value, bool add_with_multiple);
    Salles Get(unsigned int index) const;
    Salles* GetTab() const;
    void Set(unsigned int index, Salles value);

    Salles Pop();
    Salles Pop(int index);
    void Remove(Salles value, int num);
    void Remove(Salles value);
    void Remove(Salles value, bool is_first);

private :
    Salles* m_tab;
};

/* SPLIT */


/* SPLIT */

#endif