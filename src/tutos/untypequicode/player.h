#pragma once

#include <iostream>
#include <string>

struct Player {

	Player();
	Player(const Player& player);
	Player(const std::string& name, int hitPoints, int damages, int m_bonus);

	~Player();

	std::string m_name;
	int m_hitPoints;
	int m_damages;
	int m_bonus;
	int* m_Data;

	bool IsDead();
	void Attack(Player& other);
};