#ifndef SCHEDULE_GENIUS_DATABASE_H
#define SCHEDULE_GENIUS_DATABASE_H

#include "../tab_dyn/tab_dyn.h"

class Database {
public:
    Database();
    Database(const Database& database);
    TabDynInt GetId() const;
    TabDynString GetGroupe() const;
    TabDynString GetMatiere() const;
    void GenererId();
    void AddGroupe(std::string groupe);
    void AddMatiere(std::string matiere);

private:
    TabDynInt m_id;
    TabDynString m_groupe;
    TabDynString m_matiere;
};


#endif //SCHEDULE_GENIUS_DATABASE_H
