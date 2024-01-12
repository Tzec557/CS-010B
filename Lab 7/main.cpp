#include <iostream>
using namespace std;

#include "IntList.h"

void testPushFront();
void testPopFront();
void testEmpty();
void testFront();
void testBack();

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   {
   
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pushfront 100" << endl;
      list1.push_front(100);
      cout << "pushfront 200" << endl;
      list1.push_front(200);
      cout << "pushfront 300" << endl;
      list1.push_front(300);
      cout << "list1: " << list1 << endl;
      cout << endl;
      cout << "Calling list1 destructor..." << endl;
   
     /*
      testPushFront();
      testPopFront();
      testEmpty();
      testFront();
      testBack();
     */
     
   }
   cout << "list1 destructor returned" << endl;
   
   // Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
   
   return 0;
}

void testPushFront(){
   IntList test1;
   test1.push_front(1);
   test1.push_front(2);
   test1.push_front(3);
   test1.push_front(4);

   cout << "test1: " << test1 << endl;
}
void testPopFront(){
   IntList test1;
   test1.push_front(1);
   test1.push_front(2);
   test1.push_front(3);
   test1.push_front(4);
   
   cout << "test1: " << test1 << endl;
   test1.pop_front();
   cout << "test1: " << test1 << endl;
   test1.pop_front();
   cout << "test1: " << test1 << endl;
   test1.pop_front();
   cout << "test1: " << test1 << endl;

}
void testEmpty(){
   IntList test1;

   cout << test1.empty() << endl;
   test1.push_front(1);
   cout << test1.empty() << endl;
   
   cout << "test1: " << test1 << endl;
}
void testFront(){
   IntList test1;

   test1.push_front(1);
   test1.push_front(2);
   cout << test1.front() << endl;
   cout << "test1: " << test1 << endl;

   test1.push_front(3);
   test1.push_front(4);
   
   cout << test1.front() << endl;
   cout << "test1: " << test1 << endl;
   
}
void testBack(){
   IntList test1;

   test1.push_front(1);
   test1.push_front(2);
   cout << test1.back() << endl;
   cout << "test1: " << test1 << endl;
}