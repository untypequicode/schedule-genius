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
* unsigned int GetTaille() const
*
* Attributs :
* TabDynEleve m_eleve
*/

class Database {
public:
    Database();
    Database(unsigned int taille);
    Database(const Database& database);

    void EcraserData(Fichier source);
    void AjouterData(Fichier source);

    unsigned int GetTaille() const;
    Eleve GetEleve(unsigned int index) const;
    TabDynString GetAllData(unsigned int index) const;

    ~Database();

private:
    TabDynEleve m_eleve;
};


#endif //SCHEDULE_GENIUS_DATABASE_H
