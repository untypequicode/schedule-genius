#ifndef DEF_GROUPE
#define DEF_GROUPE

#include <string>
#include "eleves.hpp"

class Groupe
{
public:
	std::string m_niveau;
	std::string m_matiere;
	int m_nombre_eleves;
	
	Groupe(std::string niveau, std::string matiere);	
	void AddEleve(Eleve& eleve);
	Eleve GetEleve(int index);
	~Groupe();

private:
	Eleve* m_eleves;
	
};

#endif