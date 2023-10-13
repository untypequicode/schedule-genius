#ifndef SCHEDULE_GENIUS_DATABASE_H
#define SCHEDULE_GENIUS_DATABASE_H

#include "../fichier.h"

class Database {
public:
    Database();
    Database(const Database& database);
    Database(unsigned int taille);
    void AjusterTaille();
    void EcraserData(Fichier source);
    void AjouterData(Fichier source);

    Eleve GetEleve(unsigned int index) const;
    TabDynString GetAllData(unsigned int index) const;

private:
    TabDynEleve m_eleve;
    unsigned int m_taille;
};


#endif //SCHEDULE_GENIUS_DATABASE_H
