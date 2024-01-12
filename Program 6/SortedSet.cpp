#include <iostream>
using namespace std;

#include"SortedSet.h"

//The default constructor initializes an empty set.
SortedSet::SortedSet() : IntList::IntList(){}

//The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor.
SortedSet::SortedSet(const SortedSet &cpy) : IntList::IntList(cpy){}

//A constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList. 
//Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.
SortedSet::SortedSet(const IntList &list) : IntList::IntList(list) {
    IntList::remove_duplicates();
    IntList::selection_sort();
}

//The destructor needs to deallocate all dynamically allocated memory that the IntList destructor will not already deallocate. 
//You may very well find that this function does not need to do anything.
SortedSet::~SortedSet(){}

//This function returns true if the value passed in is a member of the set, otherwise false.
bool SortedSet::in(int value){
    IntNode* curr = head;
    while(curr != nullptr){
        if(curr -> value == value){
            return true;
        }
        curr = curr -> next;
    }
    return false;

}

// This function add two SortedSet into one set without duplicates
SortedSet SortedSet::operator|(const SortedSet &rhs){
    IntNode* curr = rhs.head;
    SortedSet set;
    for(IntNode * n = head; n != nullptr; n = n->next){
        set.add(n -> value);
    }

    while(curr != nullptr){
        if(!in(curr -> value)){
            set.add(curr -> value);
        }
        curr = curr -> next;
    }
    return set;
}

// This function add the same value in two SortedSet into one set 
SortedSet SortedSet::operator&(const SortedSet &rhs){
    IntNode* curr = rhs.head;
    SortedSet set;

    while(curr != nullptr){
        if(this->in(curr -> value)){
            set.add(curr -> value);
        }
        curr = curr -> next;
    }
    return set;
}


//adds the value passed in to the set. It needs to make sure the value does not already exist in the set (no duplicates) and that it is inserted in the proper position (in ascending order).
void SortedSet::add(int value){
    if(!in(value)){
        IntList::insert_ordered(value);
    }
    
}

//Override this function so that it inserts the value in the proper position (in ascending order) only if the value does not already exist in the set (no duplicates).
//In other words, this function should do exactly what add does.
void SortedSet::push_front(int value){
    add(value);
}

//Override this function so that it inserts the value in the proper position (in ascending order) only if the value does not already exist in the set (no duplicates).
void SortedSet::push_back(int value){
    add(value);
}

//Override this function so that it does not insert duplicates.
void SortedSet::insert_ordered(int value){
    add(value);
}

//use operator| and let the left side function(implict funtion) euqal to the result of operator|
SortedSet SortedSet::operator|=(const SortedSet &rhs){
    SortedSet set;
    set = *this | rhs;
    *this = set;

    return *this;
}

//use operator& and let the left side function(implict funtion) euqal to the result of operato &
SortedSet SortedSet::operator&=(const SortedSet &rhs){
    SortedSet set;
    set = *this & rhs;
    *this = set;

    return *this;
}
