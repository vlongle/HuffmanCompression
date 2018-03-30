import  bitstring
import algorithm




def decompress(coded_file, decoded_file, tree):
    string = ''
    dec_file = open(decoded_file, 'w')
    with open(coded_file, 'br') as coded_file:
        while True:
            byte = coded_file.read(1) # read 1 byte at a time
            if not byte:
                break
            byte = bitstring.BitArray(bytes = byte)
            for i in range(8,0,-1):
                tool = 1<< (i-1)
                bit = int((int(byte.bin,2) & tool) !=0)
                if bit == 1:
                    string += "1"
                else:
                    string += "0"

    current = tree
    for ch in string:
        if current.left_child == None and current.right_child == None:
            dec_file.write(current.name)
            current = tree
        if ch == '0' and current.left_child != None:
            # print('left')
            current = current.left_child
        elif ch == '1' and current.right_child != None:
            # print('right')
            current = current.right_child
    dec_file.close()



