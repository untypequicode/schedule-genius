#ifndef DEF_GROUPES
#define DEF_GROUPES

#include "../tab_dyn/tab_dyn.h"
#include "profs.h"

class Groupes
{
public:
    Groupes();
    Groupes(unsigned int id,
            std::string nom,
            TabDynString matiere,
            TabDynInt horaire,
            Profs prof,
            unsigned int niveau_scolaire);
    ~Groupes();

    unsigned int GetId();
    std::string GetNom();
    TabDynString GetMatiere();
    TabDynInt GetHoraire();
    Profs GetProf();
    unsigned int GetNiveauScolaire();

private:
    unsigned int m_id;
    std::string m_nom;
    TabDynString m_matiere;
    TabDynInt m_horaire;
    Profs m_prof;
    unsigned int m_niveau_scolaire;
};


#endif