#ifndef DEF_ELEVE
#define DEF_ELEVE

#include <iostream>
#include "tab_dyn/tab_dyn.hpp"

class Eleve
{
	public:
		Eleve();
		Eleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire);
		//Eleve(std::string prenom, std::string nom, std::string niveau_scolaire);
		Eleve(const Eleve& eleve);
		~Eleve();

		unsigned int getId() const;
		std::string getPrenom() const;
		std::string getNom() const;
		std::string getNiveauScolaire() const;
		unsigned int getNbMatiere() const;
		unsigned int getNbMatiereMax() const;
		std::string* getMatieres() const;
		void addMatiere(std::string matiere);
		std::string getMatiere(unsigned int i) const;

		

		 
	private:
		unsigned int m_id;
		std::string m_prenom;
		std::string m_nom;
		std::string m_niveau_scolaire;
		TabDynString m_matieres;

};

class TabDynEleve : public TabDyn
{
public:
	TabDynEleve();
	TabDynEleve(unsigned int nbElemMax);
	TabDynEleve(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
	TabDynEleve(const TabDynEleve& tabDynEleve);
	~TabDynEleve();

	void Append(Eleve i);
	void Add(Eleve i);
	Eleve Get(unsigned int index) const;
	Eleve* GetTab() const;
	void Set(unsigned int index, Eleve i);
	Eleve Pop();
	Eleve Pop(int index);
	void Remove(Eleve elem, int num);
	void Remove(Eleve elem);
	void Remove(Eleve elem, bool first);

private:
	void AddAppend(Eleve i, bool addition);

	Eleve* m_tab;
};

#endif