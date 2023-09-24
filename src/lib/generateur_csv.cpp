#include "generateur_csv.hpp"


std::string none_ = "None";

void creerCsv()
{
	int NOMBRE_ELEVE = 200;
	int NOMBRE_PRENOM = PRENOM.size();
	int NOMBRE_NOM = NOM.size();
	int NOMBRE_MATIERE = MATIERE_SPE.size();

	std::ofstream myfile;
	myfile.open("example.csv");

	// Première ligne du csv avec les différentes catégories
	myfile << " PRENOM;" << "NOM;" << "Annee;";
	for (int i = 1; i < 11; i++)
	{
		myfile << "MATIERE OPTIONNELLE" << i << ";";
	};
	myfile << "\n";

	// Autres lignes du csv
	for (int i = 0; i < NOMBRE_ELEVE; i++)
	{
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
	std::cout << "Fini" << std::endl;
}