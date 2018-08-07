/*
Crystal Ding
08/06/2018
Header file of Beamo
*/

#ifndef RPG_BEAMO_H
#define RPG_BEAMO_H

#include <iostream>
#include "Player.h"
#include <cstdlib>
#include <ctime>

namespace RPG {

	class Beamo : public Player {

	public:
		Beamo();
		void attackMethod(Player&);
	};
}

#endif
