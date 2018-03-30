import bitstring

def utf8coding(file_read, file_write):
    with open(file_read,'r' ) as fr:
        string = fr.read()
        string = bytes(string, 'utf-8')
    with open(file_write, 'wb') as fw:
        bit_arr = bitstring.BitArray(bytes = string)
        fw.write()



def utf8decoding(file_read, file_write):
    fw = open(file_write, 'w')
    with open(file_read,'br' ) as fr:
        byte = fr.read()
        string = byte.decode('utf-8')
    fw.write(string)
    fw.close()

