//
//  Encoder.h
//  
//
//  Created by Le Nguyen VIet Long on 3/13/18.
//

#ifndef Encoder_h
#define Encoder_h
#include "HuffmanPriorityQueue.h"
#include <map>

// Implemementation of Queue needed for BFS tranversal
// Because the implementation of Queue is quite short, it's included in the header
#define CAPACITY 9999
class Queue{
public:
    Node* dQueue;
    int head; // the current USED top of the dArray
    int tail; // the first UNUSED element
    Queue(){
        dQueue = new Node[CAPACITY];
        head = 0;
        tail = 0;
    }
    void enqueue(Node incoming){
        dQueue[tail] = incoming;
        tail +=1;
    }
    Node dequeue(){
        head +=1;
        return dQueue[head-1];
    }
};


class Encoder{
public:
    Node*  readInData(std::string filePath);
    std::map<std::string, std::string> BFSTranversal(Node topNode);
};
#endif /* Encoder_h */
