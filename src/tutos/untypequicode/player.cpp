#include "player.h"


bool Player::IsDead() {
	return m_hitPoints <= 0;
} 

void Player::Attack(Player& other) {
	other.m_hitPoints -= m_damages;
}