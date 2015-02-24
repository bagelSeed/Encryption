//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with
// PrimeNumGenerator objects
// @version: 1.2 30/01/2015
//====================================================================

// PrimeNumGenerator module (primenumgenerator.cc)

#include <cstdlib>
#include <cmath>
#include "primenumgenerator.h"

using namespace std;          // Provides direct access to std

// See interface (header file).
void PrimeNumGenerator::generatePrimeNum() {
   const int limit = 1000000;
   int root = ceil(sqrt(limit));
   bool sieve[limit];
   int primes[(limit/2)+1];
   int insert = 2;
   primes[0] = 2;
   primes[1] = 3;

   for (int z = 0; z < limit; z++) {
      sieve[z] = false; //Not all compilers have false as the default boolean value
   }

   for (int x = 1; x <= root; x++) {
      for (int y = 1; y <= root; y++) {
      //Main part of Sieve of Atkin
      int n = (4*x*x)+(y*y);
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
      n = (3*x*x)+(y*y);
      if (n <= limit && n % 12 == 7) sieve[n] ^= true;
      n = (3*x*x)-(y*y);
      if (x > y && n <= limit && n % 12 == 11) sieve[n] ^= true;
      }
    }
  
    //Mark all multiples of squares as non-prime
    for (int r = 5; r <= root; r++) if (sieve[r]) for (int i = r*r; i < limit; i += r*r) sieve[i] = false;
    
    //Add into prime array
    for (int a = 5; a < limit; a++) {
       if (sieve[a]) {
          primes[insert] = a;
          insert++;
       }
    }

    int randNum = rand()%insert;
    primeNum = primes[randNum];
} // generatePrimeNum

// See interface (header file).
PrimeNumGenerator::PrimeNumGenerator()
   : primeNum(0) {
   generatePrimeNum();
} // Constructor

// See interface (header file).
PrimeNumGenerator::~PrimeNumGenerator() {} // Destructor

// See interface (header file).
long long PrimeNumGenerator::getPrimeNum() const {
   return primeNum;
} // getPrimeNum

// See interface (header file).
void PrimeNumGenerator::regeneratePrimeNum() {
   generatePrimeNum();
} // regeneratePrimeNum
