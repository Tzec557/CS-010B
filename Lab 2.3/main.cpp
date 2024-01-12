#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS;
   
   inFS.open(inputFile);
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!inFS.is_open()){
      cout << "Could not open file." << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.
   int a;
   char b;
   vector<int> v;
   while(inFS >> a >> b){
      v.push_back(a);
   }
   v.push_back(a);
   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.
   int sum = 0;
   int num = 0;
   int avg;
   for(unsigned int i = 0; i < v.size(); i++){
      sum = sum + v.at(i);
      num += 1;
   }
   avg  = sum / num;
   // Convert each value within vector to be the difference between the original value and the average.
   for(unsigned int i = 0; i < v.size(); i++){
      v.at(i) = v.at(i) - avg;
   }
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS .open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!outFS.is_open()){
      cout << "Could not open file " << outputFile << "." << endl;
      return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned int i = 0; i < v.size(); i++){
      if( i == v.size()-1){
         outFS << v.at(i);
         
      }
      else{
         outFS << v.at(i) << "," ;
      }
   }
   // Close output stream.
   outFS.close();
   return 0;
   
}