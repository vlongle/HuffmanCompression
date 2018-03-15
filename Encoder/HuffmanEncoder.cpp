#include <map> // for creating map / dictionary
#include "HuffmanEncoder.h"
#include <iostream>
#include "fstream" // for reading file
using namespace std;

/* Read in txt.file & then make a map (dictionary) of frequency of words appearing
Then convert the map into a dynamic array of Node object ready to be fed into the Huffman Compression Algorithm
 */
Node*  Encoder::readInData(string filePath){
    ifstream file(filePath);
    char ch;
    map<string, int> dict;
    // eof stands "for end of file".
    while(!file.eof()){
        // Start populating the map
        file >> noskipws >> ch;
        // convert char to string
        string str;
        str.push_back(ch);
        
        dict[str] +=1;
    }
    file.close();
    
    // Populate queue
    Node* Dqueue = new Node[dict.size()];
    int i = 0;
    for (map<string, int>:: iterator iter = dict.begin(); iter != dict.end(); iter++) {
        
        Node temp = {};
        temp.name = iter-> first;
        temp.value = iter -> second;
        Dqueue[i] = temp;
        i+=1;
    }
    
    return Dqueue;
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

