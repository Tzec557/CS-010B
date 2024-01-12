#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include <string>
#include <vector>

#include "ItemToPurchase.h"

using namespace std;
class ShoppingCart{
    public:
        ShoppingCart();
        ShoppingCart(string, string);

        string customerName()const;
        string date()const;
        void addItem(const ItemToPurchase&);
        void removeItem(string);
        void modifyItem(const ItemToPurchase&);
        int numItemsInCart();
        int costOfCart();
        void printTotal();
        void printDescriptions();



    private:
        string _customerName;
        string _currentDate;
        vector < ItemToPurchase > _cartItems;

};
 #endif