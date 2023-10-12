#ifndef DEF_MATIERES
#define DEF_MATIERES

#include "../tab_dyn/tab_dyn.h"

class Matieres
{
public:
    Matieres();
    Matieres(std::string nom, unsigned int id,unsigned int nb_heure);
    ~Matieres();

    std::string GetNom();
    unsigned int GetId();
    unsigned int GetNbHeure();

    void SetNbHeure(unsigned int nb_heure);

private:
    std::string m_nom;
    unsigned int m_id;
    unsigned int m_nb_heure;
};


#endif
