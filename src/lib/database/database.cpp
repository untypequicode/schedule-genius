//
// Created by PC-VINCENT on 10/10/2023.
//

#include "database.h"

Database::Database()
    :m_id(TabDynInt(0)),
    m_groupe(TabDynString(0)),
    m_matiere(TabDynString(0)),
    m_eleve(TabDynEleve(0))
{

}

Database::Database(const Database& database)
    :m_id(database.GetId()),
    m_groupe(database.GetGroupe()),
    m_matiere(database.GetMatiere())
{

}

TabDynInt Database::GetId() const
{
    return m_id;
}

TabDynString Database::GetGroupe() const
{
    return m_groupe;
}

TabDynString Database::GetMatiere() const
{
    return m_matiere;
}

void Database::GenererId()
{
    for (int i = m_id.GetNbElem(); i < m_groupe.GetNbElem(); i++)
    {
        //if (i not in m_groupe)
        m_id.Add(i);
    }
}

void Database::AddGroupe(std::string groupe)
{
    m_groupe.Add(groupe);
}

void Database::AddMatiere(std::string matiere)
{
    m_matiere.Add(matiere);
}

int Database::GetId(unsigned int i) const
{
    return m_id.Get(i);
}

std::string Database::GetGroupe(unsigned int i) const
{
    return m_groupe.Get(i);
}

std::string Database::GetMatiere(unsigned int i) const
{
    return m_matiere.Get(i);
}

/*TabDynString Database::GetElement(unsigned int i) const
{
    TabDynString retour(3);
    retour.Add(convertToString(m_id.Get(i)));
    retour.Add(m_groupe.Get(i));
    retour.Add(m_matiere.Get(i));
    return retour;
}
*/