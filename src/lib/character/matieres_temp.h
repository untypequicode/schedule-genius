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




/* SPLIT */

/* SPLIT */

#endif