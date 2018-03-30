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


def file_name(file_path, new_extension):
    name = file_path[:file_path.find('.')] # strip away all the old extension starting from the period '.'
    name = name + '.' + new_extension
    return name


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
            bin_file = file_name(text_path, 'bin')
            encoder.compress(text_path ,bin_file, name2coding)
            f = open(file_name(text_path, 'pickle'), 'bw')
            pickle.dump(tree, f)
            f.close()


            print("DONE. Your decoded file is at ", file_name(text_path, 'bin'), end=' ')
            print(". Serialization at " + text_path + file_name(text_path, 'pickle'))
            break

        elif control == '2':
            text_path = input("Enter the bin file's path: ")
            pickle_f = input("Enter the path to the pickle file (serialization of tree node): ")
            print("decompressing making ....")

            pickle_f = open(pickle_f, 'br')
            tree = pickle.load(pickle_f)
            decoded = 'decoded_' + text_path
            decoder.decompress(text_path, decoded, tree)


            print("DONE. Your decoded file is at ", decoded)
            break

        else:
            print("Invalid option. Try again")



if __name__ == "__main__":
    main()


