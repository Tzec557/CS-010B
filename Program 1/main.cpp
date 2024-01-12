#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm> 
using namespace std;

void readData(const string &filename, vector<double> &angle, vector<double> &coefficient){
  double ang;
  double coe;
  ifstream inFS;
  
  inFS.open(filename);
  if(!inFS.is_open()){
    cout << "Error opening "  << filename << endl;
    exit(1);
   }

  while(inFS >> ang >> coe){
    angle.push_back(ang);
    coefficient.push_back(coe);
  }
  inFS.close();
}


double interpolation(double ang, const vector<double> &angle, const vector<double> &coefficient){
  double coe;
  double a;
  double c;
  double ac;
  double cc;
  double val;

  if(ang > angle.at(angle.size()-1)){
    exit(1);
    }
  
    for(unsigned int i = 0; i < angle.size(); i++){   
      if(ang == angle.at(i)){
        coe = coefficient.at(i);
        }
      else if(ang > angle.at(i) && ang < angle.at(i+1)){
        a = angle.at(i);
        c = angle.at(i + 1);
        ac = coefficient.at(i);
        cc = coefficient.at(i + 1);
        val = (ang - a)/(c - a);
        coe = ac + val * (cc - ac);
        }
    }
    
    return coe;
}

bool isOrdered(const vector<double> &angle){
  bool a = true;
  unsigned int i;
  unsigned int j;

  if(angle.size() <= 1){
    a = true;
    }
  else{
    for(i = 0; i < angle.size(); i++){
       for(j = i + 1; j < angle.size(); j++){
          if(angle.at(i) > angle.at(j)){
             a = false;
        }
     } 
     }
    }
    return a; 
}

void reorder(vector<double> &angle, vector<double> &coefficient){
  unsigned int i;
  unsigned int j;
  double num;
  double numc;
  for(i = 0; i < angle.size(); i++){
      for(j = i + 1; j < angle.size(); j++){
          if(angle.at(i) > angle.at(j)){
              num =  angle.at(i);
              angle.at(i) = angle.at(j);
              angle.at(j) = num;

              numc =  coefficient.at(i);
              coefficient.at(i) = coefficient.at(j);
              coefficient.at(j) = numc;
            }
        }
    }
}

int main(int argc, char *argv[]){
  string filename;
  vector<double> angle;
  vector<double> coefficient;
  double ang;
  string answer;
  
  filename = argv[1];
  readData(filename, angle,coefficient);
    
  if(isOrdered(angle) == 0 ){
      reorder(angle, coefficient);
    }

  cout << "Enter flight-path angle." << endl;
  cin >> ang;
  cout << interpolation(ang, angle, coefficient) << endl;
  
  
  

  cout << "Do you want to enter another flight-path angle" << endl;
  cin >> answer;

  while(answer != "No"){
    cout << "Enter flight-path angle." << endl;
    cin >> ang;
    cout << interpolation(ang, angle, coefficient) << endl;
  
  
    cout << "Do you want to enter another flight-path angle" << endl;
    cin >> answer;
  }

    return 0;
}