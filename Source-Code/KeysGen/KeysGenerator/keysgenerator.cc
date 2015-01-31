//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with
// KeyGenerator objects
// @version: 1.2 30/01/2014
//====================================================================

// KeysGenerator module (keysgenerator.cc)

#include <cstdlib>
#include <ctime>
#include "keysgenerator.h"

using namespace std;        // Provides direct access to std

// See interface (header file).
bool KeysGenerator::isPrime(const int num) {
   int testFactor = 2;
      
   while (testFactor < num) {
      if (num % testFactor == 0) {
         return false;
      } else {
         testFactor += 1;
      } // if
   } // while

   return true;

} // isPrime

// See interface (header file).
int KeysGenerator::generatePrime() {
   int primeNum = rand(); // Stores a randomly generated prime number
      
   // Repeatedly generates another prime number randomly if
   // the last randomly generated number isn't prime
   while (!isPrime(primeNum)) {
      primeNum = rand();
   } // while
   	  
   return primeNum;
} // generatePrime

// See interface (header file).
int KeysGenerator::gcd(int num1, int num2) {
   int temp = 0;

   while (num2 != 0) {
      temp = num1;
      num1 = num2;
      num2 = temp % num2;
   } // while

   return num1;
} // gcd

// See interface (header file).
int KeysGenerator::findCoPrime(const int num) {

   // Iterates until a number is found to be coprime with num
   for (int i = 1; i < num; ++i) {
       if (gcd(i, num) == 1) {
       	  return i;
       } // if
   } // if

} // findCoPrime

// See interface (header file).
KeysGenerator::KeysGenerator() {
   srand(time(0));                // Initializes random seed with time
   const int p = generatePrime(); // Stores a randomly generated number
   const int q = generatePrime(); // Stores a randomly generated number
   const int n = p * q;
   const int totient = (p - 1) * (q - 1);
   const int e = findCoPrime(totient);


   // Sets privateKey and publicKey to calculated values
   privateKey.first = n;
   privateKey.second = d;
   publicKey.first = n;
   publicKey.second = e;
} // Constructor

// See interface (header file).
KeysGenerator::~KeysGenerator() {} // Destructor

// See interface (header file).
pair<int, int> KeysGenerator::getPrivateKey() {
   return privateKey;
} // getPrivateKey

// See interface (header file).
pair<int, int> KeysGenerator::getPublicKey() {
   return publicKey;
} // getPublicKey
