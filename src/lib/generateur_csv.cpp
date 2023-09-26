#include "generateur_csv.hpp"

std::array <std::string,26> const PRENOM = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack",
"Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor",
"Ursula", "Victor", "Wendy", "Xavier", "Yasmine", "Zane" };

std::array <std::string,29> const NOM = {"Dupont", "Martin", "Dubois", "Bernard", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy",
"Moreau", "Simon", "Laurent", "Lefebvre", "Michel", "Garcia", "David", "Roux", "Bonnet", "Fournier",
"Lopez", "Legrand", "Martinez", "Ferreira", "Fernandez", "Blanc", "André", "Leroux", "Rousseau" };

std::vector <std::string> MATIERE_SPE = { "Francais", "Histoire" "Geo", "EMC", "EPS", "SPC", "SVT", "Maths", "NSI", "Philo",
"Anglais", "Espagnole", "Allemand", "Italien", "Russe" };

int NOMBRE_ELEVE = 5675;
int NOMBRE_PRENOM = PRENOM.size();
int NOMBRE_NOM = NOM.size();
int NOMBRE_MATIERE = MATIERE_SPE.size();
int ID_ELEVE = 00000;
void creerCsv()
{
	std::ofstream myfile;
	myfile.open("eleve.csv");

	// Première ligne du csv avec les différentes catégories
	myfile << "ID" << " PRENOM;" << "NOM;" << "Annee;";
	for (int i = 1; i < 11; i++)
	{
		myfile << "MATIERE OPTIONNELLE" << i << ";";
	};
	myfile << "\n";

	// Autres lignes du csv
	for (int i = 0; i < NOMBRE_ELEVE; i++)
	{
		myfile << ID_ELEVE << ";";
		ID_ELEVE += 1;
		myfile << PRENOM[rand() % NOMBRE_PRENOM] << ";";
		myfile << NOM[rand() % NOMBRE_NOM] << ";";
		myfile << rand() % 3 + 1 << ";";

		int NOMBRE_MATIERE_SPE = rand() % 10;

		std::vector <std::string> matiere_restante = MATIERE_SPE;
		for (int e = 0; e < NOMBRE_MATIERE_SPE; e++)

		{
			int RANDOM_MATIERE = rand() % 5;
			myfile << matiere_restante[RANDOM_MATIERE] << ";";
			matiere_restante.erase(matiere_restante.begin() + RANDOM_MATIERE);
		};
		myfile << "\n";
	}
	myfile.close();
}