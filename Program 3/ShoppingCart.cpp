//Class definition
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
    _customerName = name;
    _currentDate = date;
}

string ShoppingCart::customerName()const{
    return _customerName;
}

string ShoppingCart::date()const{
    return _currentDate;
}

//Adds an item to cart items vector. 
void ShoppingCart::addItem(const ItemToPurchase &a){
    _cartItems.push_back(a);
}

//Removes item from cart items vector. Has a parameter of type string (an item's name). 
//If item name cannot be found, output this message: Item not found in cart. Nothing removed.
void ShoppingCart::removeItem(string x){
    bool found = false;

    for(unsigned int i = 0; i < _cartItems.size(); i++){
        if(x == _cartItems.at(i).name() ){
             _cartItems.erase(_cartItems.begin() + i);
             found = true;
        }
    }
    if(!found){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

/* Modifies an item's description, price, and/or quantity. Has a parameter of type ItemToPurchase. Does not return anything.

If item can be found (by name) in cart, check if parameter variable has default values for description, price, and/or quantity. 

For each of the non-default values in parameter, set the item in the cart to the non-default value. 

For example, if the parameter has non-default values for quantity and price but a default value for the description, 
then just set the quantity and price in the cart item to the parameter's values for quantity and price and leave the cart item's description alone.

If item cannot be found (by name) in cart, output this message: Item not found in cart. Nothing modified.*/
void ShoppingCart::modifyItem(const ItemToPurchase &a){
    bool found = false;

    for(unsigned int i = 0; i < _cartItems.size(); i++){
    if(_cartItems.at(i).name() == a.name()){
        _cartItems.at(i).setQuantity(a.quantity());
        found = true;
    }
    }

    if(!found){
    cout << "Item not found in cart. Nothing modified." << endl;
    }
}

//Returns quantity of all items in cart. Has no parameters.
int ShoppingCart::numItemsInCart(){
    int numItem = 0;
    for(unsigned int i = 0; i < _cartItems.size(); i++){
        numItem += _cartItems.at(i).quantity();

    }
    return numItem;
}
//Determines and returns the total cost of items in cart. Has no parameters.
int ShoppingCart::costOfCart(){
    double cost = 0;
    for(unsigned int i = 0; i < _cartItems.size(); i++){
        cost += (_cartItems.at(i).quantity()) * (_cartItems.at(i).price());

    }
    return cost;
}
//Outputs total of objects in cart.
//If cart is empty, output this message: SHOPPING CART IS EMPTY
void ShoppingCart::printTotal(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    
    if(_cartItems.size() == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl;
        cout << "Total: $0" << endl;
        cout << endl;
    }
    else{
    for(unsigned int i = 0; i < _cartItems.size(); i++){
        _cartItems.at(i).printItemCost();
    }
    cout << endl;
    cout << "Total: $" << costOfCart() << endl;
    cout << endl;
    }
}

//Outputs each item's description.
void ShoppingCart::printDescriptions(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;

    for(unsigned int i = 0; i < _cartItems.size(); i++){
        _cartItems.at(i).printItemDescription();
    }
}