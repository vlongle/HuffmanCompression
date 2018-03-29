  # Created by Long Le on 3/28/18.
  # Copyright © 2018 Long Le. All rights reserved.

import encoder
import decoder
import algorithm


file_path = "hamlet.txt"
coded_path = "decoded.bin"
name2coding, coding2name = algorithm.startHuffman(file_path)
encoder.compress(file_path, "coded.bin", name2coding)
decoder.decompress(file_path, coded_path, coding2name)