#include <map> // for creating map / dictionary
#include "HuffmanEncoder.h"
#include <iostream>
#include "fstream" // for reading file
using namespace std;

/* Read in txt.file & then make a map (dictionary) of frequency of words appearing
Then convert the map into a dynamic array of Node object ready to be fed into the Huffman Compression Algorithm
 */
//Node*
Node* Encoder::readInData(string filePath){
    ifstream file(filePath);
    char ch;
    map<string, int> freqDict;
    // eof stands "for end of file".
//    while(!file.eof()){
    while(file >> noskipws >> ch){
        cout << "Ch is " << ch << endl;
        // Start populating the map
//        file >> noskipws >> ch;
        // convert char to string
        string str;
        str.push_back(ch);
        
        freqDict[str] +=1;
    }
    
    cout << "Encoder::ReadInData, finish while(!)" << endl;
    file.close();
    
    // Populate queue
    Node* Dqueue = new Node[freqDict.size()];
    int i = 0;
    for (map<string, int>:: iterator iter = freqDict.begin(); iter != freqDict.end(); iter++) {
        
        Node temp = {};
        temp.name = iter-> first;
        temp.value = iter -> second;
        Dqueue[i] = temp;
        i+=1;
    }
    cout << "Encoder:: ReadInData: number of chars in text: " << freqDict.size() << endl;
    int* fake = new int(freqDict.size());
    size = fake;
//    return Dqueue;
    HuffmanPriorityQueue HQueue(Dqueue, size );
    HQueue.makeTree();
    map<string, string> codedDict = BFSTranversal(*HQueue.myHeap.Dqueue);
    std:: cout << "-----Printing codedDict -----" << std:: endl;
    for(auto it = codedDict.cbegin(); it != codedDict.cend(); ++it)
    {
        std::cout << it->first << " " <<  " " << it->second << "\n";
    }
    ofstream CodedFile("/Users/longle/Desktop/Developers/github/HuffmanCompression/HuffmanCompression/HuffmanCompression/coded.txt");
    file.open(filePath);
    while(file >> noskipws >> ch){
        string temp;
        temp.push_back(ch);
        CodedFile << codedDict[temp];
    }
    return HQueue.myHeap.Dqueue;
}


/* Tranverse the Huffman Tree -- Breadth First Tranversal -- go layer by layer
 and return map (dictionary) of { char (like "a", "b") : codingBits (like "0001", "10010"...)
 */

map<string, string> Encoder::BFSTranversal(Node topNode){
    Queue myQ;
    myQ.enqueue(topNode);
    map<string, string> dict;
    
    
    while (myQ.tail != myQ.head){ // a.k.a if the size of myQ != 0
        Node parent = myQ.dequeue();
        Node* left = parent.leftChild;
        Node* right = parent.rightChild;
        if (left != nullptr){         // only enqueue if left & right != NULL
            
            left->HuffmanCoding = parent.HuffmanCoding + "0";
            
            if (left->name !="sum"){         // check if it's not sum ---> write directly into some dict!!
                dict[left->name] = left->HuffmanCoding;
                
            }
            myQ.enqueue(*left);
            
        }
        if (right !=nullptr){
            right->HuffmanCoding = parent.HuffmanCoding + "1";
            if (right->name !="sum"){         // check if it's not sum ---> write directly into some dict!!
                dict[right->name] = right->HuffmanCoding;
            }
            myQ.enqueue(*right);
        }
    }
    return dict;
}

