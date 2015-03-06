//====================================================================
// Text File Encryptor/Decryptor
//
// @description: Module for providing functions to work with Decryptor
// objects
// @author: ahlai
// @version: 1.0 22/12/2014
//====================================================================

// Decryptor module (decryptor.h)

#ifndef __DECRYPTOR_H__
#define __DECRYPTOR_H__

#include <iostream>
#include <string>
#include <utility>

// Object definition
class Decryptor {
   std::pair<long long, long long> privateKey; // Private key value pair (n,d)

   // Checks if keyFile provided in the constructor exists.
   bool keyFileExists(const std::string keyFile);

public:
   Decryptor(const long long keyValue1, const long long keyValue2); // Constructor
   Decryptor(const std::string keyFile = "privatekey.txt");         // Constructor
   ~Decryptor();                                                    // Destructor

   // Performs the decryption.
   void decrypt(std::istream &in, std::ostream &out);
};

#endif
