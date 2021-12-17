#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;
void Shop();
void Monster();
void GhostF();
string inventory[10];
int bones = 0;
int health = 100;
int gold = 10;

int main() {

	int room = 1;
	char input;






	do {
		for (int i = 0; i < 10; ++i)
			cout << inventory[i] << " ";



		cout << "health" << health << endl;
		cout << "gold" << gold << endl;
		cout << "bones" << bones << endl;
		//Set up a visible inventory & health counter & possible money counter

		switch (room) {
			//add items to be able to pick up
			//work on story and spelling a bit more 
		case 1:

			system("Color d0");

			cout << "You got isekai and you wake up in a dungeon" << endl;

			cout << "You look around and you see alter it seems look you could put something in there. You see a small Door to the South. There is also a teleporting merchant enter M" << endl;
			cin >> input;
			if (input == 'S')
				room = 2;
			else if (input == 'M')
				Shop();
			else if (input == 'A')
				GhostF();
			else
				cout << "sorry, not a option." << endl;
			break;
		case 2:

			system("Color e8");

			cout << "You walk into a dim room you see a window and further South you see an open." << endl;
			cin >> input;
			if (input == 'S')
				room = 3;
			else if (input == 'W')
				cout << "you tried jumping to window but its 10 feet above you. " << endl;
			else
				cout << "sorry, not an option." << endl;
			break;
		case 3:
			cout << "As you walk towards the opening you see sand on the ground you walk into a desert type area." << endl;
			cout << " You find a oasis there's a body of water.You see a Portal." << endl;
			cin >> input;

			if (input == 'W') {
				inventory[3] = "Water";
				cout << "you acquired water you can now activate the portal" << endl;
			}

			else if (input == 'P') {
				if (inventory[3].compare("Water") == 0)
				{

					cout << "you activated the portal. you jump through and appear in a cave." << endl;
					room = 4;
				}
				else
					cout << "sorry, not an option." << endl;
			}
			break;
		case 4:
			cout << "You appear in a cave there is a pillars holding you the cave. You can go South." << endl;
			cin >> input;
			if (input == 'S')
				room = 5;
			else if (input == 'P')
				cout << " You rub the pillar questioning when they were made and who made them" << endl;
			else
				cout << "sorry, not an option." << endl;
			break;

		case 5:

			system("Color e2");
			Monster();

			cout << "You walk into the open and you see a open field you also see some mosters. You can go South." << endl;
			cin >> input;
			if (input == 'S')
				room = 6;
			else if (input == 'M')
				Shop();
			else if (input == 'W')
				cout << "You wait in the great plains" << endl;
			else
				cout << "sorry, not an option." << endl;
			break;
		case 6:
			cout << "You stumble upon a villige and you think you yourselve you could anakin skywaker all these people or you can go South." << endl;
			cin >> input;
			if (input == 'S')
				room = 7;
			else if (input == 'A') {
				cout << "You killed all the children in the village..." << endl;
				cout << " " << endl;
				cout << "What's wrong with you" << endl;
				bones += 50;
				cout << "Bones: " << bones << endl;
				room = 7;
			}
			else
				cout << "sorry, not an option." << endl;
			break;
		case 7:
			cout << "You climb a mountian and on the top you see the teleporting merchant from eariler. You could go Down on the other side." << endl;
			cin >> input;
			if (input == 'D')
				room = 8;
			else if (input == 'M')
				Shop();
			else
				cout << "sorry, not an option." << endl;
			break;
		case 8:
			cout << "You see a sign before entering a forest the sign it says beware the aimless forest. You can walk around aimlessly until you find a exit or look around ." << endl;
			cout << "You can walk around aimlessly until you find a exit or look around." << endl;
			cin >> input;
			if (input == 'W')
				room = 9;
			else if (input == 'L') {
				cout << "you look around and find a body" << endl;
				bones += 20;
				cout << "Bones: " << bones << endl;
			}
			else
				cout << "sorry, not an option." << endl;
			break;
		case 9:
			cout << "You enter abandoned outpost and the first thing you see is a Portal (input P for portal) as you look around you find a lock door leading to an caestle to the east (Input E to mess with door) (Input L to look around)" << endl;
			cin >> input;
			if (input == 'E')
				room = 10;
      else if (input == 'L') {
				inventory[4] = "Rusty key";
				cout << " while looking around you found a you accidently step on a brick " << endl;
      }
      else if (input == 'E') {
				if (inventory[3].compare("Water") == 0)
				{

					cout << "you open the door and start heading towards the castle " << endl;
					room = 10;
				} 
      }
      else if (input == 'P'){
          cout << "You decide to go throught the portal and go unconscious immediately" << endl;
          room = 1;
      }      
			else
				cout << "sorry, not an option." << endl;
			break;
		case 10:
			cout << "You enter the castle and you see a king. The king look at your past endeavors and he said he'll decide you faith" << endl;
      if (bones >= 0){
        cout << "The king have decied to have you hung" << endl;
        health -= 100;
      }
      else if (bones <= 0){
        cout << "The king have decied to have you let you live you life in peace. You become one of his vessals." << endl;
        room= 11;
      } 
			
			break;

    case 11:
    cout<< "You have beat the game play again sometime" << endl;
    return 0;   

		}//end switch
	} while (input != 'q' && health > 0);//end game loop
	if (health <= 0) {
		cout << "You have let down you family" << endl;
	}
}//end main

void Shop() {

	string input;
	do {
		cout << "Hello! Welcome to my teleporting shop!" << endl;
		cout << "Press 'H' for a Heath potion (cost:10 gold), 'K' for a katana (cost:20 gold), and 'S' for Skull (cost:50 gold). Press 'L' to leave the shop" << endl;
		cin >> input;
		if (input == "H") { //change items in shop &  add money variable
			inventory[0] = "Health potion";
			gold -= 10;
		}
		else if (input == "K") {
			inventory[1] = "katana";
			gold -= 20;
			cout << "You bought a cool looking katana it's pretty much useless but at least it looks cool." << endl;
		}
		else if (input == "S") {
			inventory[2] = "Skull";
			gold -= 50;
      bones += 30;
      if (gold <= 50){
        cout << "You dont have enough money" << endl;
      }
			cout << "You now have the skull of a child. The shop keeper questions your sanity" << endl;
		}
		else
			cout << " There's nothing else just leave.";

	} while (input != "L");

}


void Monster() {

	int num = rand() % 100 + 1;
	if (num <= 20) {
		cout << "A emberwings scratches you!" << endl << endl;
		health -= 15;
		cout << "Health: " << health << endl;
		gold += 25;
	}
	else if (num <= 50) {
		cout << "A blazefoot use a fire attack " << endl << endl;
		health -= 15;
		cout << "Health: " << health << endl;
		gold += 25;

	}
	else if (num <= 90) {
		cout << "A phaseseeker mentals attacks you!" << endl << endl;
		health -= 15;
		cout << "Health: " << health << endl;
		gold += 25;
	}
	else {
		cout << "GhostF says hi" << endl << endl;
		GhostF();
	}
}

void GhostF() { //A alternate ending & secret ending.
	if (bones <= 0) {
		cout << " -.-- --- ..- / -.. --- -. .----. - / .... .- ...- . / - .... . / .-. .. --. .... - / .-. . --.- ..- .. .-. . -- . -. - ... " << endl;

	}
	if (bones >= 100) {
		cout << "-.-- --- ..- / .... .- ...- . / .- -.-. --.- ..- .. .-. . -.. / .- .-.. .-.. / --- ..-. / - .... . / -. . . -.. . -.. / .--. .- .-. - ... / -. --- .-- / --. --- / -... .- -.-. -.- / - --- / - .... . / .- .-.. - . .-. / -... -.-- / .. -. .--. ..- - - .. -. --. / .----. -.. .----." << endl;
	}
}


