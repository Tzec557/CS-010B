#include <iostream>
#include <string>

using namespace std;

#include "ShoppingCart.h"


void printMenu();

int main(){
string cName;
string cDate;

cout << "Enter customer's name: " << endl;
getline(cin,cName);

cout << "Enter today's date: " << endl;
getline(cin,cDate);
cout << endl;

ShoppingCart sc(cName, cDate);

cout << "Customer name: " << cName << endl;
cout << "Today's date: " << cDate << endl;
cout << endl;


ItemToPurchase itp;
char opt = 'b';

string itemname;
string itemdesc;
int itemP;
int itemQ;

string rm;
string newN;
int newQ;


bool menu = false;
while(opt != 'q'){
    if(menu == false){
        printMenu();
    }

    cout << "Choose an option: " << endl;
    cin >> opt;

    if(opt == 'o'){
        cout << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        sc.printTotal();
    }

    else if(opt == 'i'){
        cout << endl;
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        sc.printDescriptions();
        cout << endl;
    }

    else if(opt == 'a'){
        cout << endl;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name: " << endl;
        getline(cin,itemname);
        getline(cin,itemname);
        itp.setName(itemname);

        cout << "Enter the item description: " << endl;
        getline(cin, itemdesc);
        itp.setDescription(itemdesc);

        cout << "Enter the item price: " << endl;
        cin >> itemP;
        itp.setPrice(itemP);

        cout << "Enter the item quantity: " << endl;
        cin >> itemQ;
        itp.setQuantity(itemQ);

        sc.addItem(itp);
        cout << endl;
    }

    else if(opt == 'd'){
        cout << endl;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove: " << endl;
        getline(cin, rm);
        getline(cin, rm);

        sc.removeItem(rm);
        cout << endl;
        }
        
    else if(opt == 'c'){
        cout << endl;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name: " << endl;
        
        getline(cin, newN);
        getline(cin,newN);
        itp.setName(newN);

        cout << "Enter the new quantity: " << endl;
        cin >> newQ;
        itp.setQuantity(newQ);

        sc.modifyItem(itp);
        cout << endl;
    }
    else{
        if(opt != 'q'){
            menu = true;
        }

    }

    }
    



}
void printMenu(){
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}