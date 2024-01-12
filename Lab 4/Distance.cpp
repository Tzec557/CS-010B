#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance(){
     _feet = 0.0;
     _inches = 0.0;
 }
Distance::Distance(unsigned ft, double in){
     _feet = ft;
     _inches = in;
     init();
}

Distance::Distance(double in){
     _inches = in;
     _feet = 0;
     init();
}

unsigned Distance::getFeet() const{
     return _feet;
}

double Distance::getInches() const{
     return _inches;
}

double Distance::distanceInInches() const{
     double disInch = _feet * 12 + _inches;
     return disInch;
}

double Distance::distanceInFeet() const{
     double disFeet = _feet + _inches / 12;
     return disFeet;
}

double Distance::distanceInMeters() const{
     double disMeter = (_feet * 12 + _inches) * 0.0254;
     return disMeter;
}

Distance Distance::operator+(const Distance &rhs) const{
     return Distance(_feet + rhs._feet, _inches + rhs._inches);
}

Distance Distance::operator-(const Distance &rhs) const{
     unsigned a = 0;
     double b =  0;

     if(_feet >= rhs._feet){
          a = _feet - rhs._feet;
          b = _inches - rhs._inches;
          if(_inches < rhs._inches && a != 0){
               a -= 1;
               b += 12 ;
          }
     }
     else if(_feet < rhs._feet){
          a = rhs._feet - _feet;
          b = rhs._inches - _inches;
          if(rhs._inches < _inches){
               a -= 1;
               b += 12;
          }
     }
     return Distance(a,b);
}

ostream & operator<<(ostream &out, const Distance &rhs){
     out << rhs._feet << "\' " <<rhs._inches << "\"";
     return out;
}

void Distance::init(){
     if(_feet < 0){
          _feet *= -1;
     }
     if(_inches < 0){
          _inches *= -1;
     }
     while(_inches >= 12){
          _feet += 1;
          _inches -= 12;
     }
}