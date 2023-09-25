#ifndef DEF_ELEVE
#define DEF_ELEVE

#include <string>
#include <iostream>

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
		std::string getMatiere(unsigned int i) const;

		

		 
	private:
		unsigned int m_id;
		std::string m_prenom;
		std::string m_nom;
		std::string m_niveau_scolaire;
		unsigned int m_nb_matiere;
		unsigned int m_nb_matiere_max;
		std::string* m_matieres;

};

#endif