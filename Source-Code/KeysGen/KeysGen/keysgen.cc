//====================================================================
// Private & Public Keys Generator
//
// @author: Mark Luo & Elisha Lai
// @description: Program for generating private & public keys
// @version: 1.4 16/02/2014
//====================================================================

// Keysgen program (keysgen.cc)

#include <iostream>
#include <fstream>
#include <string>
#include "keysgenerator.h"

using namespace std; // Provides direct access to std

int main() {
   cout << "Generating private & public keys." << endl;

   KeysGenerator keysgenerator;
   pair<long long, long long> privateKey = keysgenerator.getPrivateKey();
   pair<long long, long long> publicKey = keysgenerator.getPublicKey();

   // Writes private key to a file
   ofstream privateKeyFile("privatekey.txt");
   privateKeyFile << privateKey.first << endl;
   privateKeyFile << privateKey.second << endl;

   // Writes public key to a file
   ofstream publicKeyFile("publickey.txt");
   publicKeyFile << publicKey.first << endl;
   publicKeyFile << publicKey.second << endl;

   cout << "Private & public keys were successfully generated." << endl;
} // main
