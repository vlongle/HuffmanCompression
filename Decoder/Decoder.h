//
//  Decoder.h
//  
//
//  Created by Le Nguyen VIet Long on 3/13/18.
//

#ifndef Decoder_h
#define Decoder_h
#include "HuffmanPriorityQueue.h"
class Decoder{
public:
    void decoder(std::string codedFilePath, std::string decodedFilePath, Node* topNode);
};
#endif /* Decoder_h */
