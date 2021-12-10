#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;
void Shop();
void Monster();
void GhostF();
string inventory[10];

int health = 100;
int gold = 10;

int main() {

    int room = 1;
    char input;
    int bones = 0;



    cout << "You get isekai and you wake up in a dungeon" << endl;

    do {
        for (int i = 0; i < 10; ++i)
            cout << inventory[i] << " ";
        cout << "health" << health << endl;

        cout << "gold" << gold << endl;
        //Set up a visible inventory & health counter & possible money counter

        switch (room) {
            //add items to be able to pick up
            //work on story and spelling a bit more 
        case 1:

            system("Color d0");

            cout << "You look around and you see alter it seems look you could put something in there. You see a small Door to the South. There is also a shop enter M" << endl;
            cin >> input;
            if (input == 'S')
                room = 2;
            else if (input == 'M')
                Shop();
            else if (input == 'P')
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
            if (input == 'P') {
                if (inventory[3].compare("Water") != 0) {
                    cout << "You need a source of water to activate the portal." << endl;
                    room = 4;
                }
                else if (input == 'W')
                    inventory[3] = "Water";
                else
                    cout << "sorry, not an option." << endl;
                break;
        case 4:
            cout << "You are in room 4. You can go South." << endl;
            cin >> input;
            if (input == 'S')
                room = 5;
            else
                cout << "sorry, not an option." << endl;
            break;

        case 5:
            cout << "You are in room 5. You can go South." << endl;
            cin >> input;
            if (input == 'S')
                room = 6;
            else
                cout << "sorry, not an option." << endl;
            break;
        case 6:
            cout << "You are in room 6. You can go South." << endl;
            cin >> input;
            if (input == 'S')
                room = 7;
            else
                cout << "sorry, not an option." << endl;
            break;
        case 7:
            cout << "You are in room 7. You can go East." << endl;
            cin >> input;
            if (input == 'E')
                room = 8;
            else
                cout << "sorry, not an option." << endl;
            break;
        case 8:
            cout << "You are in room 8. You can go South." << endl;
            cin >> input;
            if (input == 'S')
                room = 9;
            else
                cout << "sorry, not an option." << endl;
            break;
        case 9:
            cout << "You are in room 9. You can go East." << endl;
            cin >> input;
            if (input == 'E')
                room = 10;
            else
                cout << "sorry, not an option." << endl;
            break;
        case 10:
            cout << "You are in room 10. You run into a boss.." << endl;
            cout << "The end" << endl;
            break;
            }
        }
    } while (input != 'q' && health > 0);
    if (health <= 0) {
        cout << "You have let down you family" << endl;
    }
}


void Shop() {

    string input;
    do {
        cout << "Hello! Welcome to my teleporting shop!" << endl;
        cout << "Press 'H' for a Heath potion, 'K' for a katana, and 'S' for Skull." << endl;
        cin >> input;
        if (input == "H") { //change items in shop &  add money variable
            inventory[0] = "Health potion";
        }
        else if (input == "K")
            inventory[1] = "katana";
        else if (input == "S")
            inventory[2] = "Skull";
        else
            cout << "";

    } while (input != "q");

}

void Monster() {

    int num = rand() % 100 + 1;
    if (num <= 20) {
        cout << "A emberwings scratches you!" << endl << endl;
        health -= 15;
        cout << "Health: " << health << endl;
        gold += 10;
    }
    else if (num <= 50) {
        cout << "A blazefoot use a fire attack " << endl << endl;
        health -= 15;
        cout << "Health: " << health << endl;
        gold += 10;

    }
    else if (num <= 90) {
        cout << "A phaseseeker mentals attacks you!" << endl << endl;
        health -= 15;
        cout << "Health: " << health << endl;
        gold += 10;
    }
    else {
        cout << "GhostF says hi" << endl << endl;
        GhostF();
    }
}

void GhostF() {
    cout << "" << endl;
}

