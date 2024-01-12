#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
    This function does NOT output a newline or space at the end.
*/
ostream & operator<<(ostream & os, const IntList & list) {
    return operator<<(os, list.head);
}

/* Returns true if the integer passed in is contained within the IntList.
    Otherwise returns false.
*/
bool IntList::exists(int value) const {
    return exists(head, value);
}

/* Helper function that returns true if the integer passed in is contained within
    the IntNodes starting from the IntNode whose address is passed in.
    Otherwise returns false.
*/
bool IntList::exists(IntNode* node, int value) const {
    if (node == nullptr) {
        return false;
    }
    if (node->value == value) {
        return true;
    }
    return exists(node->next, value);
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream & os, IntNode* node) {
    if (node != nullptr) {
        os << node->value;
        
        if(node->next != nullptr){
            os << " " << node->next;
        }
    }
    return os;
}