#ifndef DEF_TABDYN
#define DEF_TABDYN

#include <string>

/*
* Classe TabDyn
* Classe de base pour les tableaux dynamiques
* Contient le nombre d'éléments et le nombre d'éléments maximum
* Les classes filles contiennent le tableau
* 
* Constructeurs :
* TabDyn() : m_nbElem(0), m_nbElemMax(0)
* TabDyn(unsigned int nbElemMax) : m_nbElem(0), m_nbElemMax(nbElemMax)
* TabDyn(const TabDyn& tabDyn) : m_nbElem(tabDyn.m_nbElem), m_nbElemMax(tabDyn.m_nbElemMax)
* 
* Destructeur :
* ~TabDyn()
* 
* Méthodes :
* void SetParam(bool add_with_multiple, unsigned int addition)
* void Clear()
* 
* Accesseurs :
* unsigned int getNbElem() const
* unsigned int getNbElemMax() const
* 
* Attributs :
* unsigned int m_nbElem;
* unsigned int m_nbElemMax;
* 
* Remarques :
* Les classes filles contiennent le tableau
* 
* Exemple :
* TabDynString tab(10);
* std::cout << tab.getNbElem() << std::endl;
* std::cout << tab.getNbElemMax() << std::endl;
* TabDynString tab2;
* std::cout << tab2.getNbElem() << std::endl;
* std::cout << tab2.getNbElemMax() << std::endl;
* 
* Sortie :
* 0
* 10
* 0
* 0
*/
class TabDyn
{
public :
	TabDyn();
	TabDyn(unsigned int nbElemMax);
	TabDyn(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
	TabDyn(const TabDyn& tabDyn);
	~TabDyn();

	unsigned int GetNbElem() const;
	unsigned int GetNbElemMax() const;
	void SetParam(bool add_with_multiple, unsigned int addition);
	void Clear();
	void SetSecurity(bool security);	

protected :
	unsigned int m_nbElem;
	unsigned int m_nbElemMax;
	bool m_add_with_multiple;
	unsigned int m_addition;
	bool m_security;
};

/*
* Classe TabDynString
* Classe fille de TabDyn
* Contient un tableau de std::string
* 
* Constructeurs :
* TabDynString()
* TabDynString(unsigned int nbElemMax)
* TabDynString(const TabDynString& tabDynString)
* 
* Destructeur :
* ~TabDynString()
* 
* Méthodes :
* void Append(std::string str)
* void Add(std::string str)
* std::string Get(unsigned int index) const
* std::string* GetTab() const
* void Set(unsigned int index, std::string str)
* 
* Attributs :
* std::string* m_tab;
* 
* Remarques :
* 
* Exemple :
* TabDynString tab(10);
* std::cout << tab.getNbElem() << std::endl;
* std::cout << tab.getNbElemMax() << std::endl;
* TabDynString tab2;
* std::cout << tab2.getNbElem() << std::endl;
* std::cout << tab2.getNbElemMax() << std::endl;
* 
* Sortie :
* 0
* 10
* 0
* 0
*/
class TabDynString : public TabDyn
{
public :
	TabDynString();
	TabDynString(unsigned int nbElemMax);
	TabDynString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
	TabDynString(const TabDynString& tabDynString);
	~TabDynString();

	void Append(std::string str);
	void Add(std::string str);
	std::string Get(unsigned int index) const;
	std::string* GetTab() const;
	void Set(unsigned int index, std::string str);
	std::string Pop();
	std::string Pop(int index);
	void Remove(std::string elem, int num);
	void Remove(std::string elem);
	void Remove(std::string elem, bool first);

private :
	void AddAppend(std::string str, bool addition);

	std::string* m_tab;
};

class TabDynChar : public TabDyn
{
	public :
		TabDynChar();
		TabDynChar(unsigned int nbElemMax);
		TabDynChar(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
		TabDynChar(const TabDynChar& tabDynChar);
		~TabDynChar();


		void Append(char c);
		void Add(char c);
		char Get(unsigned int index) const;
		char* GetTab() const;
		void Set(unsigned int index, char c);
		char Pop();
		char Pop(int index);
		void Remove(char elem, int num);
		void Remove(char elem);
		void Remove(char elem, bool first);

	private :
		void AddAppend(char c, bool addition);

		char* m_tab;
};

class TabDynInt : public TabDyn
{
	public :
		TabDynInt();
		TabDynInt(unsigned int nbElemMax);
		TabDynInt(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition);
		TabDynInt(const TabDynInt& tabDynInt);
		~TabDynInt();

		void Append(int i);
		void Add(int i);
		int Get(unsigned int index) const;
		int* GetTab() const;
		void Set(unsigned int index, int i);
		int Pop();
		int Pop(int index);
		void Remove(int elem, int num);
		void Remove(int elem);
		void Remove(int elem, bool first);

private :
	void AddAppend(int i, bool addition);

	int* m_tab;
};

#endif