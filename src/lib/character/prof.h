#ifndef DEF_PROF
#define DEF_PROF
#include "../tab_dyn/tab_dyn.h"

class Prof
{
public:
    Prof();
    Prof(unsigned int id, std::string prenom, std::string nom, unsigned int nb_heure);
    ~Prof();

    std::string GetPrenom() const;
    std::string GetNom() const;
    unsigned int GetId() const;
    unsigned int GetNbHeure();

    void SetNbHeure(unsigned int nb_heure);
    void SetId(unsigned int id);

private:
    unsigned int m_id;
    std::string m_prenom;
    std::string m_nom;
    unsigned int m_nb_heure;
};


#endif
