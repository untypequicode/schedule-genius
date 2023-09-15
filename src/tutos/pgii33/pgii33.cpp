#include "pgii33.h"

void pgii33()
{
	std::cout << "pgii33" << std::endl;
	float value = 0.0f;
	float temp = 0.0f;
	int choose = 6;
	bool running = true;
	while (running) {
		std::cout << "Choisissez 0 pour fermer le programme, 1 pour additionner, 2 pour soustraire, 3 pour multiplier et 4 pour diviser. ";
		std::cin >> choose;
		if (choose == 0) {
			running = false;
		}
		if (choose == 1) {
			additionner(value, temp);
		}
	}


}

void additionner(float value, float temp) {
	std::cout << "Combien voulez vous ajouter à " << value ;
	std::cin >> temp ;
	value = value + temp;
	std::cout << value ;
}

void soustraire(float value, float temp) {
	std::cout << "Combien voulez vous soustraire à " << value;
	std::cin >> temp ;
	value = value - temp;
	std::cout << value ;
}

void multiplier(float value, float temp) {
	std::cout << "Dombien voulez vous multiplier " << value;
	std::cin >> temp;
	value = value * temp;
	std::cout << value;
}

void diviser(float value, float temp) {
	std::cout << "De combien voulez vous diviser" << value;
	std::cin >> temp;
	value = value / temp;
	std::cout << value;
}