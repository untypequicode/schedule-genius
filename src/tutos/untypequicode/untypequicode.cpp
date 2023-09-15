#include "untypequicode.h"


void untypequicode() {
	/*
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
	if (input <= 0 or input > 4)
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
	*/

	calculator();
}

void calculator() {
	float a = 0.0f;
	float b = 0.0f;
	char operation;
	std::cout << "Bienvenue sur Calculator, tu peux utiliser les operations suivantes :" << std::endl;
	std::cout << "\n - + : Addition\n - - : Soustraction\n - * : Multiplication\n - / : Division\n - = : Afficher le resultat" << std::endl << std::endl;
	std::cout << "Pour quitter le programme renvoyez 'e' lors de la demande de l'operation" << std::endl;
	std::cout << "Nous t'invitons a inscrire ta valeur de depart" << std::endl;
	std::cin >> a;
	std::cin.ignore();
	while (true) {
		std::cin >> operation;
		if (operation == 'e') {
			std::cout << "Fin du programme" << std::endl;
			break;
		}
		else if (operation == '+') {
			std::cin >> b;
			std::cin.ignore();
			a += b;
		}
		else if (operation == '-') {
			std::cin >> b;
			std::cin.ignore();
			a -= b;
		}
		else if (operation == '*') {
			std::cin >> b;
			std::cin.ignore();
			a *= b;
		}
		else if (operation == '/') {
			std::cin >> b;
			std::cin.ignore();
			a /= b;
		}
		else if (operation == '=') {
			std::cout << a << std::endl;
		}
		else {
			std::cout << "Erreur" << std::endl;
		}

	}
}

/*
for (int i = 0; i <= 10; ++i) {
		while (true) {
			break;
		}
		do {
			continue;
		} while (true);
	}
*/