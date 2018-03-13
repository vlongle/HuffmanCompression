

// Priority Queue for Huffman Compression using Heap
class HuffmanPriorityQueue {
    
public:
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
    
};


Node* populateQueue(int size)
{
    
    Node* Dqueue = new Node[size];
    
    for (int i = 0; i < size; i++) {
        
        Node temp = {};
        
        cout << "Name: ";
        
        cin >> temp.name;
        
        cout << "Value: ";
        
        cin >> temp.value;
        Dqueue[i] = temp;
        
        cout << endl;
    }
    
    return Dqueue;
}

void printQueue(Node* Dqueue, int size)
{
    
    for (int i = 0; i < size; i++) {
        
        cout << "Name: " << Dqueue[i].name;
        
        cout << " Value: " << Dqueue[i].value;
        
        cout << endl;
    }
}
