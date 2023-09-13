
#include <iostream>

int main()
{
	// type name;
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
	std::cout << "d + e = " << d + e << std::endl;

	return 0;
}