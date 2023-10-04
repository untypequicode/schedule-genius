#include "generateur_csv.hpp"

CsvGenerateur::CsvGenerateur()
	: CsvGenerateur(200)
{
	
}

CsvGenerateur::CsvGenerateur(unsigned int M_NOMBRE_ELEVE)
	: M_NOMBRE_ELEVE(M_NOMBRE_ELEVE),
	m_id_eleve(0)
{
	m_matiere_spe.SetSecurity(false);
	m_matiere_spe.Add("Francais");
	m_matiere_spe.Add("Anglais");
	m_prenom.SetSecurity(false);
	m_prenom.Add("Alice");
	m_prenom.Add("Antoine");
	m_nom.SetSecurity(false);
	m_nom.Add("Dupont");
	m_nom.Add("Ducon");

	M_NOMBRE_NOM = m_nom.GetNbElem();
	M_NOMBRE_PRENOM = m_prenom.GetNbElem();
	M_NOMBRE_MATIERE_SPE = m_matiere_spe.GetNbElem();
}
CsvGenerateur::~CsvGenerateur()
{
}

//std::string* PRENOM_TEMP[26] = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack",
//"Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor",
//"Ursula", "Victor", "Wendy", "Xavier", "Yasmine", "Zane" };


//std::array <std::string,29> const NOM = {"Dupont", "Martin", "Dubois", "Bernard", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy",
//"Moreau", "Simon", "Laurent", "Lefebvre", "Michel", "Garcia", "David", "Roux", "Bonnet", "Fournier",
//"Lopez", "Legrand", "Martinez", "Ferreira", "Fernandez", "Blanc", "André", "Leroux", "Rousseau" };
//
//std::vector <std::string> MATIERE_SPE = { "Francais", "Histoire" "Geo", "EMC", "EPS", "SPC", "SVT", "Maths", "NSI", "Philo",
//"Anglais", "Espagnole", "Allemand", "Italien", "Russe" };


void CsvGenerateur::creerCsv()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::ofstream myfile;
	myfile.open("eleve.csv");

	// Première ligne du csv avec les différentes catégories
	myfile << "ID;" << " PRENOM;" << "NOM;" << "Annee;";
	for (int i = 1; i < 11; i++)
	{
		myfile << "MATIERE OPTIONNELLE" << i << ";";
	};
	myfile << "\n";

	// Autres lignes du csv
	for (unsigned int i = 0; i < M_NOMBRE_ELEVE; i++)
	{
		myfile << m_id_eleve << ";";
		m_id_eleve++;
		myfile << m_prenom.Get(rand() % M_NOMBRE_PRENOM) << ";";
		myfile << m_nom.Get(rand() % M_NOMBRE_NOM) << ";";
		myfile << rand() % 3 + 1 << ";";

		NOMBRE_MATIERE_SPE = rand() % m_matiere_spe.GetNbElem();
		TabDynString m_matiere_restante(m_matiere_spe);
		for (unsigned int e = 0; e < NOMBRE_MATIERE_SPE +1; e++)

		{
			unsigned int RANDOM_MATIERE = rand() % m_matiere_restante.GetNbElem();
			myfile << m_matiere_restante.Pop(RANDOM_MATIERE) << ";";
		};
		myfile << "\n";
	}
	myfile.close();
}
