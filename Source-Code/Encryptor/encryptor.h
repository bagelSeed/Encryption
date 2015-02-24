//====================================================================
// Text File Encryptor/Decryptor
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with Encryptor
// objects
// @version: 1.2 15/01/2015
//====================================================================

// Encryptor module (encryptor.h)

#ifndef __ENCRYPTOR_H__
#define __ENCRYPTOR_H__

#include <iostream>

// Object definition
class Encryptor {
   istream &in;                          // Input stream
   const int keyValue1;                  // Public key value pair, d
   const int keyValue2;                  // Public key value pair, n

   // 
   bool authenticate();

public:
   Encryptor(istream &in, const int keyValue1, const int keyValue2); // Constructor
   Encryptor(istream &in, string keyFile = "publickey.txt");         // Constructor
   ~Encryptor();                                                     // Destructor

   // Runs the encryptor.
   friend ostream& operator<<(ostream &out, const Encryptor encryptor);
};

#endif
