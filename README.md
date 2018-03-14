    struct Node {
    // default initialization
    Node() : leftChild(nullptr), rightChild(nullptr), parent(nullptr){};
    
    // data
    string name;
    double value;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
    };
