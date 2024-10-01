#include <iostream>
#include <vector>
//#include <windows.h>  // For Windows
#include <unistd.h> // For Linux

using std::cout, std::vector, std::string, std::endl, std::cin;

class Weapon {
public:
    int type;   // 1: sword 2: wand 3: dagger
    int damage = 1;
    Weapon(int type) {
        this->type = type;
    }
};

class Player{
public:
    int health = 1, regeneration = 1, armor = 1, magicResist = 1, strength = 1, dexterity = 1, stamina = 1;

    // Weapon weapon;
    Player(){}

    // void SetWeapon(Weapon weapon) {
    //     this->weapon = weapon;
    // }
};

void Attack(Player p1, Player p2) {
    if (p1.strength > p2.armor) {
        cout << "St > armor" << endl;
    }
    else if (p1.strength < p2.armor) {
        cout << "St < armor" << endl;
    }
    else {
        cout << "St = armor" << endl;
    }
}

void newRound(int& level) {
    vector<Player> enemies;
    cout << endl << endl << endl;

    for (int i = 0; i < level; i++) {
        Player enemy = Player();
        // Will add skills randomly
    }

    // Fight
    // Drop item

    level++;
}

int main() {
    int level = 1;
    Player user = Player();
    cout << "Welcome to the Game of Life!" << endl << endl;
    sleep(1);
    cout << "Choose your weapon (wand, sword, dagger)" << endl;
    cout << "1: wand, 2: sword, 3: dagger" << endl;
    int choice;
    cin >> choice;
    // user.SetWeapon(choice);
    sleep(1);

    cout << endl << "You have 5 skill points, use them wisely!" << endl;
    cout << "1: health, 2: regen, 3: armor, 4: magic resist, 5: strength, 6: dexterity, 7: stamina" << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". point goes to: ";
        int j;
        cin >> j;

        switch (j) {
            case 1:
                user.health++;
            break;
            case 2:
                user.regeneration++;
            break;
            case 3:
                user.armor++;
            break;
            case 4:
                user.magicResist++;
            break;
            case 5:
                user.strength++;
            break;
            case 6:
                user.dexterity++;
            break;
            case 7:
                user.stamina++;
            break;
            default:
                cout << "Invalid option. Please choose between 1 and 7." << endl;
            i--; // To retry the current point allocation
            break;
        }
    }

    newRound(level);

    return 0;
}
