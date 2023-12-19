#include "groupes.h"

Groupes::Groupes()
    : m_id(0),
      m_niveau_scolaire(0),
      m_nom("/0"),
      m_matiere(TabDynIntUnsigned()),
      m_horaire(TabDynIntUnsigned()),
      m_prof(TabDynIntUnsigned())
{

}

Groupes::Groupes(unsigned int id,
                 unsigned int niveau_scolaire,
                 std::string nom,
                 TabDynIntUnsigned matiere,
                 TabDynIntUnsigned horaire,
                 TabDynIntUnsigned prof)
    : m_id(id),
      m_nom(nom),
      m_matiere(matiere),
      m_horaire(horaire),
      m_prof(prof),
      m_niveau_scolaire(niveau_scolaire)
 {

 }

Groupes::Groupes(const Groupes &groupes)

Groupes::~Groupes()
{

}
