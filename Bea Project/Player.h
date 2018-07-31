#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <iostream>

namespace RPG {

	const int max_length = 20;

	class Player {
		char type;
		char* name;
		int health, attack, enhanced_atk, defense, speed;
		
	public:
		Player();
		Player(const char*, int, int, int, int, char = 'P');
		Player(const Player&);
		Player& operator=(const Player&);
		virtual ~Player();
		void copy_name(const char*);
		bool isEmpty() const;
		bool alive() const;
		int hp() const;
		int atk() const;
		int en_atk() const;
		int def() const;
		int spd() const;
 		int damage(Player&) const;
		int hp_after_attack(Player&);
		int optionValid(int&);
		void angryBoss();
		void bossOffer(Player&);
		void display(Player&) const;
		void turn(Player&);
		void operator*(Player&);
		void prize();
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;
	};
	std::istream& operator>>(std::istream&, Player&);
	std::ostream& operator<<(std::ostream&, const Player&);
	void diamond();
}

#endif