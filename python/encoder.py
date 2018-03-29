# Created by Long Le on 3/28/18.
# Copyright © 2018 Long Le. All rights reserved.




import bitstring
def compress(file_path, bin_path, name2coding):
    bin_file = open(bin_path, 'bw')
    with open(file_path, 'r') as f: # bw = binary write
        while True:
            char = f.read(1)
            if not char:
                break
            # print("dict[c]",dict[c])
            coding = name2coding[char] # str
            extra_padding = (16 - len(coding)%16)%16 # will read 2 byte for each char
            # when there's no padding
            #need padding because the computer write 8 byte each
            for i in range(extra_padding):
                coding += '0'

            bit_arr = bitstring.BitArray(bin = coding)
            # print('extra_padding ', extra_padding)
            # https://docs.python.org/3.1/library/struct.html#format-characters
            extra_padding = bitstring.BitArray(bin ="{0:08b}".format(extra_padding))# 2 byte for padding info
            bin_file.write(bit_arr.bytes)
            # print('extra_padding.bytes', extra_padding.bytes)
            bin_file.write(extra_padding.bytes)
        bin_file.close()