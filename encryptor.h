//====================================================================
// Text File Encryptor/Decryptor
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with Encryptor
// objects
// @version: 1.0 22/12/2014
//====================================================================

// Encryptor module (encryptor.h)

#ifndef __ENCRYPTOR_H__
#define __ENCRYPTOR_H__

#include <iostream>

// Object definition
class Encryptor {
   istream &in;                          // Input stream
   ostream &out;                         // Output stream
   int key;
   int value;                 

   // 
   bool authenticate();

public:
   Encryptor(istream &in, ostream &out); // Constructor
   ~Encryptor();                         // Destructor

   // Runs the encryptor.
   void run();
   friend ostream& operator<<(ostream &in)
};

#endif
