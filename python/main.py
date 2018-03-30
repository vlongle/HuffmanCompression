  # Created by Long Le on 3/28/18.
  # Copyright © 2018 Long Le. All rights reserved.
import pickle
from encoder import encoder
from decoder import decoder
from algorithm import algorithm
from utf8 import utf8
def dict2txt(name2coding):
    file = open('dict.txt', 'w')
    for keys, values in name2coding.items():
        file.write(keys + ' >> ' + values + '\n \n')
    file.close()

def main():
    while True:
        print("Options: ")
        print("1. Compress Huffman (hit 1)")
        print("2. Decompress Huffman (hit 2)")
        control = input()

        if control == '1':
            text_path = input("Enter the txt file's path: ")
            print("Huffman making ...")

            name2coding, tree = algorithm.startHuffman(text_path)
            encoder.compress(text_path ,text_path + '.bin' , name2coding)
            f = open(text_path + '.pickle', 'bw')
            pickle.dump(tree, f)
            f.close()


            print("DONE. Your decoded file is at ", text_path + '.bin', end=' ')
            print(". Serialization at " + text_path + '.pickle')
            break

        elif control == '2':
            text_path = input("Enter the bin file's path: ")
            pickle_f = input("Enter the path to the pickle file (serialization of tree node): ")
            print("decompressing making ....")

            pickle_f = open(pickle_f, 'br')
            tree = pickle.load(pickle_f)
            decoder.decompress(text_path, text_path + '.txt', tree)


            print("DONE. Your decoded file is at ", text_path + '.utf8')
            break

        else:
            print("Invalid option. Try again")



if __name__ == "__main__":
    main()


# test = algorithm.Huffman_node('test', 39)
# f = open('f.pickle', 'wb')
# pickle.dump(test, f)
# print(test)
# f.close()

# f = open('f.pickle', 'rb')
# test = pickle.load(f)
# print(test.name)