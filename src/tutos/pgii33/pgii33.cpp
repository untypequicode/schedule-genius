#include "pgii33.h"

void pgii33()
{
	std::cout << "pgii33" << std::endl;
	float value = 0.0f;
	float temp = 0.0f;
	int choose = 6;
	bool running = true;
	std::cout << "Choisissez 0 pour fermer le programme, 1 pour additionner, 2 pour soustraire, 3 pour multiplier et 4 pour diviser. " << std::endl;
	while (running) {
		std::cin >> choose;
		if (choose == 0) {
			running = false;
		}
		else if (choose == 1) {
			value = additionner(value, temp);
		}
		else if (choose == 2) {
			value = soustraire(value, temp);
		}
		else if (choose == 3) {
			value = multiplier(value, temp);
		}
		else if (choose == 4) {
			value = diviser(value, temp);
		}
	}
}

float additionner(float value, float temp) {
	std::cout << "Combien voulez vous ajouter à " << value << std::endl;
	std::cin >> temp ;
	value = value + temp;
	std::cout << value <<std::endl;
	return value;
}

float soustraire(float value, float temp) {
	std::cout << "Combien voulez vous soustraire à " << value << std::endl;
	std::cin >> temp ;
	value = value - temp;
	std::cout << value << std::endl;
	return value;
}

float multiplier(float value, float temp) {
	std::cout << "Dombien voulez vous multiplier " << value << std::endl;
	std::cin >> temp;
	value = value * temp;
	std::cout << value << std::endl;
	return value;
}

float diviser(float value, float temp) {
	std::cout << "De combien voulez vous diviser" << value << std::endl;
	std::cin >> temp;
	value = value / temp;
	std::cout << value << std::endl;
	return value;
}