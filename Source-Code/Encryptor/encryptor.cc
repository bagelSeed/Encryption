//====================================================================
// Text File Encryptor/Decryptor
//
// @author: Mark Luo & Elisha Lai
// @description: Module for providing functions to work with Encryptor
// objects
// @version: 1.2 15/01/2015
//====================================================================

// Encryptor module (encryptor.cc)

#include "encryptor.h"

using namespace std; // Provides direct access to sd

// See interface (header file).
bool Encryptor::authenticate() {
   ifstream ifs (publicKeyFile.c_str()); // Connects stream and authNFile

   if ( !ifs.good() ) {              // File doesn't exists in current directory?
      cout << publicKeyFile << ' ' << "is missing from the current directory." << endl;
      return false;
   } else {
      return true;    
   } // if
} // authenticate

// See interface (header file).
Encryptor::Encryptor(istream &in, const int keyValue1, const int keyValue2)
   : in(in), keyValue1(keyValue1), keyValue2(keyValue2) {} // Constructor

// See interface (header file).
Encryptor::Encryptor(istream &in, string keyFile)
   : in(in) {} // Constructor

// See interface (header file).
Encryptor::~Encryptor() {} // Destructor

// See interface (header file).
void Encryptor::run() {
   if ( authenticate() ) { // Authentication successful?
      
   } else {
   	  cout << "Encryption failed."
   } // if
} // run

// See interface (header file).
ostream& operator<<(ostream &out, Encryptor encryptor) {
   // Perform encryption here.
   return out;
}
