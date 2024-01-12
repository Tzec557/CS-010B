#include"Wizard.h"
#include<iostream>
using namespace std;

Wizard::Wizard(const string &a, double b, double c, int d) : Character(WIZARD, a, b, c), rank(d){
}
void Wizard::attack(Character &opponent){
    
    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        /*When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.*/
        double damage = attackStrength * (rank * 1.0 / opp.rank);
        opponent.damage(damage);
        cout << "Wizard " << name << " attacks " << opp.name <<" --- POOF!!" << endl;
        cout << opp.name << " takes " << damage << " damage." << endl;
    }
    else{
        /*The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.*/
        double damage = attackStrength;
        opponent.damage(damage);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
   

}
