#ifndef DEF_GROUPES
#define DEF_GROUPES

#include "../tab_dyn/tab_dyn.h"
#include "profs.h"
#include "matieres_temp.h"
#include "salles.h"

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
    Groupes(const Groupes& groupes);
    ~Groupes();

    unsigned int GetId();
    unsigned int GetNiveauScolaire();

    std::string GetNom();

    TabDynString GetMatiere();
    TabDynInt GetHoraire();

    Profs GetProf();

    void SetId(unsigned int id);
    void SetNom(std::string nom);
    void SetMatiere(TabDynString matiere);
    void SetHoraire(TabDynInt horaire);
    void SetProf(Profs prof);
    void SetNiveauScolaire(unsigned int niveau_scolaire);

private:
    unsigned int m_id;
    unsigned int m_niveau_scolaire;
    std::string m_nom;
    TabDynString m_matiere;
    TabDynInt m_horaire;
    Profs m_prof;
    Matieres_temp m_matiere_temp;
    Salles m_salle;
};


#endif