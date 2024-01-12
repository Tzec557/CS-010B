#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

void simpletest();
void testat();
void testInsert();
void testErase();
void testPushback();
void testPopback();
void testClear();
void testResize();
void testReserve();
void testAssign();


int main(){
/*
simpletest();
testat();
testInsert();
testErase();
testPushback();
testPopback();
testClear();
testResize();
testReserve();
testAssign();
*/
testInsert();
return 0;
}

void simpletest(){
    IntVector x(5, 1);
    IntVector y(77,102);
    IntVector z(0,0);

    cout << x.size() << endl;
    cout << x.at(x.size() - 1) << endl;
    cout << x.capacity() << endl;
    cout << x.empty()<< endl;
    cout << x.at(4)<< endl;
    cout << x.front()<< endl;
    cout << x.back()<< endl;

    cout << y.size() << endl;
    cout << y.at(y.size() - 1) << endl;
    cout << y.capacity() << endl;
    cout << y.empty()<< endl;
    cout << y.at(4)<< endl;
    cout << y.front()<< endl;
    cout << y.back()<< endl;

    cout << z.empty()<< endl;
}

void testat(){
IntVector x(10, 1);

x.at(9) = 10;
cout << x.at(9) << endl;
cout << x.at(11) << endl;
}

void testInsert(){
    IntVector x(5, 1);
    IntVector y(0,0);
    IntVector z(5,0);

    x.insert(1,3);
    cout << x.at(0) << endl;
    cout << x.at(1) << endl;
    cout << x.at(2) << endl;
    cout << x.size() << endl;
    cout << x.capacity()<< endl;
    
    cout << y.size() << endl;
    y.insert(0, 1);
    cout << y.size() << endl;
    cout << y.capacity()<< endl;

    z.at(0) = 1;
    z.at(1) = 2;
    z.at(2) = 3;
    z.at(3) = 4;
    z.at(4) = 5;

    z.insert(1, 9);
    for(unsigned int i = 0; i < z.size(); i++){
        cout << z.at(i) << endl;
    }
}

void testErase(){
    IntVector x(5, 1);
    IntVector y(1,0);
    IntVector z(5,0);

    x.erase(0);
    cout << x.at(0) << endl;
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    y.erase(0);
    cout << y.size() << endl;
    cout << y.capacity() << endl;

    z.at(0) = 1;
    z.at(1) = 2;
    z.at(2) = 3;
    z.at(3) = 4;
    z.at(4) = 5;

    z.erase(1);
    for(unsigned int i = 0; i < z.size(); i++){
        cout << z.at(i) << endl;
    }
   

    
}

void testPushback(){
    IntVector x(5, 1);
    IntVector y(1,0);
    IntVector z(0,0);

    x.push_back(0);
    cout << x.back() << endl;
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    y.push_back(8);
    cout << y.back() << endl;
    cout << y.size() << endl;
    cout << y.capacity() << endl;

    z.push_back(10);
    cout << z.back() << endl;
    cout << z.size() << endl;
    cout << z.capacity() << endl;
}

void testPopback(){
    IntVector x(5, 1);
    IntVector y(1,0);
    IntVector z(0,0);

    x.pop_back();
    cout << x.back() << endl;
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    y.pop_back();
    cout << y.back() << endl;
    cout << y.size() << endl;
    cout << y.capacity() << endl;

    z.pop_back();
    cout << z.back() << endl;
    cout << z.size() << endl;
    cout << z.capacity() << endl;
}

void testClear(){
    IntVector x(5, 1);
    IntVector y(1,0);
    IntVector z(0,0);

    x.clear();
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    y.clear();
    cout << y.size() << endl;
    cout << y.capacity()<< endl;

    z.clear();
    cout << z.size() << endl;
    cout << z.capacity() << endl;
}

void testResize(){
    IntVector x(5, 1);
    IntVector y(1,0);
    IntVector z(0,0);

    x.resize(8, 10);
    cout << x.back() << endl;
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    y.resize(0, 0);
    cout << y.size() << endl;
    cout << y.capacity()<< endl;

    z.resize(100, 9);
    cout << z.size() << endl;
    cout << z.capacity() << endl;
}

void testReserve(){
    IntVector x(5, 1);
    IntVector y(1,0);
    IntVector z(20,0);

    cout << x.capacity() << endl;
    x.reserve(8);
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    cout << y.capacity()<< endl;
    y.reserve(0);
    cout << y.size() << endl;
    cout << y.capacity() << endl;

    cout << z.capacity() << endl;
    z.reserve(30);
    cout << z.size() << endl;
    cout << z.capacity() << endl;
}

void testAssign(){
    IntVector x(5, 1);
    IntVector y(2,0);
    IntVector z(0,0);

    cout << x.capacity() << endl;
    x.assign(8, 9);
    cout << x.back() << endl;
    cout << x.size() << endl;
    cout << x.capacity() << endl;

    cout << y.capacity() << endl;
    y.assign(1, 1);
    cout << y.back() << endl;
    cout << y.size() << endl;
    cout << y.capacity() << endl;

    cout << z.capacity() << endl;
    z.assign(100, 9);
    cout << z.back() << endl;
    cout << z.size() << endl;
    cout << z.capacity() << endl;
}