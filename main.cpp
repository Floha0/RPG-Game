#include <iostream>
#include <vector>

using std::cout, std::vector, std::string, std::endl;

class Player {
public:
    float health;
    float armor;
    float strength;

    Player(float health, float armor, float strength) {
        this->health = health;
        this->armor = armor;
        this->strength = strength;
    }
};

void Attack(Player p1, Player p2) {

}

int main() {

    Player user = Player(25, 50, 50);
    cout << user.health;

    return 0;
}
