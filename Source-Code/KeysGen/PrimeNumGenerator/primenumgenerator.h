//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with
// PrimeNumGenerator objects
// @version: 1.2 30/01/2015
//====================================================================

// PrimeNumGenerator module (primenumgenerator.h)

#ifndef __PRIMENUMGENERATOR_H__
#define __PRIMENUMGENERATOR_H__

// Object definition
class PrimeNumGenerator {
   long long primeNum;            // Randomly generated prime number

   // Generates primeNum randomly.
   void generatePrimeNum();

public:
   PrimeNumGenerator();     // Constructor
   ~PrimeNumGenerator();    // Destructor

   long long getPrimeNum() const; // Accessor to primeNum

   // Regenerates primeNum randomly.
   void regeneratePrimeNum();
};

#endif
