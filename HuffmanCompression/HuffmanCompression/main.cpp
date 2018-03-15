#include <iostream>
#include "HuffmanEncoder.h"
using namespace std;




int main(){
    std::string filePath = "Hamlet.txt";
    Encoder encoder;
    encoder.readInData(filePath);
    
    
    cout << "YEAH" << endl;
}
