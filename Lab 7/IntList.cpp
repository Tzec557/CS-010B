#include <iostream>
using namespace std;

#include"IntList.h"

//Initializes an empty list.
IntList::IntList(): head(nullptr), tail(nullptr){
}

//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList(){
    IntNode* front = head;
    IntNode* next;
    while(front != nullptr){
        next = front->next;
        delete front;
        front = next;
        }
}


//Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value){
    IntNode* temp = new IntNode(value);
    temp->next = head;
    head = temp;

    if(tail == nullptr){
        tail = temp;
    }
}

//Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
void IntList::pop_front(){
    if(empty()) return;

    IntNode* pf = head;
    head = head->next;
    delete pf;

    if(head == nullptr){
        tail = nullptr;
    }

}

//Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const{
    return (head == nullptr);
}

//Returns a reference to the first value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::front() const{
    return head->value;
}

// Returns a reference to the last value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::back() const{
    return tail->value;
    
}

// Overloads the insertion operator (<<) so that it sends to the output stream (ostream) a single line all of the int values stored in the list, each separated by a space. This function does NOT send a newline or space at the end of the line.
ostream & operator<<(ostream &a, const IntList &b){
    IntNode* c = b.head;
    IntNode* next;

    while(c != nullptr){
        next = c->next;
        a << c->value;
        c = next;

        if(next != nullptr){
            a << " ";
        }
    }
    return a;
}