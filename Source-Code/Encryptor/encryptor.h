//====================================================================
// Text File Encryptor/Decryptor
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with Encryptor
// objects
// @version: 1.2 15/01/2014
//====================================================================

// Encryptor module (encryptor.h)

#ifndef __ENCRYPTOR_H__
#define __ENCRYPTOR_H__

#include <iostream>
#include <string>
#include <utility>

// Object definition
class Encryptor {
   std::pair<long long, long long> publicKey; // Public key value pair (n,e)

   // Checks if keyFile provided in the constructor exists.
   bool keyFileExists(const std::string keyFile);

public:
   Encryptor(const long long keyValue1, const long long keyValue2); // Constructor
   Encryptor(const std::string keyFile = "publickey.txt");          // Constructor
   ~Encryptor();                                                    // Destructor

   // Performs the encryption.
   void encrypt(std::istream &in, std::ostream &out);
};

#endif
