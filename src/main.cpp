#include "tutos/untypequicode/untypequicode.hpp"
#include "tutos/vincentcestmoi/vincentcestmoi.hpp"
#include "tutos/pgii33/pgii33.hpp"



int main()
{
	/*// type name;
	// char		- character			- 'r'
	// int		- integer			- 50, 42, 500, -400
	// float	- floating points	- 5.5f
	// double	- double precision	- 5.0
	int age;
	float mark;
	double height;

	// Initialization
	// variable = value
	age = 42; 
	mark = 18.5f;
	height = 200.50;

	// Declaration and Initialization
	// int age = 42;
	// float mark = 18.5f;
	// double height = 200.50;

	int a = 50;
	int b = 20;
	int c = a + b;

	// Operators : + * - / % & | 



	std::cout << "Hello, World" << std::endl;
	std::cout << c << std::endl;
	std::cout << 50 + a << std::endl;
	//std::cin.ignore();

	int number = 0;
	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cin.ignore();
	std::cout << "The number is: " << number << std::endl;

	int d = 0, e = 0;
	std::cout<<"Enter d then e: ";
	std::cin >> d >> e;
	std::cin.ignore();
	std::cout << "d + e = " << d + e << std::endl;*/


	/*
	int number_of_student = 0;
	std::cout << "Bienvenue sur Schedule Genius, veniez renseigner le nombre d'étudiant qu'il y a dans votre établissement : ";
	std::cin >> number_of_student;
	std::cin.ignore();
	std::cout << "Votre établissement a donc " << number_of_student << "étudiants." << std::endl;
	std::cout << "Veuillez renseigner la moyenne générale de tout votre établissement : ";
	float average = 10.0f;
	std::cin >> average;
	std::cin.ignore();
	std::cout << "Vous avez donc un établissement de " << number_of_student << " étudiants, qui ont une moyenne générale de " << average << "/20" << std::endl;

	float uk = 2.5f;
	int test = 2;
	std::cout << "Print sinon conséquences : " << uk;
	std::cin >> test;
	std::cout << uk + test ;
	*/

	/*float data1 = 0.0f;
	float data2 = 0.0f;
	std::cout << "Entrez le premier nombre a additionner : ";
	std::cin >> data1;
	std::cout << "Entrez le nombre a additioner a " << data1 << " : ";
	std::cin >> data2;
	std::cout << data1 << " + " << data2 << " = " << data1 + data2 << std::endl;
	std::cout << "Entrez le nombre a soustraire : ";
	std::cin >> data2;
	std::cout << "Entrez le nombre auquel sera soustrait " << data2 << " : ";
	std::cin >> data1;
	std::cout << data1 << " - " << data2 << " = " << data1 - data2 << std::endl;
	std::cout << "Entrez le premier nombre a multiplier : ";
	std::cin >> data1;
	std::cout << "Entrez le nombre a multiplier par " << data1 << " : ";
	std::cin >> data2;
	std::cout << data1 << " X " << data2 << " = " << data1 * data2 << std::endl;
	std::cout << "Entrez le nombre a diviser : ";
	std::cin >> data1;
	std::cout << "Entrez le diviseur : ";
	std::cin >> data2;
	std::cout << data1 << " / " << data2 << " = " << data1 / data2 << std::endl;*/

	std::cout << "Quel programme voulez vous lancer ?" << std::endl;
	std::cout << "1 : untypequicode" << std::endl;
	std::cout << "2 : vincentcestmoi" << std::endl;
	std::cout << "3 : pgii33" << std::endl;
	int input = 0;
	std::cin >> input;
	std::cin.ignore();
	switch (input) {
		case 1:
			untypequicode();
			break;
		case 2:
			vincentcestmoi();
			break;
		case 3:
			pgii33();
			break;
		default:
			std::cout << "Erreur" << std::endl;
			break;
	}

	return 0;
}