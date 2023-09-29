#include "generateur_csv.hpp"

TabDynString Prenom;
TabDynString Nom;
TabDynString MatiereSpe;
void begin()
{
	Prenom.Add("Alice");
	Nom.Add("Dupont");
	MatiereSpe.Add("Francais");
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

int NOMBRE_ELEVE = 1000;
int NOMBRE_PRENOM = Prenom.GetNbElem();
int NOMBRE_NOM = Nom.GetNbElem();
int NOMBRE_MATIERE = MatiereSpe.GetNbElem();
int ID_ELEVE = 00000;
void creerCsv()
{
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
	for (int i = 0; i < NOMBRE_ELEVE; i++)
	{
		myfile << ID_ELEVE << ";";
		ID_ELEVE += 1;
		myfile << Prenom.Get(rand() % NOMBRE_PRENOM) << ";";
		myfile << Nom.Get(rand() % NOMBRE_NOM) << ";";
		myfile << rand() % 3 + 1 << ";";

		int NOMBRE_MATIERE_SPE = rand() % MatiereSpe.GetNbElem();
		TabDynString MatiereRestante(MatiereSpe);
		for (int e = 0; e < NOMBRE_MATIERE_SPE; e++)

		{
			int RANDOM_MATIERE = rand() % 5;
			myfile << MatiereRestante.Pop(e) << ";";
		};
		myfile << "\n";
	}
	myfile.close();
}