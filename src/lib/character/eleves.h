#ifndef DEF_ELEVE
#define DEF_ELEVE

#include "../tab_dyn/tab_dyn.h"

class Eleve
{
public:
    Eleve();
    Eleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire);
    //Eleve(std::string prenom, std::string nom, std::string niveau_scolaire);
    Eleve(const Eleve& eleve);
    ~Eleve();

    unsigned int GetId() const;
    std::string GetPrenom() const;
    std::string GetNom() const;
    std::string GetNiveauScolaire() const;
    unsigned int GetNbMatiere() const;
    unsigned int GetNbMatiereMax() const;
    std::string* GetMatieres() const;
    std::string GetMatiere(unsigned int i) const;

    void SetEleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire);
    void SetId(unsigned int id);
    void SetPrenom(std::string prenom);
    void SetNom(std::string nom);
    void SetNiveauScolaire(std::string niveau_scolaire);
    void CopyMatiere(TabDynString tab_ref);
    void SetMatiere(unsigned int i, std::string matiere);
    void AddMatiere(std::string matiere);
    std::string PopMatiere();
    std::string PopMatiere(int index);
    void RemoveMatiere(std::string matiere, int num);
    void RemoveMatiere(std::string matiere);
    void RemoveMatiere(std::string matiere, bool first);



private:
    unsigned int m_id;
    unsigned int m_nb_matiere;
    unsigned int horaire1;
    unsigned int horaire2;
    std::string m_prenom;
    std::string m_nom;
    std::string m_niveau_scolaire;
    TabDynString m_matieres;
    TabDynInt m_horaires;
    Groupes m_groupes;

};

class TabDynEleve : public TabDyn
{
public:
    TabDynEleve();
    TabDynEleve(unsigned int nbElemMax);
    TabDynEleve(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
    TabDynEleve(const TabDynEleve& tabDynEleve);
    ~TabDynEleve();

    void Add(Eleve eleve);
    void Add(Eleve eleve, bool addition);
    Eleve Get(unsigned int index) const;
    Eleve* GetTab() const;
    void Set(unsigned int index, Eleve i);
    Eleve Pop();
    Eleve Pop(int index);
    void Remove(Eleve elem, int num);
    void Remove(Eleve elem);
    void Remove(Eleve elem, bool first);

private:
    Eleve* m_tab;
};

#endif