/*
Crystal Ding
08/06/2018
main functions
*/

#include "Player.h"
#include "Beamo.h"
#include "Basus.h"

using namespace std;
using namespace RPG;

int main(void) {
	int flag = 1;
	int option = 0;
	char* input = nullptr;

	Player boss("Phanos", 50, 12, 8, 5, 'B');

	cout << " Hello, world!" << endl << endl;
	cout << " 'Bea Project' is a text-based role-playing game. " << endl; 
	cout << " The purpose of this game is to create a fun way to present my code and resume for the upcoming co-op opportunities." << endl << endl;
	cout << " All the conversations are continued by pressing 'Enter' key." << endl; 
	cout << " Try it now!";
	cin.ignore(2000, '\n');
	cout << endl;
	cout << " As a player, you will select your action to defeat the boss 'Phanos' and get the prize from the Gamemaster." << endl;
	cout << " (I know it sounds familiar. " << char (236) << " War 2 is coming!)";
	cin.ignore(2000, '\n');
	cout << endl;
	cout << " Why don't we start with your profession?" << endl << endl;
	cout << "    1. Beamo" << endl;
	cout << "    2. Basus" << endl;
	cout << "    3. Ordinary" << endl << endl;

	while (flag == 1) {
		cout << " Your choice: ";
		input = new char[max_length + 1];
		std::cin.getline(input, max_length + 1);
		std::stringstream is(input);
		cout << endl;

		if (is >> option && is >> input) {
			errorMsg();
		}
		else if (option >= 1 && option <= 3) {
			if (option == 1) {
				Beamo user;
				user.gamePlay(boss);
			}
			else if (option == 2) {
				Basus user;
				user.gamePlay(boss);
			}
			else {
				Player user;
				user.copy_name(user.get_name());
				user.gamePlay(boss);
			}
			flag = 0;
		}
		else {
			errorMsg();
		}
	}

	cout << endl << " (Press 'Enter' to continue)";
	cin.ignore(2000, '\n');
	cout << endl << endl << "    Thank you SOOOOOO much for playing 'Bea Project'!" << endl; 
	cout << "    Please take a few minutes to fill out this survey (the link provided below) to help me improve!" << endl << endl;
	cout << "    https://goo.gl/forms/cPjBMtIpNU3uBIFm2" << endl << endl;
	cout << "    Bye for now~ o(>_<)o" << endl << endl;

	cout << " (Press 'Enter' to exit)";
	cin.ignore(2000, '\n');

	delete[] input;
	return 0;
}