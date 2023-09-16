#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <iostream>
#include <string>

enum Armement {
	aucun,
	épée,
	hache,
	masse
};

enum class Armement2 {
	aucun,
	épée,
	hache,
	masse
};

struct Player {

	Player();
	Player(const Player& player);
	Player(const std::string& name, int hitPoints, int damages, int bonus, Armement armement, Armement2 m_armement2);

	~Player();

	std::string m_name;
	int m_hitPoints;
	int m_damages;
	int m_bonus;
	int* m_Data;
	Armement m_armement;
	Armement2 m_armement2;

	bool IsDead();
	void Attack(Player& other);
};

#endif