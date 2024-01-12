#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"
/*IntVector::IntVector(){
    _size = 0;
    _capacity = 0;
    _data = nullptr;
}

IntVector::IntVector(unsigned capacity){
    _size = capacity;
    _capacity = capacity;
    _data = new int[capacity];
}
*/

IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;
    _data = new int[_capacity];
    
    if(capacity > 0){
        for(unsigned int i = 0; i < capacity; i++){
            _data[i] = value;
        }
    }
    
}

IntVector::~IntVector(){
    delete [] _data;
}

//This function returns the current size (not the capacity) of the IntVector object, which is the values stored in the _size member variable.
unsigned IntVector::size() const{
    return _size;
}

//This function returns the current capacity (not the size) of the IntVector object, which is the value stored in the _capacity member variable
unsigned IntVector::capacity() const{
    return _capacity;
}

//Returns whether the IntVector is empty (_size is 0).
bool IntVector::empty() const{
    return (_size == 0);
}

//This function will return the value stored in the element at the passed in index position. 
//Your function should throw an outofrange exception if an invalid index is passed in. An invalid index is an index greater than or equal to the size.
const int & IntVector::at(unsigned index) const{
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
   return _data[index];
}

int & IntVector::at(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
   return _data[index];
}

//This function will return the value stored in the first element of the IntVector. 
//This function does not check the size of the IntVector or the array. If the IntVector is empty then calling this function causes undefined behavior.
const int & IntVector::front() const{
    return _data[0];
}

int & IntVector::front(){
    return _data[0];
}
//This function will return the value stored in the last element of the IntVector. 
//This function does not check the size of the IntVector or the array. If the IntVector is empty then calling this function causes undefined behavior.
const int & IntVector::back() const{
    return _data[_size - 1];
}

int & IntVector::back(){
    return _data[_size - 1];
}
//This function will double the capacity of the vector. 
//This function should reallocate memory for the dynamically allocated array and update the value of capacity. 
void IntVector::expand(){
    if(_capacity == 0){
        _capacity = 1;
    }

    else{
        _capacity *= 2;
    }
    int* newdata = new int[_capacity];

    for(unsigned int i = 0; i < _size; i++){
        newdata[i] = _data[i];
    }

    _data = newdata;
}

//This function should reallocate memory for the dynamically allocated array and update the value of capacity.
void IntVector::expand(unsigned amount){
    _capacity += amount;
    int* newdata = new int[_capacity];

    for(unsigned int i = 0; i < _size; i++){
        newdata[i] = _data[i];
    }

    _data = newdata;

}

//Size will be increased by 1
//expand (double) the capacity, if size will become larger than capacity.
void IntVector::insert(unsigned index, int value){
    _size++;
    if(index < _size){
        if(_size > _capacity){
            expand();
            }
        for(unsigned int i = _size - 1; i > index; i--){
            _data[i] = _data[i - 1];
            }
        _data[index] = value;
    }
   
    else{
        throw out_of_range("IntVector::insert_range_check");
    }
}

//Size is decreased by 1.
//removes the value at position index and shifts all of the values at positions greater than index to the left by one
void IntVector::erase(unsigned index){
    if(index < _size){
        for(unsigned int i = 0; i < _size; i++){
         if(i > index){
            _data[i-1] = _data[i];
         }
       }
       _size--;
   }
    
    else{
        throw out_of_range("IntVector::erase_range_check");
    }
}

//This function inserts a value at the back end of the array.
//expand (double) the capacity, if size will become larger than capacity.
void IntVector::push_back(int value){
    if(_size + 1 > _capacity){
        expand();
    }
    _size++;
     _data[_size - 1] = value;
    
}

// decrease size by 1.
void IntVector::pop_back(){
    if(_size != 0){
      _size--;  
    }

}

//This function reduces the size of the vector to 0.
void IntVector::clear(){
    _size = 0;
}

//resizes the vector to contain size elements.
//If size is smaller than the current size(_size), this function just reduces the value of _size to size.
//If size is greater than the current size(_size), then the appropriate number of elements are inserted at the end of the vector, giving all of the new elements the value passed in through the 2nd parameter (value).
//expand (double) the capacity, if size will become larger than capacity.
void IntVector::resize(unsigned n, int value){
    if(n < _size){
        _size = n;
    }
    if(n >= _size){
        if(n > _capacity){
            if(n < _capacity * 2){
                expand();
            }
            else{
                expand(n - _capacity);
            }
        }
        for(unsigned int i = _size; i < n; i++){
                _data[i] = value;
            }
        _size = n;
    }
}

//capacity be set to n at minimum, should NOT ever reduce the size of the vector
//If n is larger than the current capacity then the capacity should be expanded to n.
void IntVector::reserve(unsigned n){
    if(n > _capacity){
            expand(n - _capacity);
        }
}

//Assigns new content to the vector object, if the new value of size will be larger than capacity, then this function must first expand capacity
void IntVector::assign(unsigned n, int value){
   _size = n;
    if(n > _capacity){
        if(n < _capacity * 2){
            expand();
        }
        else{
            expand(n - _capacity);
        }
    }
    for(unsigned int i = 0; i < n; i++){
        _data[i] = value;
    }
}
