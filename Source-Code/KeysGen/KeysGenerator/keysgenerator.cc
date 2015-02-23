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
#include "primenumgenerator.h"
#include "algebra.h"

using namespace std;                                    // Provides direct access to std

// See interface (header file).
void KeysGenerator::generateKeys() {
   PrimeNumGenerator primenumgenerator;
   const long long p = primenumgenerator.getPrimeNum(); // Stores a randomly generated number
   primenumgenerator.regeneratePrimeNum();
   const long long q = primenumgenerator.getPrimeNum(); // Stores a randomly generated number
   const long long n = p * q;
   const long long phi = (p - 1) * (q - 1);
   const long long e = coprime(phi);
   const long long d = multInverse(e, phi);

   // Sets privateKey and publicKey to calculated values
   privateKey.first = n;
   privateKey.second = d;
   publicKey.first = n;
   publicKey.second = e;
} // generateKeys

// See interface (header file).
KeysGenerator::KeysGenerator() {
   srand(time(0));                                      // Initializes random seed with time
   generateKeys();
} // Constructor

// See interface (header file).
KeysGenerator::~KeysGenerator() {}                      // Destructor

// See interface (header file).
pair<long long, long long> KeysGenerator::getPrivateKey() const {
   return privateKey;
} // getPrivateKey

// See interface (header file).
pair<long long, long long> KeysGenerator::getPublicKey() const {
   return publicKey;
} // getPublicKey

// See interface (header file).
void KeysGenerator::regenerateKeys() {
   generateKeys();
} // regenerateKeys
