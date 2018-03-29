import main
# lst = [12,3]
#
# buffer = bytes(lst)
# file_path = "test.bin"
# with open(file_path, 'bw') as f:
#     f.write(buffer)
#
# with open(file_path, 'br') as f:
#     dude = f.read()
#
# print(dude)



a = '00010011100010'
padded_info = a[:8]
print(a)
print(padded_info)
print(int(padded_info,2))
a = a[8:]
print(a)
a = a[:-1]
print('print a', a)