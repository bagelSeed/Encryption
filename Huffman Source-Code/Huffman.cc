#include "Huffman.h"

Huffman::Huffman(){}
Huffman::~Huffman(){}

void Huffman::getFrequency(char c){
	if(freqTable[c]){
		freqTable[c]++;
	} else {
		freqTable[c]=1;
	}
}

void Huffman::printFreq(){
	for(std::map<char,int>::iterator it = freqTable.begin(); it!=freqTable.end(); it++){
        std::cout<<it->first<<" "<<it->second<<std::endl;
	}
}
