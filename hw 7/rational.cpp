/* Daniel Chai
 * June 1st, 2017
 * Implementation of rational number type
 * CSE 374 HW7, 17wi
 */
#include <stdlib.h>
#include "rational.h"

int gcd(int n, int d){
  int den = d;
  int remainder = n % d;
  while(remainder != 0){
    int temp = remainder;
    remainder = den % remainder;
    den = temp;
  }
  return den;
}

/* replace this line with your implementation of the Rational type */
Rational::Rational(){
  num = 1;
  denom = 0;
}

Rational::Rational(int n){
  num = n;
  denom = 1;
}

Rational::Rational(int n, int d){
  int temp = gcd(abs(n), d);
  num = n / temp;
  denom = d / temp;
} 

int Rational::n(){
  return num;
}

int Rational::d(){
  return denom;
}

Rational Rational::plus(Rational other){
  int other_n = other.n();
  int other_denom = other.d();
  int this_n = this->num * other_denom;
  other_n = this->denom * other_n;
  other_denom = other_denom * this->denom;
  return Rational(this_n + other_n, other_denom);	 	
}

Rational Rational::minus(Rational other){
  int other_n = other.n();
  int other_denom = other.d();
  int this_n = this->num * other_denom;
  other_n = this->denom * other_n;
  other_denom = other_denom * this->denom;
  return Rational(this_n - other_n, other_denom);
}

Rational Rational::times(Rational other){
  int other_n = other.n();
  int other_denom = other.d();
  return Rational(this->num * other_n, other_denom * this->denom);
}

Rational Rational::div(Rational other){
  int other_n = other.n();
  int other_denom = other.d();
  return Rational(this->num * other_denom, other_n * this->denom);
}
