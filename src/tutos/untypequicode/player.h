#pragma once

#include <string>

struct Player {
	std::string m_name;
	int m_hitPoints;
	int m_damages;

	bool IsDead();
	void Attack(Player& other);
};