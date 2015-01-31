//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with
// KeysGenerator objects
// @version: 1.2 30/01/2014
//====================================================================

// KeysGenerator module (keysgenerator.h)

#ifndef __KEYSGENERATOR_H__
#define __KEYSGENERATOR_H__

#include <utility>

// Object definition
class KeysGenerator {
   std::pair<int, int> privateKey;      // Private key value pair, (n,d)
   std::pair<int, int> publicKey;       // Public key value pair, (n,e)
   
   // Checks if a number num is prime
   bool isPrime(const int num);

   // Generates a prime number
   int generatePrime();

   // Finds the greatest common divisor of two non-negative numbers, num1 and num2
   int gcd(int num1, int num2);

   // Finds another non-negative number coprime to a number num
   int findCoPrime(int num);

public:
   KeysGenerator();                     // Constructor
   ~KeysGenerator();                    // Destructor

   std::pair<int, int> getPrivateKey(); // Accessor to privateKey
   std::pair<int, int> getPublicKey();  // Accessor to publicKey
};
