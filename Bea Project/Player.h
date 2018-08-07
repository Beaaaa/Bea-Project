/*
Crystal Ding
08/06/2018
Header file of Player
*/

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

namespace RPG {

	const int max_length = 20;

	class Player {

	protected:
		char type;
		char* name;
		int health, attack, enhanced_atk, defense, enhanced_def, speed;
		
	public:
		Player();
		Player(const char*, int, int, int, int, char = 'P');
		Player(const Player&);
		Player& operator=(const Player&);
		virtual ~Player();
		char* get_name();
		const char* currentName() const;
		bool isEmpty() const;
		bool alive() const;
		int enh_def() const;
 		int damage(Player&) const;
		int hp_after_attack(Player&);
		int optionValid(int&);
		void copy_name(const char*);
		void angryBoss();
		void bossOffer(Player&);
		void display(Player&) const;
		virtual void attackMethod(Player&);
		void turn(Player&);
		void operator*(Player&);
		void prize();
		void gamePlay(Player&);
		std::istream& welcome(std::istream&);
		std::ostream& stats(std::ostream&) const;
	};

	std::istream& operator>>(std::istream&, Player&);
	std::ostream& operator<<(std::ostream&, const Player&);
	void errorMsg();
	void diamond();
}

#endif