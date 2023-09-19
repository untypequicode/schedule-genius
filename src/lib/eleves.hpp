#ifndef DEF_ELEVE
#define DEF_ELEVE

#include <string>
#include <iostream>

class Eleve
{
	public:
		std::string m_prenom;
		std::string m_nom;
		std::string m_niveau;
		int m_quantite_matiere;

		Eleve();
		Eleve(std::string prenom, std::string nom, std::string niveau,int quantite_matiere);
		void SetMatiere(std::string matiere, int index);
		std::string GetMatiere(int index);

		~Eleve();

		std::string* m_matieres;
	private:
		
		//* m_groupes;
		//* m_horaires;
};

#endif