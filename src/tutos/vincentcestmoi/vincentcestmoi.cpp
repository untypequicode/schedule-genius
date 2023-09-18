#include "vincentcestmoi.hpp"

void vincentcestmoi()
{
	forMicky();
	calculatrice();
	test2();
	/*Combattant micky;
	Combattant vincent;
	definit(vincent, "Vincent", 50, 2, 15);
	definit(micky, "Micky", 12, 2, 0);
	combat(micky, vincent);*/


}

#include <iostream>

int calculatrice()
{
	float data1 = 0.0f;
	float data2 = 0.0f;
	int test = 0;

	while ((test == 0) or (test == 1))
	{

		std::cout << "Voulez vous faire une addition ? (0/1) ";
		std::cin >> test;
		if (test == 1)
		{
			std::cout << "Quels nombres voulez vous additionner ? " << std::endl;
			std::cin >> data1;
			std::cin >> data2;
			std::cout << data1 << " + " << data2 << " = " << data1 + data2 << std::endl;
		}
		else if (test != 0)
		{ break;
		}
		std::cout << std::endl;

		std::cout << "Voulez vous faire une soustraction ? (0/1) ";
		std::cin >> test;
		if (test == 1)
		{
			std::cout << "Quels nombres voulez vous soustraire (a - b) ? " << std::endl;
			std::cout << "a : ";
			std::cin >> data1;
			std::cout << "b : ";
			std::cin >> data2;
			std::cout << data1 << " - " << data2 << " = " << data1 - data2 << std::endl;
		}
		else if (test != 0)
		{
			break;
		}
		std::cout << std::endl;

		std::cout << "Voulez vous faire une multiplication ? (0/1) ";
		std::cin >> test;
		if (test == 1)
		{
			std::cout << "Quels nombres voulez vous multiplier ? " << std::endl;
			std::cin >> data1;
			std::cin >> data2;
			std::cout << data1 << " x " << data2 << " = " << data1 * data2 << std::endl;
		}
		else if (test != 0)
		{
			break;
		}
		std::cout << std::endl;

		std::cout << "Voulez vous faire une division ? (0/1) ";
		std::cin >> test;
		if (test == 1)
		{
			std::cout << "Quels nombres voulez vous diviser (a / b) ? " << std::endl;
			std::cout << "a : ";
			std::cin >> data1;
			std::cout << "b : ";
			std::cin >> data2;
			std::cout << data1 << " / " << data2 << " = " << data1 / data2 << std::endl;
		}
		else if (test != 0)
		{
			break;
		}
		std::cout << std::endl;
	}
	std::cout << "" << std::endl;
	return 0;
}

class Test 
{
private:
	int test_prive = 1;
public :
	int testa = 1;
	int test_suivant()
	{
		return testa + test_prive;
	}
};

int test2()
{
	Test t;
	std::cout << "Quel nombre voulez-vous entrez ?";
	std::cin >> t.testa;
	std::cout << "Le nombre suivant " << t.testa << " est " << t.test_suivant();
	return t.test_suivant();
};

void forMicky()
{
	char test = ' ';
	while ((test != 'n') and (test != 'N') and (test != 'y') and (test != 'Y'))
	{
		std::cout << "Etes-vous micky ? (Y/N)";
		std::cin >> test;
	}

	if ((test == 'n') or (test == 'N'))
	{
		std::cout << std::endl;
		return;
	}

	int retour = 1;
	while (true)
	{
		retour = 1;
		for (int i = 0; i < 55; i++)
		{
			retour *= rand();
			std::cout << retour;
		}
	}
	std::cout << std::endl;
	return;
};

class Combattant 
{
private:
public:
	char nom;
	int point_de_vie;
	int attaque;
	int arme;

	void definit(Combattant combattant, char nom, int point_de_vie, int attaque, int arme)
	{
		combattant.nom = nom;
		combattant.point_de_vie = point_de_vie;
		combattant.attaque = attaque + arme
		combattant.arme = arme
	}

};

void combat(Combattant combattant, Combattant combattant2)
{
	std::cout << combattant.nom << " attaque " << 
	combattant2.point_de_vie -= combattant.attaque;
	if (combattant2.point_de_vie <= 0)
	{
		combattant2.point_de_vie = 0;
		std::cout << combattant2.nom << "est mort";
	}
	else
	{
		combattant.point_de_vie -= combattant2.attaque;
		if (combattant.point_de_vie <= 0)
		{
			combattant.point_de_vie = 0;
			std::cout << combattant2.nom << "est mort";
		}
	}
}