#include <iostream>
#include <vector>

#ifndef LOAD_ENEMIES_H
#define LOAD_ENEMIES_H
struct Enemy {
	std::string name;
	int base_health;
	std::string weapon;
	int weapon_strength;
};
std::vector<Enemy> load_enemies();
#endif