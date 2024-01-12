#include"Character.h"
using namespace std;

Character::Character(HeroType a, const string &b, double c, double d) : type(a), name(b), health(c), attackStrength(d){
}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return health;
}

/* Reduces health value by amount passed in. */
void Character::damage(double d){
    health -= d;
}

 /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const{
    return(this->getHealth() > 0);
}

void Character::attack(Character &){

}