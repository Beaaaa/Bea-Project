#include "Player.h"
#include <string>
#include <sstream>
#include <fstream>

namespace RPG {

	//0-arg constructor
	Player::Player() {
		type = 'N';
		name = nullptr;
		health = 0;
		attack = 0;
		enhanced_atk = 0;
		defense = 0;
		speed = 0;
	}

	//5 or 6-arg constructor
	Player::Player(const char* reg_name, int reg_hp, int reg_atk, int reg_def, int reg_spd, char reg_type) {
		if ((reg_name != nullptr || reg_name[0] != '\0') && reg_hp > 0 && reg_atk > 0 && reg_def > 0 && reg_spd > 0) {
			type = reg_type;
			copy_name(reg_name);
			health = reg_hp;
			attack = reg_atk;
			enhanced_atk = reg_atk;
			defense = reg_def;
			speed = reg_spd;
		}
		else {
			name = nullptr;
			*this = Player();
		}
	}

	//copy constructor
	Player::Player(const Player& rhs) {
		name = nullptr;
		*this = rhs;
	}

	//copy assignment operator
	Player& Player::operator=(const Player& rhs) {
		name = nullptr;
		if (this != &rhs) {
			copy_name(rhs.name);
			health = rhs.health;
			attack = rhs.attack;
			enhanced_atk = rhs.enhanced_atk;
			defense = rhs.defense;
			speed = rhs.speed;
		}
		return *this;
	}

	//destructor
	Player::~Player() {
		delete[] name;
	}

	//copy name
	void Player::copy_name(const char* rhs) {
		name = new char[max_length + 1];
		strncpy(name, rhs, max_length);
		name[max_length] = '\0';
	}

	//return true if the current Player is in the safe empty state
	bool Player::isEmpty() const {
		return ((name == nullptr || name[0] == '\0') && health == 0 && attack == 0 && defense == 0 && speed == 0);
	}

	//return true if the current Player is still alive
	bool Player::alive() const {
		return (health > 0);
	}

	//return the current Player's health
	int Player::hp() const{
		return health;
	}

	//return the current Player's attack
	int Player::atk() const {
		return attack;
	}

	//return the current Player's enhanced attack
	int Player::en_atk() const {
		return enhanced_atk;
	}

	//return the current Player's defense
	int Player::def() const {
		return defense;
	}

	//return the current Player's speed
	int Player::spd() const {
		return speed;
	}

	//return the current Player's damange dealt
	int Player::damage(Player& rhs) const {
		int dmg = enhanced_atk - rhs.defense;
		return (dmg < 0 ? 0 : dmg);
	}

	//return the receive Player's health after being attacked
	int Player::hp_after_attack(Player& rhs) {
		rhs.health = rhs.health - damage(rhs);
		return (rhs.health = rhs.health > 0 ? rhs.health : 0);
	}

	//return a valid option input
	int Player::optionValid(int& flag) {
		int option = 0;
		char* input = nullptr;

		if (type != 'B') {
			std::cout << " " << name << ": ";
		}
		else {
			std::cout << " You: ";
		}

		input = new char[max_length + 1];
		std::cin.getline(input, max_length + 1);
		std::stringstream is(input);

		if (is >> option && is >> input) {
			option = 0;
		}
		else if (option >= 1 && option <= 3) {
			flag = 0;
		}

		std::cout << std::endl;

		delete[] input;
		return option;
	}

	//program the Boss's behaviour when its getting angry
	void Player::angryBoss() {
		std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
		std::cout << " {{{ " << name << " is getting angry! (#_#) }}}" << std::endl << std::endl;
		enhanced_atk = attack + 10;
		std::cout << *this << std::endl;
	}

	//program the Boss's offer
	void Player::bossOffer(Player& rhs) {
		int flag = 1;

		std::cout << " " << name << ": \"You know what? I have her LinkedIn profile (>_<), take it and leave me alone please~~~\"" << std::endl << std::endl;
		std::cout << "    1. \"Fine.\"" << std::endl;
		std::cout << "    2. \"Nah~\"" << std::endl;
		std::cout << "    3. Ignore " << name << "'s offer and continue the game" << std::endl << std::endl;
	
		while (flag == 1) {
			switch (optionValid(flag)) {
			case 1:
				rhs.health = -99;
				std::cout << " " << name << ": \"Here you go! https://www.linkedin.com/in/crystal-ding/\"" << std::endl << std::endl;
				std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
				std::cout << "    You left with the developer's LinkedIn profile!" << std::endl;
				break;
			case 2:
				angryBoss();
				hp_after_attack(rhs);
				break;
			case 3:
				std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
				std::cout << "     Nothing happened and the game continues..." << std::endl << std::endl;
				std::cout << std::endl;
				break;
			default: std::cout << " \"Please select a valid option.\"" << std::endl << std::endl;
			}
		}
	}

	//display the damage taken and health after being attacked
	void Player::display(Player& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			std::cout << " " << name << " attacks " << rhs.name << "!" << std::endl;
			std::cout << " Damage taken: " << damage(rhs) << std::endl;
			std::cout << " Health bar: |";
			for (int i = 0; i < rhs.hp(); i++) {
				std::cout << "*";
			}
			std::cout << "|" << std::endl;
		}
	}

	//program the Player's behaviour in its turn
	void Player::turn(Player& rhs) {
		int flag = 1;
		int temp = atk();

		if (alive() && !isEmpty() && !rhs.isEmpty()) {
			hp_after_attack(rhs);

			if (type != 'B') {
				std::cout << " Please select one of the following actions:" << std::endl;
				std::cout << "    1. Punchs " << rhs.name << " in the face." << std::endl;
				std::cout << "    2. Picks up a pebble and throw it at " << rhs.name << "." << std::endl;
				std::cout << "    3. Fetchs a twig and use it to slap " << rhs.name << "." << std::endl << std::endl;

				flag = 1;

				while (flag == 1) {
					switch (optionValid(flag)) {
					case 1:
						enhanced_atk = attack;
						break;
					case 2:
						enhanced_atk = attack + 1;
						break;
					case 3:
						enhanced_atk = attack + 2;
						break;
					default: std::cout << " \"Please select a valid option.\"" << std::endl << std::endl;
					}
				}
			}
			else {
				if (health <= rhs.damage(*this)) {
					std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
					std::cout << " " << name << ": \"Ouch, stop! stop!! What are you doing here?\"" << std::endl << std::endl;
					std::cout << "    1. \"To have some fun~\"" << std::endl;
					std::cout << "    2. \"To beat you up!\"" << std::endl;
					std::cout << "    3. \"Get to know the developer of this project.\"" << std::endl << std::endl;
						 
					while (flag == 1) {
						switch (optionValid(flag)) {
						case 1:
							std::cout << " " << name << ": \"You've already had a lot of fun! Stop messing around and get out here! (T_T)\"" << std::endl << std::endl;
							std::cout << "    1. \"Okay.\"" << std::endl;
							std::cout << "    2. \"Nope!\"" << std::endl;
							std::cout << "    3. \"Why should I?\"" << std::endl << std::endl;
							flag = 1;
							while (flag == 1) {
								switch (optionValid(flag)) {
								case 1: 
									rhs.health = -99;
									std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
									std::cout << "    You get back home with empty hands." << std::endl;
									break;
								case 2:
									angryBoss();
									hp_after_attack(rhs);
									break;
								case 3:
									bossOffer(rhs);
									break;
								default: std::cout << " \"Please select a valid option.\"" << std::endl << std::endl;
								}
							}
							break;
						case 2:
							angryBoss();
							hp_after_attack(rhs);
							break;
						case 3:
							bossOffer(rhs);
							break;
						default: std::cout << " \"Please select a valid option.\"" << std::endl << std::endl;
						}
					}
				}
			}
			if (rhs.health > -99) {
				display(rhs);
			}
		}
	}

	//program how two Players fight to each other
	void Player::operator*(Player& rhs) {
		while (alive() && rhs.alive()) {
			if (rhs.spd() > spd()) {
				std::cout << std::endl;
				rhs.turn(*this);
				std::cout << std::endl;
				turn(rhs);
			}
			else {
				std::cout << std::endl;
				turn(rhs);
				std::cout << std::endl;
				rhs.turn(*this);
			}
		}
	}

	//extract name, register Player's stats accordingly, and return a reference to the istream object
	std::istream& Player::read(std::istream& is) {
		char reg_name[max_length + 1];
		std::string answer;
		int flag = 1;

		while (flag == 1) {
			std::cout << " Your Name: ";
			is.getline(reg_name, max_length + 1);
			if (is.fail()) {
				std::cout << " \"Too long! Keep it short please!\"" << std::endl;
				is.clear();
				is.ignore(2000, '\n');
			}
			else if (reg_name[0] == '\0') {
				std::cout << " \"You didn't give me your name. Try again!\"" << std::endl;
			}
			else {
				flag = 0;
			}
			std::cout << std::endl;
		}

		flag = 1;

		while (flag == 1) {
			std::cout << " Are you an employer? (Y/N) ";
			getline(std::cin, answer);

			if (!std::cin.fail()) {
				if (answer.length() == 1 && toupper(answer[0]) == 'Y') {
					std::cout << std::endl;
					std::cout << " Welcome to Bea Project! You are currently in 'Invincible Mode'." << std::endl;
					std::cout << " Enjoy your time here!" << std::endl;
					std::cout << std::endl;
					*this = Player(reg_name, 50, 20, 15, 10);
					flag = 0;
					return is;
				}
				else if (answer.length() == 1 && toupper(answer[0]) == 'N') {
					while (flag == 1) {
						std::cout << std::endl;
						std::cout << " Do you know the developer of this game in real life? (Y/N) ";
						getline(std::cin, answer);

						if (!std::cin.fail()) {
							if (answer.length() == 1 && toupper(answer[0]) == 'Y') {
								std::cout << std::endl;
								std::cout << " Welcome to Bea Project! You are currently in 'Normal Mode'." << std::endl;
								std::cout << " Have fun~" << std::endl;
								std::cout << std::endl;
								*this = Player(reg_name, 35, 14, 8, 5);
								flag = 0;
								return is;
							}
							else if (answer.length() == 1 && toupper(answer[0]) == 'N') {
								std::cout << std::endl;
								std::cout << " Welcome to Bea Project! You are currently in 'Hard Mode'." << std::endl;
								std::cout << " \"May the Force be with you.\"" << std::endl;
								std::cout << std::endl;
								*this = Player(reg_name, 35, 13, 8, 3);
								flag = 0;
								return is;
							}
							else {
								std::cout << " \"I'll only take (Y/N) as the answer.\"" << std::endl;
								is.clear();
							}
						}
					}
				}
				else {
					std::cout << " \"I'll only take (Y/N) as the answer.\"" << std::endl;
					std::cout << std::endl;
					is.clear();
				}
			}
		}
		return is;
	}

	//receive a reference to an ostream object and return a reference to the ostream object
	std::ostream& Player::write(std::ostream& os) const {
		os << " " << name << " Stats: " << std::endl;
		os << "    Health: " << hp() << std::endl;
		os << "    Attack: " << en_atk() << std::endl;
		os << "    Defense: " << def() << std::endl;
		os << "    Speed: " << spd() << std::endl << std::endl;
		return os;
	}

	//extract the Player stats from the istream
	std::istream& operator>>(std::istream& is, Player& rhs) {
		rhs.read(is);
		return is;
	}

	//print a diamond shape
	void diamond() {
		int a = 3;

		for (int i = 0; i <= 2 * a; i++) {
			for (int j = 0; j <= 2 * a; j++) {
				if (i <= a) {
					if (j < a - i || j > a + i) {
						std::cout << " ";
					}
					else {
						std::cout << "*";
					}
				}
				else {
					if (j < i - a || j > 3 * a - i) {
						std::cout << " ";
					}
					else {
						std::cout << "*";
					}
				}
			}
			std::cout << std::endl;
		}
	}

	//insert the Player stats into the ostream
	std::ostream& operator<<(std::ostream& os, const Player& rhs) {
		rhs.write(os);
		return os;
	}

	//program the prize the players get after they beat the game
	void Player::prize() {
		int flag = 1;
		char* GM = new char[max_length + 1];

		std::cout << " A creature who claimed itself as the Game Master of this game suddenly appeared in front of you, its name is ________." << std::endl;
		std::cout << "    1. Moggle" << std::endl;
		std::cout << "    2. Tomberry" << std::endl;
		std::cout << "    3. Choccobo" << std::endl << std::endl;

		while (flag == 1) {
			switch (optionValid(flag)) {
			case 1: strcpy(GM, "Moggle");
				break;
			case 2: strcpy(GM, "Tomberry");
				break;
			case 3: strcpy(GM, "Choccobo");
				break;
			default: std::cout << " \"Not like you have other choices~\"" << std::endl << std::endl;
			}
		}

		std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
		std::cout << " " << GM << ": \"Congrats! You just beat the game!! Here is your prize~ \"";
		std::cin.ignore(2000, '\n');
		std::cout << std::endl;

		diamond();

		std::cin.ignore(2000, '\n');
		std::cout << " " << name << ": \"Seriously? That's it?\"";
		std::cin.ignore(2000, '\n');
		std::cout << std::endl;
		std::cout << " " << GM << ": \"Okay, okay, be patient! It's always so stressful to deal with you humans.\"";
		std::cin.ignore(2000, '\n');
		std::cout << " " << GM << ": \"I really need to grab myself a coffee after all this.\"";
		std::cin.ignore(2000, '\n');
		std::cout << std::endl;
		std::cout << " " << GM << " starts searching around and after a while...";
		std::cin.ignore(2000, '\n');
		std::cout << std::endl;
		std::cout << " " << GM << ": \"Found it! Take this with you and get out here. Oh, make sure you close the door when you leave.\"" << std::endl;
		std::cout << std::endl;
		std::cout << " ------------------------------------------------------------------------------------" << std::endl << std::endl;
		std::cout << " You got the developer's short form resume!" << std::endl;
		std::cout << " (Press 'Enter' to review)" << std::endl << std::endl;
		std::cin.ignore(2000, '\n');

		std::string content;
		std::ifstream file("Tech_Resume.txt");
		if (file.is_open()) {
			while (getline(file, content))
			{
				std::cout << content << std::endl;
			}
			file.close();
		}
		else {
			std::cout << "\"Oops, unable to open the file. That's embarrassing.\" (>//<)";
		}

		delete[] GM;
	}
}