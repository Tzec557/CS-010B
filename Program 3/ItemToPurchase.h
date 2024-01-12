#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include<string>

using namespace std;
class ItemToPurchase{
    public:
        ItemToPurchase();
        ItemToPurchase(string, string, int, int);

        void setName(string );
        void setDescription( string );
        void setPrice( int );
        void setQuantity( int );
        //getDescription
        string name()const;
        int price()const;
        int quantity()const;
        string description()const;

        void printItemCost()const;
        void printItemDescription()const;

    private:
        string _name;
        string _description;
        int _price;
        int _quantity;

        };
        #endif
