#include "untypequicode.hpp"

// public
// protected
// private

struct Player {
	std::string name;
	int hitPoints;
	int damages;

	bool IsDead() {
		return hitPoints <= 0;
	}

	void Attack(Player& other);
};

void Player::Attack(Player& other) {
	other.hitPoints -= damages;
}


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

	//calculator();

	//history1();
	
	//history2();

	//display();

	jeu();
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

void history1() {
	char history[20] = {};
	for (int i = 0; i < 20; ++i) {
		std::cin >> history[i];
	}
	for (int i = 0; i < 20; ++i) {
		std::cout << history[i];
	}
	std::cout << std::endl;
}

void history2() {
	// new int : -> delete int;
	// new int[10] : -> delete[] int;
	int size = 0;
	std::cout << "Taille de l'historique : ";
	std::cin >> size;
	std::cin.ignore();
	char* history = new char[size];
	for (int i = 0; i < size; ++i) {
		std::cin >> history[i];
	}
	for (int i = 0; i < size; ++i) {
		std::cout << history[i];
	}
	delete[] history;
}

void display() {
	int x = 0;
	int y = 0;
	std::cout << "Entrez la taille de la matrice : ";
	std::cin >> x >> y;
	std::cin.ignore();
	int** matrix = new int* [y];

	for (int i = 0; i < y; ++i) {
		matrix[i] = new int[x];
	}

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; j++) {
			std::cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < y; ++i) {
		delete[] matrix[i];
	}

	delete[] matrix;

}

void jeu() {
	Player player1;
	Player player2;
	Player player3;

	player1.name = "untypequicode";
	player1.hitPoints = 100;
	player2.name = "vincentcestmoi";
	player2.hitPoints = 20;
	player2.damages = 50;
	player2.Attack(player1);
	player2.Attack(player1);
	player3.name = "pgii33";
	player3.hitPoints = 10;

	std::cout << player1.name << std::endl;
	std::cout << player2.name << std::endl;
	std::cout << player3.name << std::endl;

	if (player1.IsDead()) {
		std::cout << player1.name << " est mort" << std::endl;
	}
	else {
		std::cout << player1.name << " est vivant" << std::endl;
	}
	if (player2.IsDead()) {
		std::cout << player2.name << " est mort" << std::endl;
	}
	else {
		std::cout << player2.name << " est vivant" << std::endl;
	}
	if (player3.IsDead()) {
		std::cout << player3.name << " est mort" << std::endl;
	}
	else {
		std::cout << player3.name << " est vivant" << std::endl;
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