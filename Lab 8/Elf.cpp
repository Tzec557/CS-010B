#include"Elf.h"
#include<iostream>
using namespace std;

Elf::Elf(const string &a, double b, double c, string d) : Character(ELF, a, b, c), fname(d){
}

void Elf::attack(Character &opponent){
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.fname == fname){
            cout << "Elf " << name << " does not attack Elf " << opp.name << "." << endl;
            cout << "They are both members of the " << fname << " family." << endl;
        }
        else{
            double damage = (health * 1.0 / MAX_HEALTH) * attackStrength;
            opponent.damage(damage);
            cout << "Elf " << name << " shoots an arrow at " << opp.name << " --- TWANG!!" << endl;
            cout << opp.name << " takes " << damage << " damage." << endl;
        }
    }
    else{
        double damage = (health * 1.0 / MAX_HEALTH) * attackStrength;
        opponent.damage(damage);
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
        
    }

}