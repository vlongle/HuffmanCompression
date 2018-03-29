import bitstring

def decompress(file_path, file_store, coding2name): # the table must be transmitted
    decoded_file = open(file_store, 'w')

    with open(file_path, "br") as f:
        while True:
            byte = f.read(4) # read 2 bytes
            if not byte:
                print("exiting at byte", byte)
                break
            # print('byte', byte)
            bit_arr = bitstring.BitArray(bytes = byte).bin
            bin_decode = bit_arr[:16]
            coding = str(bin_decode)
            print('coding', coding)
            padding = bit_arr[16:]
            print('padding in 2', padding)
            padding = int(padding,2)
            # if padding == 8:
            #     padding = 0
            # print()
            coding = coding[:16-padding] # without padding
            char = coding2name[coding]
            decoded_file.write(char)

