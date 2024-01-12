#include <iostream>
#include <cstdlib>

using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main() {
    SortedSet test1;
    cout << "add 10" << endl;
    test1.add(10);
    cout << "add 20" << endl;
    test1.add(20);
    cout << "add 30" << endl;
    test1.add(30);
    cout << "add 30" << endl;
    test1.add(30);
    cout << "test1: " << test1 << endl;
    cout << test1.in(10) << endl;
    cout << test1.in(0) << endl;

    SortedSet test2;
    cout << "add 10" << endl;
    test2.add(2);
    cout << "add 20" << endl;
    test2.add(6);
    cout << "add 30" << endl;
    test2.add(20);
    cout << "add 30" << endl;
    test2.add(7);
    cout << "test2: " << test2 << endl;

    SortedSet test3;
    test3 = test1 | test2;
    cout << "test3: " << test3 << endl;

    SortedSet test4;
    test4 = test1 & test2;
    cout << "test4: " << test4 << endl;

    SortedSet test5;
    test5 = test1 |= test2;
    cout << "test5: " << test5 << endl;
    cout << "test1: " << test1 << endl;

    SortedSet test6;
    test6 = test1 &= test2;
    cout << "test6: " << test6 << endl;
    cout << "test1: " << test1 << endl;
   


	return 0;
}