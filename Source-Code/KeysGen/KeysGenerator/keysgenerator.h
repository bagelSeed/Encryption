//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with
// KeyGenerator objects
// @version: 1.2 30/01/2015
//====================================================================

// KeysGenerator module (keysgenerator.h)

#ifndef __KEYSGENERATOR_H__
#define __KEYSGENERATOR_H__

#include <iostream>
#include <utility>

// Object definition
class KeysGenerator {
   std::pair<long long, long long> privateKey;            // Private key value pair, (n,d)
   std::pair<long long, long long> publicKey;             // Public key value pair, (n,e)
   
   // Generates privateKey and publicKey randomly.
   void generateKeys();

public:
   KeysGenerator();                                       // Constructor
   ~KeysGenerator();                                      // Destructor

   std::pair<long long, long long> getPrivateKey() const; // Accessor to privateKey
   std::pair<long long, long long> getPublicKey() const;  // Accessor to publicKey

   // Regenerates privateKey and publicKey randomly.
   void regenerateKeys();
};

#endif
