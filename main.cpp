#include <iostream>
#include <fstream>//gives the function to read
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct freq
{
    int value;
    char symbol;
    freq *left;
    freq *right;
};

typedef vector<bool> bvec;

struct traversalStr
{
    char symbol;
    bvec code;
};

typedef vector<string> svec;
typedef vector<char> cvec;
//typedef vector<bool> bvec;
typedef vector<int> ivec;
typedef vector<unsigned int> uvec;
typedef vector<freq*> fvec;
typedef vector<traversalStr> tvec;


//Return the Boolean value of the comparison of lhs value with rhs value
bool freqSorter(freq const * lhs, freq const * rhs)
{
    return lhs->value > rhs->value;
}

ostream &operator<<(ostream &stream, svec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream << obj[i]<<endl;
    }
    return stream;
}
ostream &operator<<(ostream &stream, cvec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream << obj[i]<<endl;
    }
    return stream;
}
ostream &operator<<(ostream &stream, bvec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream << obj[i];
    }
    return stream;
}
ostream &operator<<(ostream &stream, fvec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream << "character " <<obj[i]->symbol;
        stream << " has "<<obj[i]->value<< " frequency"<<endl;
    }
    return stream;
}
ostream &operator<<(ostream &stream, tvec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream <<obj[i].symbol<<" :"<<obj[i].code<<endl;
    }
    return stream;
}
ostream &operator<<(ostream &stream, uvec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream << obj[i]<<endl;
    }
    return stream;
}
ostream &operator<<(ostream &stream, ivec &obj)
{
    for(int i = 0; i < (int)obj.size(); i++)
    {
        stream << obj[i];
    }
    return stream;
}
/*fvec sortFreq(fvec file)
{
    for(int i = 0; i < (int)file.size()-1; i++)
    {
        for(int j = i+1; j < (int)file.size(); j++)
        {
            if(file[i]->value < file[j]->value)
            {
                int value = file[i]->value;
                char chara = file[i]->symbol;
                file[i]->value = file[j]->value;
                file[i]->symbol = file[j]->symbol;
                file[j]->value = value;
                file[j]->symbol = chara;
            }
        }
    }
    return file;
}

fvec sortVecFreq(fvec file)
{
    freq *newNode = new freq;
    newNode = file[file.size()-1];
    file.pop_back();
    for(int i = 0; i < (int)file.size()-1; i++)
    {
        if(i==(int)file.size()-1)
        {
            return file;
        }
        if((file[i]->value) > (newNode->value) && (file[i+1]->value) < (newNode->value))
        {
            fvec tempVec;
            for(int j = i+1; i < (int)file.size()-1; i++)
            {
                tempVec.push_back(file[j]);
                file.erase(file.begin()+j-1);
                cout << "j = " << j << file << endl;
            }
            file.push_back(newNode);
            for(int k = 0; k < (int)tempVec.size()-1; k++)
            {
                file.push_back(tempVec[k]);
            }
        }
    }
    return file;
}*/

void printNode(freq *file)
{
    if(file!=0)
    {
        cout << "address ="<<file<<" left ="<<file->left;
        cout << " right ="<<file->right<<" data ="<<file->value;
        cout <<"  CHARACTER = "<<file->symbol<<endl;
    }
}
void printTree(freq *file)
{
    if(file!=NULL)
    {
        printTree(file->left);
        printNode(file);
        printTree(file->right);
    }
}
//Encoding : Bst Char vector<bool> Bool -> vector<bool>
// 1 = right "true"             0 = left "false"
void encoding(freq *file, char target, bvec &code, bool &isDone)
{
    if(file->left!=NULL)
    {
        code.push_back(false);
        encoding(file->left, target, code, isDone);
    }

    if(file->left==NULL && file->right==NULL )
    {
        //leaf is reached, isDone is true, end w/ return
        if(file->symbol==target)
            isDone=true;
        //if not, erase previous code, travser tree and try again
        else
            code.pop_back();
    }
    if(isDone)
        return;

    //just trust this part
    if(file->right!=NULL)
    {
        code.push_back(true);
        encoding(file->right, target, code, isDone);
        //it's legit
        //seriously...
        //if the left part of the root is false, go right, check with the NULL test
        //if isDone is now true => found the target => end problem
        if(isDone)
            return;
        //else, we delete the previous code that we added above
        code.pop_back();
    }
}

int power (int count)
{
    int temp =1 ;
    for (int i = 0; i < count; i ++)
    {
        temp *= 2;
        //cout << "temp = "<< temp << endl;
    }
    return temp;
}

ifstream::pos_type size;
char * memblock;

int main()
{
    /*          OPENING FILE        */
    string infilename;//string a infilename <-- name of the file to open
    ifstream infile;// "in" fstream a infile, which can be use to open the infilename file

    //cout << "Please enter the input file name" << endl;
    //getline (cin, infilename);//get the name of infilename
    infilename = "stuff.txt";
    while(true)//assume its true that the program can open
    {
        infile.open(infilename.c_str(), ifstream::in);//opening the infilename with infile
        if(!infile.is_open())//if it doesnt open
        {
            cout << "could not open" << infilename << endl;//print error and get another name after the if loop
            cout << "Please enter another filename" << endl;
            cout << "or enter to quit" << endl;
        }
        else//if it can open, break out loop
            break;
        getline(cin, infilename);//get new infilename's name
        if(infilename=="")//if infilename is nothing, end the program
            return 1;
    }

    svec sector;

    while(infile.good())//keep goes while still has input
    {
        string str;//string a str
        getline(infile, str);//get each line from infile(the file we just opened) to str
        sector.push_back(str);
        //cout << sector<<endl;//and then print out each strings of line
    }


















    /*              IMPLEMENTING TREE               */
    //cout <<sector<<endl;

    fvec file;//vector of freq, This is the node of the BST (leaf). Each Node has a character value as well as a integer value
                //NOTE: The integer value determines the frequency of the character appeared in the text file.
    tvec codeFile;//Public key of each alphabet, It has a Char value and a vector of Bool
                    //The vector of Bool determines the Binary Code of each alphabet

    for(int i = 0; i < (int)sector.size(); i++)
    {
        //get the frequency and the types of each characters
        for(int k = 0; k < (int)sector[i].size(); k++)
        {
            /*if(i==0 && k==0)
            {
                freq start;
                start.symbol=sector[0][0];
                start.value=1;
                file.push_back(start);
                //cout <<"STARTING FILE SIZE "<<file.size()<<endl;
            }*/
            bool isAlreadyExist=false;
            //Go through the list of Node (freq*) and check for repeating characters
            for(int j = 0; j < (int)file.size(); j++)
            {
                if(file[j]->symbol==sector[i][k])
                {
                    file[j]->value++;
                    isAlreadyExist=true;
                }
            }
            //If new character appears, add to the list of <file>
            //add new "Char" to the list of <codeFile>





            //  Obtaining a list of all of the character from the text file
            //  Listof freq(node of the tree) : <file>        Listof traversalStr(key of each character) : <codeFile>
            if(!isAlreadyExist)
            {
                freq *indi = new freq;
                traversalStr newCode;
                //cout <<sector[i][k];
                indi->symbol=sector[i][k];
                newCode.symbol=sector[i][k];
                indi->value=1;
                indi->left=NULL;
                indi->right=NULL;
                file.push_back(indi);
                codeFile.push_back(newCode);
                //cout <<"NEW FILE SIZE "<<file.size()<<endl;
            }
        }
    }
    //cout<<codeFile<<endl;
    //cout <<file.size()<<"FILE SIZE"<<endl;
    //organize the freq

    //file = sortFreq(file);


    /*The behaviour of sort:
    sort :: The range of the list ->[Initial starting point (beginning of the list), End point (ending of the list)], Boolean evaluation
    */
    sort(file.begin(), file.end(), &freqSorter);
    //cout <<file<<endl;

    //Continuously adding trees together.
    //<file> sorted as descending order. Smallest elements are combined into a node, with no symbol value (value of 0).
    //smallest are combined, added to the end. Sorted and proceeded again.
    while((int)file.size()!=1)
    {
        freq *tempNode = new freq;
        //combined value --> new value for the node, with 0 as symbol value.
        tempNode->value=(file[file.size()-1]->value)+(file[file.size()-2]->value);
        tempNode->symbol=0;
        //sorted as BST, smallest -> left, largest -> right
        if((file[file.size()-1]->value)>(file[file.size()-2]->value))
        {
            tempNode->left=file[file.size()-2];
            tempNode->right=file[file.size()-1];
        }
        else
        {
            tempNode->left=file[file.size()-1];
            tempNode->right=file[file.size()-2];
        }
        //get ride of the used node
        file.pop_back();
        file.pop_back();
        //add new node, with comebined value and symbol of 0. <freq>
        file.push_back(tempNode);

        //sort again, proceed until left with root
        sort(file.begin(), file.end(), &freqSorter);
        //cout << file;
        //cout << endl;
    }



    //Implement the actual position/binary code of each characters
    for(int i = 0; i < (int)codeFile.size(); i++)
    {
        bool isDone = false;
        encoding(file[0], codeFile[i].symbol, codeFile[i].code, isDone);
    }
    //cout <<"ROOT OF TREE"<<file;

    //printTree(file[0]);
    cout <<codeFile;

    bvec codeString;
    //acquiring the string of binary code (from each letter)
    for(int i = 0; i < (int)sector.size(); i++)
    {
        for(int j = 0; j < (int)sector[i].size(); j++)
        {
            for(int k = 0; k < (int)codeFile.size(); k++)
            {
                if(codeFile[k].symbol==sector[i][j])
                {
                    for(int l = 0; l< (int)codeFile[k].code.size(); l++)
                    {
                        codeString.push_back(codeFile[k].code[l]);
                    }
                }
            }
        }
    }
    /*for(int i = 0; i < (int)codeFile.size(); i++)
    {
        for(int j = 0; j < (int)codeFile[i].code.size(); j++)
            codeString.push_back(codeFile[i].code[j]);
    }*/

    //cout <<"Binary code : "<<codeString<<endl;
    unsigned int numCharInData=codeString.size();
    int paddedZeros = 32-(codeString.size()%32);
    if(paddedZeros!=32)
    {
        for(int i = 0; i < paddedZeros; i++)
            codeString.push_back(false);
    }

    //cout <<"Binary code : "<<codeString<<endl;

    ivec tempBinaryCode;
    uvec convertedDecimal;
    for(int i = 0; i < (int)codeString.size(); i++)
    {
        if(codeString[i]==false)
            tempBinaryCode.push_back(0);
        else
            tempBinaryCode.push_back(1);
        if((i+1)%32==0)
        {
            ivec temp;
            for (int i = 1; i <= (int)tempBinaryCode.size(); i++)
            {
                int hello = power(i-1);

                hello *= tempBinaryCode[(tempBinaryCode.size()) - i];

                temp.push_back(hello);
            }

            int sum = 0;
            for (int i = 0; i < (int)temp.size(); i++)
                sum += temp[i];
            convertedDecimal.push_back(sum);
            //cout << "Pre erase"<<tempBinaryCode<<endl;
            tempBinaryCode.erase(tempBinaryCode.begin(), tempBinaryCode.end());
            //cout <<" Post erase"<<tempBinaryCode<<endl;
        }
    }
    //cout << convertedDecimal;

    ofstream outbin( "binary.bin", ios::binary );
    unsigned int CDsize = (convertedDecimal.size()+1)*4;
    outbin.write( reinterpret_cast <const char*> (&CDsize), sizeof( CDsize) );

    for(int i = 0; i < (int)convertedDecimal.size(); i++)
        outbin.write( reinterpret_cast <const char*> (&convertedDecimal[i]), sizeof( convertedDecimal[i]) );

    unsigned char codeFileSizeTemp = (codeFile.size()*2)+CDsize;
    //cout<<"CODE FILE SIZE TEMP: "<< (int) codeFileSizeTemp<<endl;
    outbin.write( reinterpret_cast <const char*> (&codeFileSizeTemp), sizeof( codeFileSizeTemp ) );

    for(int i = 0; i < (int)codeFile.size(); i++)
    {
        unsigned char tempSymb = codeFile[i].symbol;
        unsigned char tempSize = codeFile[i].code.size();
        outbin.write( reinterpret_cast <const char*> (&tempSymb), sizeof( tempSymb ) );
        outbin.write( reinterpret_cast <const char*> (&tempSize), sizeof( tempSize ) );
    }
//START HERE
    bvec codeBinaryString;
    for(int i = 0; i < (int)codeFile.size(); i++)
    {
        for(int j = 0; j < (int)codeFile[i].code.size(); j++)
        {
            if(codeFile[i].code[j]==false)
                codeBinaryString.push_back(false);
            else
                codeBinaryString.push_back(true);
        }
    }

    int codeBinaryPaddedZeros = 32-(codeBinaryString.size()%32);
    if(codeBinaryPaddedZeros!=32)
    {
        for(int i = 0; i < codeBinaryPaddedZeros; i++)
            codeBinaryString.push_back(false);
    }

    //cout <<"BAssign Code :"<<codeBinaryString<<endl;

    ivec codeBinary;//assigning letter's binary code
    uvec convertedDecimal2;
    for(int i = 0; i < (int)codeBinaryString.size(); i++)
    {
        if(codeBinaryString[i]==false)
            codeBinary.push_back(0);
        else
            codeBinary.push_back(1);
        if((i+1)%32==0)
        {
            ivec temp;
            for (int i = 1; i <= (int)codeBinary.size(); i++)
            {
                int hello = power(i-1);

                hello *= codeBinary[(codeBinary.size()) - i];

                temp.push_back(hello);
            }

            int sum = 0;
            for (int i = 0; i < (int)temp.size(); i++)
                sum += temp[i];
            convertedDecimal2.push_back(sum);
            //cout << "Pre erase"<<codeBinary<<endl;
            codeBinary.erase(codeBinary.begin(), codeBinary.end());
            //cout <<" Post erase"<<codeBinary<<endl;
        }
    }
    //cout <<"CD2 :"<<convertedDecimal2<<endl;


    for(int i = 0; i < (int)convertedDecimal2.size(); i++)
        outbin.write( reinterpret_cast <const char*> (&convertedDecimal2[i]), sizeof( convertedDecimal2[i]) );

    outbin.write( reinterpret_cast <const char*> (&numCharInData), sizeof(numCharInData) );


    outbin.close();
















    ifstream newfile ("binary.bin", ios::in|ios::binary|ios::ate);
    size = newfile.tellg();
    memblock = new char [size];
    newfile.seekg (0, ios::beg);
    newfile.read (memblock, size);
    //cout <<memblock<<endl;
    newfile.close();
    cvec InputString;
    bvec code;
    //cout <<"SIZE "<<size<<endl;
    //cout <<"CDsize "<<CDsize<<endl;
    unsigned int codeSize = memblock[0];
    unsigned int numCharInData2 = memblock[size];
    //cout <<"CodeSize :"<<codeSize<<endl;
    int counttemp = 1;
    for(int i = 4; i < (int)codeSize; i++)
    {
        if(counttemp%4==0)
        {
            counttemp=0;
            //cout <<"THROUGH TIME"<<endl;
            for(int m = i; m>=i-3; m--)
            {
                unsigned char number=memblock[m];

                int i = 0;
                int bSum = 0;

                while (true)
                {
                    bSum = power(i);
                    //cout << "i = " << i << " bSum = " << bSum << " number = " << (unsigned int) number << endl;
                    if (bSum > number)
                        break;
                    i++;
                }
                //cout << "i = " << i << endl;
                bSum = power(i-1);
                if (number == 0)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        code.push_back(false);
                    }
                }
                else
                {
                    while (true)
                    {
                        if (number > bSum)
                        {
                            number -= bSum;
                            code.push_back(true);
                            bSum = power(i-2);
                        }
                        else if (number == bSum)
                        {
                            code.push_back(true);
                            while (i > 1)
                            {
                                code.push_back(false);
                                i--;
                            }
                            break;
                        }
                        else
                        {
                            bSum = power(i-2);
                            code.push_back(false);
                        }
                        i--;
                    }
                }
            }
        }
        counttemp++;
        //cout << endl;
    }
    tvec ExtractedTreeCode = codeFile;//cheat cheat
    unsigned char treeSize = memblock[codeSize];
    //cout <<"TREE SIZE: "<<(int) treeSize<<endl;
    //cout <<"SIZE SIZE: "<<(int) size<<endl;

    bvec code2;
    int counttemp2 = 1;
    for(int i = treeSize+1; i < (int)size-4; i++)
    {
        //cout<<"TREE SIZE2: "<<(int)treeSize<<endl;
        if(counttemp2%4==0)
        {
            //cout <<"THROUGH TIME"<<endl;
            for(int m = i; m>=i-3; m--)
            {
                unsigned char number=memblock[m];

                int i = 0;
                int bSum = 0;

                while (true)
                {
                    bSum = power(i);
                    //cout << "i = " << i << " bSum = " << bSum << " number = " << (unsigned int) number << endl;
                    if (bSum > number)
                        break;
                    i++;
                }
                //cout << "i = " << i << endl;
                bSum = power(i-1);
                if (number == 0)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        code2.push_back(false);
                    }
                }
                else
                {
                    while (true)
                    {
                        if (number > bSum)
                        {
                            number -= bSum;
                            code2.push_back(true);
                            bSum = power(i-2);
                        }
                        else if (number == bSum)
                        {
                            code2.push_back(true);
                            while (i > 1)
                            {
                                code2.push_back(false);
                                i--;
                            }
                            break;
                        }
                        else
                        {
                            bSum = power(i-2);
                            code2.push_back(false);
                        }
                        i--;
                    }
                }
            }
        }
        counttemp2++;
        //cout << endl;
    }
    unsigned int incrTemp=0;
    int halfCount=1;
    /*for(int i = (int)codeSize+1; i <(int)treeSize; i++)
    {
        //cout << "code size + 1 = " << codeSize + 1 << " treesize = "<< (int)treeSize << " i = " << i << endl;
        if(halfCount%2==0)
        {
            halfCount++;
            continue;
        }
        else
        {
            halfCount++;
            unsigned char BinChar = memblock[i];
            unsigned char BinCode = memblock[i+1];
            int treeDataSize=0;
            traversalStr temp;
            temp.symbol=BinChar;
            for(int j=incrTemp; j<(int)incrTemp+BinCode; j++)
            {
                //cout << "incrTemp = " << incrTemp << " incrTemp+BinCode = "<< (int)incrTemp+BinCode << " j = " << j << endl;
                if(code2[j]==false)
                    temp.code.push_back(false);
                else
                    temp.code.push_back(true);
                treeDataSize++;
            }
            incrTemp+=treeDataSize;
            ExtractedTreeCode.push_back(temp);
        }

    }*/

    delete[] memblock;
    //cout << "here" << endl;
    /*cout<<"Binary code : ";
    for(int i =0; i < (int)code.size(); i++)
        cout << code[i];
    cout <<endl;*/

    for(int i =0; i < (int)ExtractedTreeCode.size(); i++)
    {
        cout << ExtractedTreeCode[i].symbol<<" :";
        cout << ExtractedTreeCode[i].code;
        cout <<endl;
    }
    /*for(int i =0; i < (int)code2.size(); i++)
        cout << code2[i];*/
    string extraDoc;
    for(int i = 0; i < (int)numCharInData2;)
    {
        for(int j=0; j < (int)ExtractedTreeCode.size(); j++)
        {
            int treeCodeCounter=0;
            for(int k=0; k < (int)ExtractedTreeCode[j].code.size(); k++)
            {
                if(ExtractedTreeCode[j].code[k]==code[i+k])
                    treeCodeCounter++;
            }
            if(treeCodeCounter==(int)ExtractedTreeCode[j].code.size())
            {
                extraDoc.push_back(ExtractedTreeCode[j].symbol);
                i+=treeCodeCounter;
                break;
            }
        }
    }
    cout <<"Extracted document :"<<extraDoc<<endl;

    return 0;
}

/*

b :100
l :1011
a :111
c :1010
k :001
  :000
w :011
x :010
e :1101
s :1100


b :100
l :1011
a :111
c :1010
k :001
  :000
w :011
x :010
e :1101
s :1100

Process returned 0 (0x0)   execution time : 4.938 s
Press any key to continue.

*/
