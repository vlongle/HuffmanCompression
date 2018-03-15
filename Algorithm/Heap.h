//
//  Heap.h
//  
//
//  Created by Le Nguyen VIet Long on 3/13/18.
//

#ifndef Heap_h
#define Heap_h
#include <string>
struct Node {
    // default initialization
    Node() : leftChild(nullptr), rightChild(nullptr), parent(nullptr){};
    
    // data
    std::string name ;
    std:: string HuffmanCoding;
    double value;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
};
// Min Heap
class Heap{
public:
    // Data
    Node* Dqueue;
    int* size;
    // Constructors
    Heap(Node* passQueue, int *passSize);
    // Methods
    void swap(int index1, int index2); // swap two nodes at specified indices
    bool topDown(int index); // heapify top down from a node on top of a subtree
    bool bottomUp(int index); // heapify top down from a node under a subtree
    void makeHeap(); // make min-Heap out of a random input Dqueue (by calling topDown on all layers)
    void printHeap(); // for debugging
};

#endif /* Heap_h */
