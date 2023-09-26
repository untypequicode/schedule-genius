#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string>



/*
* Classe TabDyn
* Classe permettant de créer un tableau dynamique
* 
*/
class TabDyn
{
public :
	TabDyn(); // Constructeur par défaut
	TabDyn(const TabDyn& tab_dyn); // Constructeur de copie

	TabDyn(unsigned int nb_elem_max); // Constructeur avec nb_elem_max

	TabDyn(unsigned int nb_elem_max, std::string* tab_string); // Constructeur avec nb_elem_max et tableau de string
	TabDyn(unsigned int nb_elem_max, char* tab_char); // Constructeur avec nb_elem_max et tableau de char
	TabDyn(unsigned int nb_elem_max, int* tab_int); // Constructeur avec nb_elem_max et tableau de int
	TabDyn(unsigned int nb_elem_max, double* tab_double); // Constructeur avec nb_elem_max et tableau de double
	TabDyn(unsigned int nb_elem_max, float* tab_float); // Constructeur avec nb_elem_max et tableau de float

	~TabDyn(); // Destructeur

	void AddElem(std::string elem);
	void AddElem(char elem);
	void AddElem(int elem);
	void AddElem(double elem);
	void AddElem(float elem);

	std::string GetElemString(unsigned int index) const;
	char GetElemChar(unsigned int index) const;
	int GetElemInt(unsigned int index) const;
	double GetElemDouble(unsigned int index) const;
	float GetElemFloat(unsigned int index) const;

	std::string* GetTabString() const;
	char* GetTabChar() const;
	int* GetTabInt() const;
	double* GetTabDouble() const;
	float* GetTabFloat() const;

	void SetElemString(unsigned int index, std::string elem);
	void SetElemChar(unsigned int index, char elem);
	void SetElemInt(unsigned int index, int elem);
	void SetElemDouble(unsigned int index, double elem);
	void SetElemFloat(unsigned int index, float elem);

	unsigned int GetNbElem() const;
	unsigned int GetNbElemMax() const;

private:
	unsigned int m_nb_elem;
	unsigned int m_nb_elem_max;

	std::string* m_tab_string;
	char* m_tab_char;
	int* m_tab_int;
	double* m_tab_double;
	float* m_tab_float;

};

#endif