#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
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

    Weapon weapon;  // Weapon object

    // Player constructor that initializes the weapon
    Player(int weaponType) : weapon(weaponType) {}  // Use an initializer list

    // You can still use this if you need to set the weapon later
    void SetWeapon(const Weapon& weapon) {
        this->weapon = weapon;
    }
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

void newRound(int& level, Player& user) {
    cout << endl;
    vector<Player> enemies;

    int skillPoint = std::round(level / 3) + 1;

    for (int i = 0; i < level; i++) {
        srand(static_cast<unsigned int>(time(0)));

        int weaponType = rand() % 3;
        Player enemy = Player(weaponType);

        // Will add skills randomly
        for (int j = 0; j < skillPoint; j++) {
            srand(static_cast<unsigned int>(time(0)));
            int randomSkill = rand() % 7;

            switch (randomSkill) {
                case 0:
                    enemy.health++;
                break;
                case 1:
                    enemy.regeneration++;
                break;
                case 2:
                    enemy.armor++;
                break;
                case 3:
                    enemy.magicResist++;
                break;
                case 4:
                    enemy.strength++;
                break;
                case 5:
                    enemy.dexterity++;
                break;
                case 6:
                    enemy.stamina++;
                break;
                default:
                    break;  // Just a safety net, should never be reached
            }
        }

        enemies.push_back(enemy);
    }

    for (int i = 0; i < enemies.size(); i++) {
        srand(static_cast<unsigned int>(time(0)));
        int turn = rand() % 2; // 0: user, 1: enemy

        bool enemyHasDefeated = false;
        if (turn == 0) {
            cout << "You are attacking first!" << endl;
            switch (user.weapon.type) {
                case 0:
                    if (user.dexterity > enemies[i].magicResist) {
                        cout << "Critical Hit!" << endl;
                        enemies[i].health -= 2;
                        if (enemies[i].health <= 0) {
                            cout << "Enemy has been defeated!" << endl;
                            enemyHasDefeated = true;
                        }
                    }
                    else if(user.dexterity == enemies[i].magicResist) {
                        cout << "Attack successful!" << endl;
                        enemies[i].health -= 1;
                        if (enemies[i].health <= 0) {
                            cout << "Enemy has been defeated!" << endl;
                            enemyHasDefeated = true;
                        }
                    }
                    else {
                        cout << "Attack blocked!" << endl;
                    }
                break;
                case 1:
                    if (user.strength > enemies[i].armor) {
                        cout << "Critical Hit!" << endl;
                        enemies[i].health -= 2;
                        if (enemies[i].health <= 0) {
                            cout << "Enemy has been defeated!" << endl;
                            enemyHasDefeated = true;
                        }
                    }
                    else if (user.strength == enemies[i].armor) {
                        cout << "Attack successful!" << endl;
                        enemies[i].health -= 1;
                        if (enemies[i].health <= 0) {
                            cout << "Enemy has been defeated!" << endl;
                            enemyHasDefeated = true;
                        }
                    }
                    else {
                        cout << "Attack blocked!" << endl;
                    }
                break;
            }
        }

        if (enemyHasDefeated) {
            // Drop item
        }
    }

    level++;
}

int main() {
    int level = 1;
    cout << "Welcome to the Game of Life!" << endl << endl;
    sleep(1);
    cout << "Choose your weapon (wand, sword, dagger)" << endl;
    cout << "1: wand, 2: sword, 3: dagger" << endl;
    int weaponChoice;
    cin >> weaponChoice;
    Player user = Player(weaponChoice);

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


    // Output the final attribute values
    std::cout << "Health: " << user.health << std::endl;
    std::cout << "Regeneration: " << user.regeneration << std::endl;
    std::cout << "Armor: " << user.armor << std::endl;
    std::cout << "Magic Resist: " << user.magicResist << std::endl;
    std::cout << "Strength: " << user.strength << std::endl;
    std::cout << "Dexterity: " << user.dexterity << std::endl;
    std::cout << "Stamina: " << user.stamina << std::endl;

    newRound(level, user);

    return 0;
}
