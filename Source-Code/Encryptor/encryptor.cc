//====================================================================
// Text File Encryptor/Decryptor
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with Encryptor
// objects
// @version: 1.2 15/01/2014
//====================================================================

// Encryptor module (encryptor.cc)

#include <fstream>
#include "encryptor.h"
#include "algebra.h"

using namespace std; // Provides direct access to std

// See interface (header file).
bool Encryptor::keyFileExists(const string keyFile) {
   ifstream publicKeyFile(keyFile.c_str());

   if (!publicKeyFile.good()) { // File doesn't exists in current directory?
      return false;
   } else {
      return true;    
   } // if
} // keyFileExists

// See interface (header file).
Encryptor::Encryptor(const long long keyValue1, const long long keyValue2) {
   // Sets publicKey to keyValue1 and keyValue2
   publicKey.first = keyValue1;
   publicKey.second = keyValue2;
} // Constructor

// See interface (header file).
Encryptor::Encryptor(const string keyFile) {
   if (keyFileExists(keyFile)) { // keyFile exists in current directory?
   	// Reads public key from a file
   	ifstream publicKeyFile(keyFile.c_str());
      publicKeyFile >> publicKey.first >> publicKey.second;
   } else {
      throw string("ERROR: " + keyFile + " is missing from the current directory.\nEncryption failed.");
   } // if
} // Constructor

// See interface (header file).
Encryptor::~Encryptor() {} // Destructor

// See interface (header file).
void Encryptor::encrypt(istream &in, ostream &out) {
   char c = '\0';
   while (in.get(c)) {
   	if (c == '\n') { // Newline character read in?
   	  	out << endl;
   	} else {
   	   c = (modularPow(c, publicKey.second, publicKey.first) % 95) + 32;
   	   out << c;
      } // if
   } // while
} // Encrypt
