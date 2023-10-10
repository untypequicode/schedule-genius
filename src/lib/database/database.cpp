//
// Created by PC-VINCENT on 10/10/2023.
//

#include "database.h"

Database::Database()
    :m_id(TabDynInt(0)),
    m_groupe(TabDynString(0)),
    m_matiere(TabDynString(0))
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