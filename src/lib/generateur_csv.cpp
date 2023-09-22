#include "generateur_csv.hpp"

void creerCsv()
{

	int NOMBRE_ELEVE = 200;
	int NOMBRE_PRENOM = PRENOM->size();
	int NOMBRE_NOM = NOM->size();
	int NOMBRE_MATIERE = MATIERE_SPE->size();

	std::ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << MATIERE_SPE[i];
	};
	for (int i = 0; i < NOMBRE_ELEVE; i++)
	{
		myfile << PRENOM[rand() % NOMBRE_PRENOM] << ";";
		myfile << NOM[rand() % NOMBRE_NOM] << ";" << "\n";
		for (int e = 0; e < NOMBRE_MATIERE; e++)

		{

		};
	}
	myfile.close();
	std::cout << "Fini" << std::endl;
}