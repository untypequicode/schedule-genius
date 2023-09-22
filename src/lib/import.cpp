#include "import.hpp"

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en paramètre
		std::string ligne;						 //on génère la variable lignetest pour ensuite la remplir
		std::getline(myfile, ligne);	    	 //on prélève la première ligne dans la variable ligne, elle servira d'identificteur de fin de programme
		std::string lignef = "";
		lignef += ligne + "\n";
		int fusible = 0;
		while ((ligne != "") and (fusible < 0))
		{
//			std::cout << lignef << std::endl;			//on renvoie la partie lu du fichier pour les test
			std::getline(myfile, ligne);				//on donne a la ligne la valeur de la ligne suivante
			lignef += ligne + " \n";					//on ajoute la dernière ligne dans la même variable pour un renvoie propre
			fusible += 1;
		}
		std::cout << lignef << std::endl;		//on renvoie le fichier lu pour les test
		std::cout << fusible << std::endl;
		return lignef;							// on renvoie la première ligne
	}
	else //en cas de problème d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une chaîne vide en cas de problème
	}
}

