#include "import.h"

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
        int max = 2500;
        while (fusible < max)
        {
            //std::cout << lignef << std::endl;			//on renvoie la partie lu du fichier pour les test
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
        int max = 2000;
        while (fusible < max)
        {
            //std::cout << caractere << std::endl;			//on renvoie la partie lu du fichier pour les test
            myfile >> mot;							//on donne au caractere la valeur du caractere suivant
            if (mot == ";")
            {
                motf += " ";
            }

            else
            {
                motf += mot + "\n";						//on ajoute le dernier caractère dans la même variable pour un renvoie propre
            }

            fusible += 1;
        }
        //std::cout << motf << std::endl;		//on renvoie le fichier lu pour les test
        return motf;							// on renvoie la première ligne
    }
    else //en cas de problème d'ouverture du fichier
    {
        std::cerr << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
        std::string a = " ";
        return a;												   //on renvoie une chaîne vide en cas de problème
    }
}

void ouvrirFichierParCaractere(std::string const nom_fichier)
{
    std::string source = ouvrirFichierParLigne(nom_fichier);
    std::string texte = "lecture csv : \n";
    for (char character : source)
    {
        //std::cout << character;
        /*if (character == ' ')
        {
            break;
        }*/
        if (character == ';')
        {
            texte += ' ';
        }

        else if (character == '\n')
        {
            texte += "\n \n";
        }

        else
        {
            texte += character;
        }
    }
    std::cout << texte;
    return;
}


TabDynEleve genererEleveViaCsv(std::string const nom_fichier)
{
    std::string mot = "";
    std::string nom = "";
    std::string prenom = "";
    std::string matiere = "";
    std::string niveau = "";
    int test = 0;
    bool test2 = true;
    std::string id = "";
    int fake_id = 0;

    std::ifstream myfile;
    myfile.open(nom_fichier);
    std::string ligne;
    std::getline(myfile, ligne);		//on se débarrasse de la première ligne qui ne contient que les en-tête
    TabDynEleve eleves;
    for(int i = 0; i < 1000 ; ++i)
    {
        myfile >> mot;
        for (char character : mot)
        {
            if (character == ';' and test != 4)
            {
                test += 1;
            }
            else if (test == 0)
            {
                id += character;
            }
            else if (test == 1)
            {
                prenom += character;
            }
            else if (test == 2)
            {
                nom += character;
            }
            else if (test == 3)
            {
                niveau += character;
            }
            else if (test == 4)
            {
                if (test2)
                {
                    Eleve elevetest(fake_id, prenom, nom, niveau);
                    std::cout << "eleve numero " << id << " : ";
                    std::cout << prenom << " " << nom << std::endl;
                    std::cout << "en annee " << niveau << std::endl;
                    test2 = false;
                    eleves.Add(elevetest);
                }
                if (not (character == '1' or character == '2' or character == '3' or character == '4' or character == '5' or character == '6' or character == '7' or character == '8' or character == '9' or character == '0'))
                {
                    if (character == ';')
                    {
                        matiere += " ";
                    }
                    else
                        matiere += character;
                }
                else
                {
                    test = 5;
                }
            }
            if (test == 5)
            {
                for (i; i < 11; ++i)
                {
                    matiere = " ";
                }
                std::cout << "matieres optionnelles : " << matiere << std::endl << std::endl;

                nom = "";
                prenom = "";
                niveau = "";
                matiere = "";
                id = character;
                test = 0;
                test2 = true;
                fake_id++;
            }
            return eleves;
        }
    }
    return TabDynEleve();
}

TabDynString splitFichier(std::string nom_fichier, char split, char end)
{
    std::ifstream myfile;
    TabDynString data;
    myfile.open(nom_fichier);
    std::string ligne;
    std::string peche = "";
    while(true)
    {
        std::getline(myfile, ligne);
        for (char character : ligne)
        {
            if (character == end)
            {
                data.Add(peche);
                std::cout << peche << std::endl;
                return data;
            }

            if (character == split)
            {
                data.Add(peche);
                std::cout << peche << std::endl;
                peche = "";
            }

            else
            {
                peche += character;
            }
        }
    }
    return data;
}