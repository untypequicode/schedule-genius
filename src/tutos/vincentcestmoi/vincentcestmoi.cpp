#include "vincentcestmoi.h"

void vincentcestmoi()
{
	calculatrice();
}

#include <iostream>

int calculatrice()
{
	float data1 = 0.0f;
	float data2 = 0.0f;
	int test = 0;
	int i;

	while ((test == 0) or (test == 1))
	{

		std::cout << "Voulez vous faire une addition ? (0/1) ";
		std::cin >> test;
		if (test == 1)
		{
			std::cout << "Quels nombres voulez vous additionner ? " << std::endl;
			std::cin >> data1;
			std::cin.ignore();
			std::cin >> data2;
			std::cin.ignore();
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
			std::cin.ignore();
			std::cout << "b : ";
			std::cin >> data2;
			std::cin.ignore();
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
			std::cin.ignore();
			std::cin >> data2;
			std::cin.ignore();
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
			std::cin.ignore();
			std::cout << "b : ";
			std::cin >> data2;
			std::cin.ignore();
			std::cout << data1 << " / " << data2 << " = " << data1 / data2 << std::endl;
		}
		else if (test != 0)
		{
			break;
		}
		std::cout << std::endl;

		std::cin.ignore();
	}
	return 0;
}