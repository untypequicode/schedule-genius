#ifndef DEF_SALLES
#define DEF_SALLES
#include "../tab_dyn/tab_dyn.h"

class Salles
{
public:
    Salles();
    Salles(unsigned int id, std::string nom, unsigned int horaires1, unsigned int horaires2);
    ~Salles();

    std::string GetNom();
    unsigned int GetId();
    TabDynInt GetHoraires();

    void SetHoraires(unsigned int horaires1, unsigned int horaires2);
    void AddHoraires(unsigned int horaires1, unsigned int horaires2);

private:
    TabDynInt m_horaires_tab;
    unsigned int m_id;
    std::string m_nom;
    unsigned int m_horaire1;
    unsigned int m_horaire2;

};


#endif
