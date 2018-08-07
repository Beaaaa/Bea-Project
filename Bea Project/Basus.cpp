/*
Crystal Ding
08/06/2018
Define Basus
*/

#include "Basus.h"

namespace RPG {

	Basus::Basus() {
		type = 'T';
		copy_name(get_name());
		health = 45;
		basic_atk = 10;
		attack = basic_atk;
		enhanced_atk = attack;
		defense = 8;
		speed = 3;
	}

	void Basus::attackMethod(Player& rhs) {
		int flag = 1;

		std::cout << " Which skill will you use?" << std::endl;
		std::cout << "    1. Symphony Strike - deals basic damanage to " << rhs.currentName() << " and stacks its power everytime you use it." << std::endl;
		std::cout << "    2. Deal Breaker - crushs " << rhs.currentName() << "'s armor and does a basic attack." << std::endl;
		std::cout << "    3. Iron Shield - does a basic attack and temporarily boosts your defense." << std::endl << std::endl;

		while (flag == 1) {
			switch (optionValid(flag)) {
			case 1:
				enhanced_atk = attack;
				attack += 2;
				enhanced_def = defense;
				break;
			case 2:
				enhanced_atk = basic_atk + rhs.enh_def();
				enhanced_def = defense;
				break;
			case 3:
				enhanced_atk = basic_atk;
				enhanced_def = defense + 3;
				break;
			default: std::cout << " \"Please select a valid option.\"" << std::endl << std::endl;
			}
		}
	}
}