#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "enemies.h"


/** This function reads the enemies.csv file and returns a struct array of enemy types 
 * TODO: Add in error-handling for malformed CSV files 
 * TODO: Read the enemies.csv file from a set folder and not the cwd */
std::vector<Enemy> load_enemies(){

	std::vector<Enemy> enemies;

	std::string enemy_string;
	std::ifstream enemiesfile("enemies.csv");
	if (enemiesfile){
		std::cout << "Enemies.csv file was found and loaded." << std::endl;
		while (std::getline(enemiesfile, enemy_string)){
			std::string cell;
			std::stringstream enemystring(enemy_string);
			std::vector<std::string> enemy_properties;
			 
      // For each line in the file, split into cells based on the ',' character
      while(std::getline(enemystring,cell,',')){
			 	enemy_properties.push_back(cell);
			}

			// Building an enemy object
			Enemy enemy_object;
			enemy_object.name = enemy_properties[0];
			enemy_object.base_health = std::stoi(enemy_properties[1]);
			enemy_object.weapon = enemy_properties[2];
			enemy_object.weapon_strength = std::stoi(enemy_properties[3]);
			enemies.push_back(enemy_object);
		}
		enemiesfile.close();
	} else {
    // TODO: Set this to print to stderr
		std::cout << "Error opening file enemies.csv!" << std::endl;
	}

  // Below output is only for debugging!
	for (int loop = 0; loop < enemies.size(); loop++){
		std::cout << "Enemy" << loop << " name: " << enemies[loop].name << std::endl;
		std::cout << "Enemy" << loop << " base health: " << enemies[loop].base_health << std::endl;
		std::cout << "Enemy" << loop << " weapon: " << enemies[loop].weapon << std::endl;
		std::cout << "Enemy" << loop << " weapon strength: " << enemies[loop].weapon_strength << std::endl;
		std::cout << "\n";
	}
	return enemies;
}
