#ifndef SCHEDULE_GENIUS_DATABASE_H
#define SCHEDULE_GENIUS_DATABASE_H

#include "../fichier.h"


/*
* Classe Database
* Classe de stockage d'élèves
* COntient une liste d'élèves et son nombre d'éléments
*
* Constructeurs :
* Database() : m_taille(0), m_eleve(TabDynEleve(0))
* Database(unsigned int taille) : m_taille(taille), m_eleve(TabDynEleve(taille))
* Database(const Database& database) : m_taille(database.m_taille), m_eleve(database.m_eleve)
*
* Destructeur:
* ~Database()
*
* Méthodes :
* void EcraserData(Fichier source)
* void AjouterData(Fichier source)
*
*
* Accesseurs:
* Eleve GetEleve(unsigned int index) const
* TabDynString GetAllData(unsigned int index) const
*
* Attributs :
* TabDynEleve m_eleve
*/

class Database {
public:
    Database();
    //crée une database vide
    Database(unsigned int taille);
    //crée une database vide avec une taille
    Database(const Database& database);
    //crée une database à partir d'une autre database

    void EcraserData(Fichier source);
    // Ecrase les données de la database par les données du fichier source
    void AjouterData(Fichier source);
    // Ajoute les données du fichier source à la database

    Eleve GetEleve(unsigned int index) const;
    // renvoie l'élève à l'index donné
    TabDynString GetEleveData(unsigned int index) const;
    // renvoie toutes les données de l'élève à l'index donné
    TabDynEleve GetEleve() const;
    // renvoie la liste d'élève

    ~Database();

private:
    TabDynEleve m_eleve;
};


#endif //SCHEDULE_GENIUS_DATABASE_H
