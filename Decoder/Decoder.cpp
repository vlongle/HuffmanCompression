//
//  Decoder.cpp
//  
//
//  Created by Le Nguyen VIet Long on 3/13/18.
//

#include <stdio.h>
#include "Decoder.h"
#include <fstream>
#include <iostream>

void Decoder::decoder(std::string codedFilePath, std::string decodedFilePath, Node* topNode){
    std::cout << "Decoder:: decoder" << std::endl;
    std::ifstream codedFile(codedFilePath);
    std::ofstream decodedFile(decodedFilePath);
    while (!codedFile.eof()) {
        std::string Decoded = "";
        Node* current = topNode;
        while (true){
            char ch;
            std::cout << ch << std::endl;
            codedFile >> ch;
            if (ch == '0'){ // left
                current = current -> leftChild;
                if (current->rightChild == nullptr){
                    break; /* break out of While true loop, prefix coding
                            ensures that every char is a leaf !! ---> current -> right
                            is an arbitrary choice. We could have check if current -> left == nullptr*/
                }
            }
            else{ // 1 is right
                current = current -> rightChild;
                if (current -> rightChild == nullptr){
                    break;
                }
            }
            
            std:: cout << "current: " << current << " current -> name:  " << current -> name<< std::endl;

        }
        std::cout << "Done looping" << std::endl;
        // current is now a char ready to put into Decoded str
        Decoded = current -> name;
        decodedFile << Decoded;
            
            }
    decodedFile.close();
    codedFile.close();
    
}
