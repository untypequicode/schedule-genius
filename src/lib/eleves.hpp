#ifndef DEF_ELEVE
#define DEF_ELEVE

#include <string>

class Eleve
{
	public:
		std::string m_prenom;
		std::string m_nom;
		std::string m_niveau;
		int m_quantite_matiere;

		Eleve(std::string prenom, std::string nom, std::string niveau,int quantite_matiere);
		void SetMatiere(std::string matiere, int index);
		std::string GetMatiere(int index);

		~Eleve();

	private:
		std::string* m_matieres;
		//* m_groupes;
		//* m_horaires;
};

#endif