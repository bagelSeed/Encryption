#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include "Huffman.h"

using namespace std;

void getFreq(std::string,Huffman&);

int main(int argv, char * argc[]){

	Huffman huff;

	try{
		std::string tmp;
		if(argv < 2){
			while(getline(cin,tmp)){getFreq(tmp, huff);}
		} else {
			std::string fileName = argc[1];
			std::fstream file(fileName.c_str());
			if(file.good()){
				while(getline(file,tmp))
					getFreq(tmp, huff);
			} else {
				throw string("Invalid file name, cannot open " + fileName);
			}
		}
	} catch(const string& msg){
		cerr<<msg<<endl;
		return 0;
	}
	huff.buildTree();
	//huff.printFreq();
}

void getFreq(std::string tmp, Huffman &huff){
	for(int i = 0; i < tmp.size(); i++)
		huff.getFrequency(tmp[i]);
	huff.getFrequency('\n');
	huff.getFrequency('\t');
}
