#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);


int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string filename){
   ifstream inFS;
   int sum = 0;
   int num = 0;
inFS.open(filename);

if(!inFS.is_open()){
cout << "Error opening " << filename << endl;
exit(1);
}

while(inFS >> num){
sum += num;
}

inFS.close();

return sum;
}
   