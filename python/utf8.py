def utf8coding(file_read, file_write):
    fw = open(file_write, 'bw')
    with open(file_read,'r' ) as fr:
        string = fr.read()
        bytes = bytearray(string, 'utf-8')
        print('bytes', bytes)
    fw.write(bytes)
    fw.close()
def utf8decoding(file_read, file_write):
    fw = open(file_write, 'w')
    with open(file_read,'br' ) as fr:
        byte = fr.read()
        string = byte.decode('utf-8')
    fw.write(string)
    fw.close()