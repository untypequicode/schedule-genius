#include "untypequicode.h"


void untypequicode() {
	float data1 = 0.0f;
	float data2 = 0.0f;

	std::cout << "0 : finir le programme" << std::endl;
	std::cout << "1 : addition" << std::endl;
	std::cout << "2 : soustraction" << std::endl;
	std::cout << "3 : multiplication" << std::endl;
	std::cout << "4 : division" << std::endl;
	int input = 0;
	std::cin >> input;
	std::cin.ignore();
	if (input == 0 or input > 4)
	{
		std::cout << "Fin du programme" << std::endl;
		return;
	}
	std::cout << "Entrez le premier nombre : ";
	std::cin >> data1;
	std::cin.ignore();
	std::cout << "Entrez le deuxième nombre : ";
	std::cin >> data2;
	std::cin.ignore();
	if (input == 1)
	{
		std::cout << data1 << " + " << data2 << " = " << data1 + data2 << std::endl;
	}
	else if (input == 2)
	{
		std::cout << data1 << " - " << data2 << " = " << data1 - data2 << std::endl;
	}
	else if (input == 3)
	{
		std::cout << data1 << " X " << data2 << " = " << data1 * data2 << std::endl;
	}
	else if (input == 4)
	{
		std::cout << data1 << " / " << data2 << " = " << data1 / data2 << std::endl;
	}
	else
	{
		std::cout << "Erreur" << std::endl;
	}
};
