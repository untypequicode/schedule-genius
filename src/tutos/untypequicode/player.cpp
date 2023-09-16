#include "player.h"

Player::Player()
	: m_name("")
	, m_hitPoints(0)
	, m_damages(0)
	, m_bonus(0)
	, m_Data(nullptr)
{
	m_Data = new int();
}

Player::Player(const Player& player)
	: m_name(player.m_name)
	, m_hitPoints(player.m_hitPoints)
	, m_damages(player.m_damages)
	, m_bonus(player.m_bonus)
	, m_Data(nullptr)
{

}

Player::Player(const std::string& name, int hitPoints, int damages, int m_bonus)
	: m_name(name)
	, m_hitPoints(hitPoints)
	, m_damages(damages)
	, m_bonus(0)
	, m_Data(nullptr)
{

}

Player::~Player()
{
	if (m_Data != nullptr) {
		delete m_Data;
	}
}

bool Player::IsDead()
{
	return m_hitPoints <= 0;
} 

void Player::Attack(Player& other)
{
	other.m_hitPoints -= m_damages;
}