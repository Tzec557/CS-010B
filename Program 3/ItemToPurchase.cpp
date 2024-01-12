#include <iostream>
#include<string>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
    _name = "none";
    _description = "none";
    _price = 0;
    _quantity = 0;

}
ItemToPurchase::ItemToPurchase(string name , string description, int price, int quantity){
    _name = name;
    _description = description;
    _price = price;
    _quantity = quantity; 
}

void ItemToPurchase::setName(string name){
    _name = name;
}

void ItemToPurchase::setDescription( string description){
    _description = description;

}

void ItemToPurchase::setPrice( int price){
    _price = price;

}

void ItemToPurchase::setQuantity( int quantity){
    _quantity = quantity;
}

string ItemToPurchase::name()const{
    return _name;
}

string ItemToPurchase::description()const{
    return _description;
}

int ItemToPurchase::price()const{
    return _price;
}

int ItemToPurchase::quantity()const{
    return _quantity;
}


//Outputs the item name followed by the quantity, price, and subtotal
//FIXME subtotal
void ItemToPurchase::printItemCost()const{
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _price *  _quantity << endl;
    }
 //Outputs the item name and description
void ItemToPurchase::printItemDescription()const{
    cout <<  _name << ": " << _description << endl;
    }