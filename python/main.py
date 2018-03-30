  # Created by Long Le on 3/28/18.
  # Copyright © 2018 Long Le. All rights reserved.

import encoder
import decoder
import algorithm
import utf8
def dict2txt(name2coding):
    file = open('dict.txt', 'w')
    for keys, values in name2coding.items():
        file.write(keys + ' >> ' + values + '\n \n')
    file.close()




utf8.utf8coding('hamlet.txt', 'utf8.bin')
utf8.utf8decoding('utf8.bin', 'decodecUTF8.txt')

# name2coding, tree = algorithm.startHuffman('hamlet.txt')
# encoder.compress('hamlet.txt', 'coded.bin', name2coding)
# decoder.decompress('coded.bin', 'decoded.txt', tree)

