//
//  HuffmanPriorityQueue.h
//  
//
//  Created by Le Nguyen VIet Long on 3/13/18.
//

#ifndef HuffmanPriorityQueue_h
#define HuffmanPriorityQueue_h
#include "Heap.h"
class HuffmanPriorityQueue {
public:
    // Data
    Heap myHeap;
    int *size; /*
                use pointer to int instead of primitive int because changes to size in HuffmanPriorityQueue affects size of myHeap
                */
    // Constructor
    HuffmanPriorityQueue(Node* passQueue, int *passSize);
    // Methods
    void enqueue(Node incoming);
    Node* dequeue();
    void makeTree(); /* feed the heap into the priority Queue &
                      repeatedly pulling out (dequeuing) 2 smallest (in frequency)
                      members of the Heap & connect them to form a new Node of their sum
                      then feed the sum back to the tree.
                      Repeat until the Queue only has 1 left -- the ultimate member (sum of all freqs)
                      */
};
#endif /* HuffmanPriorityQueue_h */
