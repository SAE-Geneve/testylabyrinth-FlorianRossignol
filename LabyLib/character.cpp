#include "character.h"

#include <cmath>
#include <limits>

Character::Character(
	std::pair<int, int> xy, 
	int health_points, 
	int attack, 
	int defence, 
	const std::string& name) :
		xy_(xy),
		health_points_(health_points),
		attack_(attack),
		defence_(defence),
		name_(name) {}

void Character::Attack(Character& enemy) const
{
	if (Distance(enemy)== 1)
	{
		enemy.SetHealthPoints(std::min(enemy.GetHealthPoints(), enemy.GetHealthPoints() - (attack_ - enemy.GetDefence())));
	}
}
	

bool Character::IsDead() const
{
	if (health_points_ <= 0)
	{
		return true;
	}
	return false;
}

float Character::Distance(const Character& character) const
{
	int x1 = xy_.first;
	int y1 = xy_.second;
	int x2 = character.GetPosition().first;
	int y2 = character.GetPosition().second;
	int a = x2;
	int b = y2;
	float d = std::sqrt(a * a + b * b);
	return d;
}
