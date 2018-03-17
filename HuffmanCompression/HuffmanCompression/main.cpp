
#include <iostream>
#include "HuffmanEncoder.h"
#include "Decoder.h"
using namespace std;




int main(){
    // MUST provide full path
    std::string filePath = "/Users/longle/Desktop/Developers/github/HuffmanCompression/HuffmanCompression/HuffmanCompression/hamlet.txt";

    Encoder encoder;

    Node* topNode = encoder.readInData(filePath);

    Decoder decoder;
    decoder.decoder("/Users/longle/Desktop/Developers/github/HuffmanCompression/HuffmanCompression/HuffmanCompression/coded.txt", "/Users/longle/Desktop/Developers/github/HuffmanCompression/HuffmanCompression/HuffmanCompression/decompressed.txt",  topNode);
    cout << "YEAH" << endl;
}
