

#include <iostream>
#include "Heap.h"
using namespace std;

// MIN HEAP

    // constructor
    
Heap::Heap(Node* passQueue, int *passSize):
Dqueue(passQueue),
size( passSize)
    {};
    
    // swap two nodes!!
    
void Heap::swap(int index1, int index2)
    {
        
        struct Node temp = Heap::Dqueue[index1];
        
        Heap::Dqueue[index1] = Heap::Dqueue[index2];
        
        Heap::Dqueue[index2] = temp;
    }
    
bool Heap::topDown(int index)
    {
        
        int leftIndex = index * 2 + 1;
        
        int rightIndex = index * 2 + 2;
        
        int minIndex = index; // assume
        
        if (leftIndex < *size && Dqueue[leftIndex].value < Dqueue[minIndex].value) {
            
            // if leftIndex is valid (< size) and leftIndex smaller than index --> swap maxIndex
            
            minIndex = leftIndex;
        }
        
        if (rightIndex < *size && Dqueue[rightIndex].value < Dqueue[minIndex].value) {
            
            // a clever way to avoid a tons of if statement!!
            
            minIndex = rightIndex;
        }
        
        if (minIndex != index) {
            
            // index is NOT minIndex --> violate Heap Rule --> need to swap
            
            swap(index, minIndex);
            
            // then call the function recursively at minIndex (which is now swapped with index)
            
            topDown(minIndex);
        }
        
        return 0;
    }
    
bool Heap::bottomUp(int index)
    {
        
        if (index < *size && index !=0) { // if index is valid in the first place!
            
            int parentIndex = -1;
            
            if (index % 2 == 0) {
                
                // index is rightChild
                
                parentIndex = (index - 2) / 2;
            }
            
            else {
                
                // index is leftChild
                
                parentIndex = index / 2;
            }
            
            if (Dqueue[parentIndex].value > Dqueue[index].value) {
                
                swap(parentIndex, index);
                
                bottomUp(parentIndex);
            }
        }
        
        return 0;
    }
    
void Heap::makeHeap()
    {
        
        for (int i = *size / 2; i >= 0; i--) {
            topDown(i);
        }
    }
    
    
void Heap::printHeap(){
        cout << "----------" << endl;
        cout << "This is printHeap()" << endl;
        for (int i = 0; i < *size; ++i){
            cout << "Name: " << Dqueue[i].name;
            
            cout << " Value: " << Dqueue[i].value;
            
            cout << endl;
        }
        cout << "-----------"<<  endl;
        
    }

    
