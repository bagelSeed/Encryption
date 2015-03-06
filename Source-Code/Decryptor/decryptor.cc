//====================================================================
// Text File Encryptor/Decryptor
//
// @description: Module for providing functions to work with Decryptor
// objects
// @author: ahlai
// @version: 1.0 22/12/2014
//====================================================================

// Decryptor module (decryptor.h)

#include <fstream>
#include "decryptor.h"
#include "algebra.h"

using namespace std; // Provides direct access to std

// See interface (header file).
bool Decryptor::keyFileExists(const string keyFile) {
   ifstream privateKeyFile(keyFile.c_str());

   if (!privateKeyFile.good()) { // File doesn't exists in current directory?
      return false;
   } else {
      return true;
   } // if
} // keyFileExists

// See interface (header file).
Decryptor::Decryptor(const long long keyValue1, const long long keyValue2) {
   // Sets privateKey to keyValue1 and keyValue2
   privateKey.first = keyValue1;
   privateKey.second = keyValue2;
} // Constructor

// See interface (header file).
Decryptor::Decryptor(const string keyFile) {
   if (keyFileExists(keyFile)) { // keyFile exists in current directory?
      // Reads private key from a file
   	  ifstream privateKeyFile(keyFile.c_str());
   	  privateKeyFile >> privateKey.first >> privateKey.second;
   } else {
   	  throw string("ERROR: " + keyFile + " is missing from the current directory.\nDecryption failed.");
   } // if
} // Constructor

// See interface (header file).
Decryptor::~Decryptor() {} // Destructor

// See interface (header file).
void Decryptor::decrypt(istream &in, ostream &out) {
   char c = '\0';
   while (in.get(c)) {
   	  if (c == '\n') { // Newline character read in?
   	  	 out << endl;
   	  } else {
   	  	 c = (modularPow((c - 32), privateKey.second, privateKey.first) % 95) + 32;
   	  	 out << c;
   	  } // if
   } // while
} // decrypt
