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

private:

    unsigned int m_horaire1;
    unsigned int m_horaire2;
    unsigned int m_id;
    TabDynInt m_horaires_tab;
    std::string m_nom;

};


#endif
