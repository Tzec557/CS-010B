#include "IntList.h"
#include <algorithm>

bool IntList::bubbleUp() {
   if(head != nullptr){
      return bubbleUp(head);
   }
   
   return false;
}

bool IntList::bubbleUp(IntNode *curr) {
   bool swapped;
   if(curr == nullptr){
      return false;
   }
   
   if(curr -> next == nullptr){
      return false;
   }

   swapped = bubbleUp(curr -> next);
   if(curr -> value > curr -> next -> value){
      swap(curr -> value, curr -> next -> value);
      swapped = true;
   }
   
   return swapped;
}
