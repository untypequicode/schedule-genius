#ifndef DEF_PROFS
#define DEF_PROFS
#include "../tab_dyn/tab_dyn.h"

class Profs
{
public:
    Profs();
    Profs(unsigned int id, std::string prenom, std::string nom, unsigned int nb_heure);
    Profs(const Profs& profs);
    ~Profs();

    std::string GetPrenom() const;
    std::string GetNom() const;
    unsigned int GetId() const;
    unsigned int GetNbHeure();

    void SetHoraires(unsigned int horaires1, unsigned int horaires2);
    void AddHoraires(unsigned int horaires1, unsigned int horaires2);
    void SetNbHeure(unsigned int nb_heure);
    void SetId(unsigned int id);

private:
    unsigned int m_horaire1;
    unsigned int m_horaire2;
    TabDynInt m_horaires_tab;
    unsigned int m_id;
    std::string m_prenom;
    std::string m_nom;
    unsigned int m_nb_heure;
};


#endif
