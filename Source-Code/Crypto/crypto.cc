//====================================================================
// Text File Encryptor/Decryptor
//
// @author: Mark Luo & Elisha Lai
// @description: Program for encrypting & decrypting text files
// @version: 1.4 16/02/2014
//====================================================================

// Crypto program (crypto.cc)

#include <iostream>
#include <fstream>
#include <string>
#include "encryptor.h"
#include "decryptor.h"

using namespace std; // Provides direct access to std

int main() {
   try {
   	  string command;
   	  while (cin >> command) {
   	  	 string textFile;
   	  	 
   	  	 if (command == "encrypt") {
   	  	 	cin >> textFile;
   	  	 	ifstream plainTextFile(textFile.c_str());
   	  	 	ofstream cipherTextFile("cipher.txt");
   	  	 	Encryptor encryptor;
   	  	 	encryptor.encrypt(plainTextFile, cipherTextFile);
   	  	 } else if (command == "decrypt") {
   	  	 	cin >> textFile;
   	  	 	ifstream cipherTextFile(textFile.c_str());
   	  	 	ofstream plainTextFile("plain.txt");
   	  	 	Decryptor decryptor;
   	  	 	decryptor.decrypt(cipherTextFile, plainTextFile);
   	  	 } // if

   	  } // while
   } catch (const string &msg) {
   	  // If an exception occurs, print the message and end the program.
      cerr << msg << endl;
   }
} // main
