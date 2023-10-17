#ifndef DEF_MATIERES_TEMP
#define DEF_MATIERES_TEMP

#include "../tab_dyn/tab_dyn.h"
#include "profs.h"

class Matieres_temp
{
public:
    Matieres_temp();
    Matieres_temp(std::string nom, unsigned int id);
    Matieres_temp(const Matieres_temp& matieres_temp);
    ~Matieres_temp();

    unsigned int GetId();
    std::string GetNom();

    void SetId(unsigned int id);
    void SetNom(std::string nom);

private:
    unsigned int m_id;
    std::string m_nom;
};


#endif
