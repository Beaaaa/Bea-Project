/*
Crystal Ding
08/06/2018
Header file of Basus
*/

#ifndef RPG_BASUS_H
#define RPG_BASUS_H

#include <iostream>
#include "Player.h"

namespace RPG {

	class Basus : public Player {

	protected:
		int basic_atk;

	public:
		Basus();
		void attackMethod(Player&);
	};
}

#endif

