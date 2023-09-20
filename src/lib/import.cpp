#include "import.hpp"

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 		  //on ouvre le fichier en paramètre
		std::string ligne1;					  //on génère la variable ligne pour ensuite la remplir
		std::getline(myfile, ligne1);	    	 //on prélève la première ligne dans la variable ligne
		std::string ligne2;					  //idem
		std::getline(myfile, ligne2);
		std::cout << ligne1 << std::endl;	  //on écrit la ligne en console (pour les test, à modifier pour fontion plus avancé)
		std::cout << ligne2 << std::endl;	  //comme précédemment avec la deuxième ligne

		std::string ligne = ligne1 + ligne2;//on entre les deux lignes dans la même variable pour un renvoie propre
		return ligne; // on renvoie la première ligne
	}
	else //en cas de problème d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une chaîne vide en cas de problème
	}
}

