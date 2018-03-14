#include "HuffmanPriorityQueue.h"
#include <iostream>
using namespace std;

// Priority Queue for Huffman Compression using Heap

    Heap myHeap;
    
    int *size;
    
    
    // constructor
    
    HuffmanPriorityQueue(Node* passQueue, int *passSize)
    : myHeap(passQueue, passSize)
    {
        
        size = passSize;
    }
    
    
    void enqueue(Node incoming){
        
        myHeap.Dqueue[*size] = incoming;
        *size +=1;
        myHeap.bottomUp(*size-1);
        cout << "FINISHING ENQUEUE & HERE A PRINT FROM ENQUEUE" << endl;
        myHeap.printHeap();
    }
    
    
    Node* dequeue(){
        myHeap.swap(0, *size-1);
        Node* result = new Node();
        *result = myHeap.Dqueue[*size-1];
        *size -=1;
        

        
        myHeap.topDown(0);
        return result;
    }
    
    
    
    void makeTree(){
        myHeap.makeHeap();
        
        
        

        Node* leftChild = new Node();
        Node* rightChild = new Node();
        Node* newParent = new Node();
        while (*size > 1){
            
            myHeap.printHeap();
            leftChild = dequeue();
            rightChild = dequeue();
            
            newParent->name = "sum";
            newParent->value = leftChild->value + rightChild->value;
            newParent->leftChild = leftChild;
            newParent->rightChild = rightChild;
            
            
            leftChild->parent = newParent;
            rightChild->parent = newParent;
            
            enqueue(*newParent);
            
        }
        
    }
    



