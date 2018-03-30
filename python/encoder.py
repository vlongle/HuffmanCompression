# Created by Long Le on 3/28/18.
# Copyright © 2018 Long Le. All rights reserved.




import bitstring


def compress(file_path, bin_path, name2coding):
    bin_file = open(bin_path, 'bw')
    bit_str = bitstring.BitArray()
    print('bit_str',bit_str)
    with open(file_path, 'r') as txt: # bw = binary write
        while True:
            ch = txt.read(1) # read 1 byte
            if not ch:
                break # end of file
            coding = name2coding[ch]
            coding = bitstring.BitArray(bin = coding)
            bit_str.append(coding)
            # print('after appending ', bit_str)

    extra_padding = (8-(len(bit_str.bin)%8))%8
    print('extra padding: ', extra_padding)
    for i in range(extra_padding):
        bit_str.append(bin(0))
    bin_file.write(bit_str.bytes)
    bin_file.close()