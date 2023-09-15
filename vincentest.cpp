#include <iostream>

int calculatrice()
{
	float data1 = 0;
	float data2 = 0;
	int test;

	std::cout << "Voulez vous faire une addition ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous additionner ? ";
		std::cin >> data1;
		std::cin >> data2;
		std::cout << data1 << " + " << data2 << " = " << data1 + data2;
	}

	std::cout << "Voulez vous faire une soustraction ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous soustraire (a - b) ? ";
		std::cin >> data1;
		std::cin >> data2;
		std::cout << data1 << " - " << data2 << " = " << data1 - data2;
	}

	std::cout << "Voulez vous faire une multiplication ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous multiplier ? ";
		std::cin >> data1;
		std::cin >> data2;
		std::cout << data1 << " x " << data2 << " = " << data1 * data2;
	}

	std::cout << "Voulez vous faire une soustraction ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous soustraire (a - b) ? ";
		std::cin >> data1;
		std::cin >> data2;
		std::cout << data1 << " - " << data2 << " = " << data1 - data2;
	}

	return 0;
}