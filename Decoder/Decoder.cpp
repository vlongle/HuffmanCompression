//
//  Decoder.cpp
//  
//
//  Created by Le Nguyen VIet Long on 3/13/18.
//

#include <stdio.h>
#include "Decoder.h"


#include <fstream>

void decoder(string codedFilePath, string decodedFilePath, Node* topNode){
    ifstream codedFile(codedFilePath);
    ofstream decodedFile(decodedFilePath);
    while (!codedFile.eof()){
        string Decoded = "";
        while (true){
            char ch;
            codedFile >> ch;
            Node* current = new Node();
            if (ch == '0'){ // left
                current = topNode -> left;
                if (current->right == nullptr){
                    break; /* break out of While true loop, prefix coding
                            ensures that every char is a leaf !! ---> current -> right
                            is an arbitrary choice. We could have check if current -> left == nullptr*/
                }
            }
            else{ // 1 is right
                current = topNode -> right;
                if (current -> right == nullptr){
                    break;
                }
            }
            
        }
        // current is now a char ready to put into Decoded str
        Decoded = current -> name;
         decodedFile << Decoded;
        
            
            }
    decodedFile.close();
    codedFile.close();
    
}
