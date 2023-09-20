#include "import.hpp"

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 		 //on ouvre le fichier en paramètre
		std::string ligne;					 //on génère la variable ligne pour ensuite la remplir
		std::getline(myfile, ligne);	   	 //on prélève la première ligne dans la variable ligne
		std::cout << ligne << std::endl;	 //on renvoie la ligne en console (pour les test, à modifier pour fontion plus avancé)

		return ligne; // on renvoie la première ligne
	}
	else //en cas de problème d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une chaîne vide en cas de problème
	}
}

