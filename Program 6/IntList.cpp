#include <iostream>
using namespace std;

#include"IntList.h"

//Initializes an empty list.
IntList::IntList(): head(nullptr), tail(nullptr){
}

// the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy){
    if(cpy.head == nullptr){
        head = nullptr;
        return;
    }

    head = nullptr;
    tail = nullptr;
    IntNode* n = cpy.head;
    while( n != nullptr){
        push_back(n -> value);
        n = n -> next;
    }

}

//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList(){
    IntNode* front = head;
    IntNode* next;
    while(front != nullptr){
        next = front -> next;
        delete front;
        front = next;
        }
}


//Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value){
    IntNode* temp = new IntNode(value);
    temp -> next = head;
    head = temp;

    if(tail == nullptr){
        tail = temp;
    }
}

//Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
void IntList::pop_front(){
    if(empty()) return;

    IntNode* pf = head;
    head = head -> next;
    delete pf;

    if(head == nullptr){
        tail = nullptr;
    }

}

// Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value){
    IntNode* newNode = new IntNode(value);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}

//Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort(){
    if(head != nullptr){
        for(IntNode* i = head; i != nullptr; i = i -> next){
            IntNode* min = i;
            for(IntNode* j = i -> next; j != nullptr; j = j -> next){
                if(min -> value > j -> value){
                    min = j;
                }
            }
    
            int a = i -> value;
            i -> value = min -> value;
            min -> value = a;
        }
    }
}

// Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) 
// This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location.
// This function may NOT ever sort the list.
void IntList::insert_ordered(int value){
    IntNode* newNode = new IntNode(value);
    if(empty()){
        head = newNode;
        tail = newNode;
    }

    else if(newNode -> value <= head -> value){
        push_front(newNode -> value);
    }

    else if(newNode -> value >= tail -> value){
        push_back(newNode -> value);
    }

    else{
        IntNode* pre;
        IntNode* cur;

        for(pre = head; pre -> next != nullptr; pre = pre -> next){
            cur = pre -> next;
            if(newNode -> value >= pre -> value && newNode-> value <= cur -> value){
                pre -> next = newNode;
                newNode -> next = cur;
                return;
            }
        }
    }
}

//Removes all duplicate data values (actually removes the nodes that contain the values) within the list. 
//Always remove just the later value within the list when a duplicate is found. 
//This function may NOT ever sort the list.
void IntList::remove_duplicates(){
    IntNode* pre;
    IntNode* cur;
    IntNode* i;

    for(i = head; i != nullptr; i = i -> next){
        pre = i;
        while(pre -> next != nullptr){
            if(i -> value == pre -> next -> value){
                cur = pre -> next;
                pre -> next = pre -> next -> next;
                delete cur;

                if(pre -> next == nullptr){
                    tail = pre;
                }
            }
            else{
                pre = pre -> next;
            }
        }
    }
}


//Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const{
    return (head == nullptr);
}

//Returns a reference to the first value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::front() const{
    return head -> value;
}

// Returns a reference to the last value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::back() const{
    return tail -> value;
    
}

//Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list. DO NOT leave them dangling!
void IntList::clear(){
    while(head != nullptr){
        pop_front();
    }
    head = nullptr;
    tail = nullptr;
}

// Overloads the insertion operator (<<) so that it sends to the output stream (ostream) a single line all of the int values stored in the list, each separated by a space. This function does NOT send a newline or space at the end of the line.
ostream & operator<<(ostream &a, const IntList &b){
    IntNode* c = b.head;
    IntNode* next;

    while(c != nullptr){
        next = c -> next;
        a << c -> value;
        c = next;

        if(next != nullptr){
            a << " ";
        }
    }
    return a;
}

//the overloaded assignment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs){
    //this is the address of implicit 
    //&rhs is the address of rhs
    if(this == &rhs){
        return *this;
    }
    else{
        clear();
        IntNode* n = rhs.head;
        
        while( n != nullptr){
            push_back(n -> value);
            n = n -> next;
        }
    }
    return *this;
}

 // Used by selection_sort function.
// Just have this function return nullptr if you don't use this function. 
	IntNode * min(IntNode *){
        return nullptr;
    }
	
	// Used by copy constructor and/or copy assignment operator.
	// Just implement an empty function if you don't use this function.
	void copy(const IntList &){
     
    }