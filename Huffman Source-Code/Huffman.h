#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

class Huffman{
	std::map<char, int>freqTable;
public:
	Huffman();
	~Huffman();
	void getFrequency(char);
	void printFreq();
	void buildTree();
};
