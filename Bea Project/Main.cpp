#include "Player.h"

using namespace std;
using namespace RPG;

int main(void) {
	
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
	cout << " Why don't we start with your name?" << endl;
	cout << endl;

	Player reg_player;
	cin >> reg_player;
	cout << reg_player;

	Player boss("Phanos", 50, 12, 8, 5, 'B');
	cout << boss;

	cout << " ----------------------" << endl;
	cout << "      Game Starts!     " << endl;
	cout << " ----------------------" << endl;

	reg_player * boss;
	cout << endl;

	if (!reg_player.alive() && boss.alive()) {
		if (reg_player.hp() != -99) {
			cout << " ------------------------" << endl;
			cout << "    Game Over... (X_X)   " << endl;
			cout << " ------------------------" << endl;
		}
	}
	else if (reg_player.alive() && !boss.alive()) {
		cout << " ------------------------" << endl;
		cout << "     You win! \\(^_^)/   " << endl;
		cout << " ------------------------" << endl;
		cout << endl << endl;
		reg_player.prize();
	}
	else {
		cout << " ------------------------" << endl;
		cout << "        Draw (=_=)       " << endl;
		cout << " ------------------------" << endl;
	}

	cout << endl << " (Press 'Enter' to continue)";
	cin.ignore(2000, '\n');
	cout << endl << endl << "    Thank you SOOOOOO much for playing 'Bea Project'!" << endl; 
	cout << "    Please take a few minutes to fill out this survey (the link provided below) to help me improve!" << endl << endl;
	cout << "    https://goo.gl/forms/cPjBMtIpNU3uBIFm2" << endl << endl;
	cout << "    Bye for now~ o(>_<)o" << endl << endl;
	cout <<" (Press 'Enter' to exit)";
	cin.ignore(2000, '\n');
	
	return 0;
}