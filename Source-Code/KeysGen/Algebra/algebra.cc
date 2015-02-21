//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to perform algebraic
// calculations
// @version: 1.8 13/02/2015
//====================================================================

// Algebra module (algebra.h)

#include <utility>
#include "algebra.h"

using namespace std; // Provides direct access to std

// Finds the greatest common divisor of two non-negative numbers,
// num1 and num2.
static long long gcd(long long num1, long long num2) {
   long long temp = 0;

   // Calculates the greatest common divisor of num1 and num2
   // using GCD With Remainders until num2 is zero
   while (num2 != 0) {
      temp = num1;
      num1 = num2;
      num2 = temp % num2;
   } // while

   return num1;
} // gcd

// See interface (header file).
long long coprime(const long long num) {
   long long i = 2;

   // Iterates until a number is found to be coprime with num
   while (i < num) {
   	  if (gcd(i, num) == 1) {
   	  	 break;
   	  } // if
   	  ++i;
   } // while

   return i;
} // coprime

// Finds the greatest common divisor of two non-negative numbers,
// a and b, and solution to the equation ax + by = gcd(a, b).
static pair<long long, pair<long long, long long> > extendedEuclidean(long long a, long long b) {
   long long x = 1;
   long long y = 0;
   long long xLast = 0;
   long long yLast = 1;
   long long q = 0;
   long long r = 0;
   long long m = 0;
   long long n = 0;

    // Calculates new values of x, y, q, and r using
    // Extended Euclidean Algorithm until a is zero 
    while (a != 0) {
       q = b / a;
       r = b % a;
       m = xLast - q * x;
       n = yLast - q * y;
       xLast = x;
       yLast = y;
       x = m;
       y = n;
       b = a;
       a = r;
    } // while

    return make_pair(b, make_pair(xLast, yLast));
} // extendedEuclidean

// See interface (header file).
long long multInverse(const long long num, const long long modulus) {
   const long long result = (extendedEuclidean(num,modulus).second.first + modulus) % modulus;
   return result;
} // multInverse

// See interface (header file).
long long modularPow(long long base, long long exponent, const long long modulus) {
   long long result = 1;

   // Calculates the value of result until exponent
   // is zero
   while (exponent != 0) {

      if (exponent % 2 == 1) {
        result = (result * base) % modulus;
      } // if

      exponent = exponent >> 1;
      base = (base * base) % modulus;
   } // while

   return result;
} // modularPow
