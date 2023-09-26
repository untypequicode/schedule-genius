#include "import.hpp"
;
std::string ouvrirFichierParLigne(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en paramètre
		std::string ligne;						 //on génère la variable ligne pour ensuite la remplir
		std::getline(myfile, ligne);	    	 //on prélève la première ligne dans la variable ligne, elle servira d'identificteur de fin de programme
		std::string lignef = "\n";
		int fusible = 0;						 //une précaution de sauvegarde pour ne pas rester bloquer dans la fichier
		int max = 2;
		while ((ligne != "") and (fusible < max))
		{
//			std::cout << lignef << std::endl;			//on renvoie la partie lu du fichier pour les test
			std::getline(myfile, ligne);				//on donne a la ligne la valeur de la ligne suivante
			lignef += ligne + " \n";					//on ajoute la dernière ligne dans la même variable pour un renvoie propre
			fusible += 1;
		}
		//std::cout << lignef << std::endl;		//on renvoie le fichier lu pour les test
		return lignef;							// on renvoie toutes les lignes
	}
	else //en cas de problème d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une chaîne vide en cas de problème
	}
}

std::string ouvrirFichierParMot(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en paramètre
		std::string mot;				     //on génère la variable caractere pour ensuite la remplir
		myfile >> mot;	    			 //on prélève le premier caractere dans la variable caractere, elle servira d'identificteur de fin de programme
		std::string motf = "";
		int fusible = 0;						 //une précaution de sauvegarde pour ne pas rester bloquer dans la fichier
		int max = 2;
		while (fusible < max)
		{
			//std::cout << caractere << std::endl;			//on renvoie la partie lu du fichier pour les test
			myfile >> mot;							//on donne au caractere la valeur du caractere suivant
			if (mot == ";")
			{
				motf += "  ";
			}

			else
			{
				motf += mot;						//on ajoute le dernier caractère dans la même variable pour un renvoie propre
			}

			fusible += 1;
		}
		std::cout << motf << std::endl;		//on renvoie le fichier lu pour les test
		return motf;							// on renvoie la première ligne
	}
	else //en cas de problème d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " ";
		return a;												   //on renvoie une chaîne vide en cas de problème
	}
}

void ouvrirFichierParCaractere(std::string const nom_fichier)
{
	std::string source = ouvrirFichierParLigne(nom_fichier);
	char carac;
	std::string texte = "lecture csv : \n";
	for (char character : source)
	{
		carac = character;
		if (carac == ';')
		{
			texte += '\n';
		}
		else
		{
			texte += carac;
		}
	}
	std::cout << texte;
	return;
}