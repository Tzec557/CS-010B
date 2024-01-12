#include"Warrior.h"
#include<iostream>
using namespace std;

Warrior::Warrior(const string &a, double b, double c, string d) : Character(WARRIOR, a, b, c), allegiance(d){
}

void Warrior::attack(Character &opponent){
    if(opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.allegiance == allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else{
            double damage = (health * 1.0 / MAX_HEALTH) * attackStrength;
            opponent.damage(damage);
            cout << "Warrior " << name <<" attacks " << opp.name << " --- SLASH!!" << endl;
            cout << opp.name << " takes " << damage << " damage." << endl;

        }
    }
    else{
        double damage = (health * 1.0 / MAX_HEALTH) * attackStrength;
        opponent.damage(damage);
        cout << "Warrior " << name <<" attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;

    }
}