#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int denom); 
      Rational(int numer, int denom ); 
      Rational add(const Rational &other) const; 
      Rational subtract(const Rational &other) const; 
      Rational multiply(const Rational &other) const; 
      Rational divide(const Rational &other) const;
      void simplify();
      void display() const;
   private:
      int gcd(int numer, int denom) const;
};

// Implement Rational class member functions here
Rational::Rational(){
   numerator = 0;
   denominator = 1;
}

Rational::Rational(int numer){
   numerator = numer;
   denominator = 1;
}

Rational::Rational(int numer, int denom){
   numerator = numer;
   denominator = denom;

}

Rational Rational::add(const Rational &other) const{
   int resultn = numerator * other.denominator + other.numerator * denominator;
   int resultd = denominator * other.denominator;
   return Rational(resultn,resultd);
}

Rational Rational::subtract(const Rational &other) const{
   int resultn = numerator * other.denominator - other.numerator * denominator;
   int resultd = denominator * other.denominator;
   return Rational(resultn,resultd);
}

Rational Rational::multiply(const Rational &other) const{
   int resultn = numerator * other.numerator;
   int resultd = denominator * other.denominator;
   return Rational(resultn,resultd);
}

Rational Rational::divide(const Rational &other) const{
   int resultn = numerator * other.denominator;
   int resultd = denominator * other.numerator;
   return Rational(resultn,resultd);
}
int Rational::gcd(int numer, int denom) const{
   int a;
   if(numer == 0){
      a = denom;
}
   if(denom == 0){
      a =  numer;
}
   if(numer == denom){
      a = numer;
}
   if(numer > denom){
      a = gcd(numer - denom, denom);
}
   if(numer < denom){
      a = gcd(numer, denom - numer);
}
return a;
}

void Rational::simplify(){
   int g = gcd(numerator,denominator);
   numerator = numerator / g;
   denominator = denominator / g;
   
}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

