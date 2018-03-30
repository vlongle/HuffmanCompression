# Quick start
This program would compress any plain text file (.txt extension) into a binary file (.bin) using __Huffman algorithm__. This helps to save space on your computer.
If you don't have `python` or `pip` on your computer. On terminal, type

```
brew install python
```

This would automatically install `python` and `pip` for you.

To use, first install the `bitstring` python package. On terminal, type

```
$ pip install bitstring
```

Then, fetch the program to your computer
`$ git clone https://github.com/vlongle/HuffmanCompression.git`

Then, navigate to the python folder of the program,
```
$ cd HuffmanCompression
$ cd python
```
Next, launch the app.

```
$ python main.py 
```


You will see two options.


```
Options: 
1. Compress Huffman (hit 1)
2. Decompress Huffman (hit 2)

```

If you want to compress a file, hit 1 on the keyboard and you'll be prompted to provide the path to your text's file.

```
Enter the txt file's path: 
```

Enter the path and wait for the algorithm to complete. You'll receive a bin file and a .pickle that contains necessary information for decompression.

If you want to decompress a file, hit 1 on the keyboard and you'll be prompted to provide the path to your bin's file.

```
Enter the bin file's path: 
```


Then provide the pickle file.

```
Enter the path to the pickle file (serialization of tree node): 
```

Wait for the algorithm to complete and you'll receive back the decompressed text file. 

# Huffman Compression
Written in __C++__ and __Python__ for __Create Project CS Principle__ (ST. Anthony 18')
## Basic of the Algorithm:
https://en.wikipedia.org/wiki/Huffman_coding

## Videos (MIT CS 6004, near the end of the lecture)
https://www.youtube.com/watch?v=CvfifZsmpQ4

## Concepts

* Huffman Algorithm
  * Heap
  * Priority Queue
  * Huffman Tree
* Data handling 
  * Byte reading
  * Bitwise manipulation
  * UTF-8 & ASCII
  * Serialization, Pickle module
* Web interface
  * Django module for Python
  * Regex (Regular Expression)
  
## Python Bugs
Can we write to bin file bit by bit?
According to https://stackoverflow.com/questions/17536411/write-individual-bits-to-a-file-in-python
we can't

But 001110 can be treated the same as 1110, which should not happen, if we convert them into int. 

http://bhrigu.me/blog/2017/01/17/huffman-coding-python-implementation/

## Regular expression
A way to match a special sequence of words.

For example, `/d` searches for all digit in a file. `/d{3}` searches for 3-digit numbers in a file.
`[ ]` is a __character class__ which is a way to say __OR__.

For example, instead of writing `/d`, we can write `[0-9]` to mean any digit from 0 to 9 (a.k.a 0 OR 1 OR 2... OR 9)
