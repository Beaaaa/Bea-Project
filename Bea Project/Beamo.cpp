/*
Crystal Ding
08/06/2018
Define Beamo
*/

#include "Beamo.h"

namespace RPG {

	Beamo::Beamo() {
		type = 'S';
		copy_name(get_name());
		health = 30;
		attack = 16;
		enhanced_atk = attack;
		defense = 4;
		enhanced_def = defense;
		speed = 6;
	}

	void Beamo::attackMethod(Player& rhs) {
		int flag = 1;

		std::cout << " Which skill will you use?" << std::endl;
		std::cout << "    1. Blinding Shot - makes " << rhs.currentName() << " lose his sight when he trys to attack you." << std::endl;
		std::cout << "    2. Toxic Dart - deals poison damage to " << rhs.currentName() << " for 3 seconds." << std::endl;
		std::cout << "    3. Green Mushroom - is planted on the floor and hope " << rhs.currentName() << " step on it. " << std::endl;
		std::cout << "       (It will result in massive damage once it's triggered.)" << std::endl << std::endl;

		while (flag == 1) {
			switch (optionValid(flag)) {
			case 1:
				enhanced_atk = attack;
				enhanced_def = defense + 99;
				break;
			case 2:
				enhanced_atk = attack + 3;
				enhanced_def = defense;
				break;
			case 3:
				srand((unsigned int)time(NULL));
				enhanced_atk = ((rand() % 10) % 2 == 0) ? (attack + 5) : 0;
				enhanced_def = defense;
				break;
			default: std::cout << " \"Please select a valid option.\"" << std::endl << std::endl;
			}
		}
	}
}