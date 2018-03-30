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
  *Byte reading
  *Bitwise manipulation
  *UTF-8 & ASCII
  *Serialization, Pickle module
* Web interface
  * Django module for Python
  
## Python Bugs
Can we write to bin file bit by bit?
According to https://stackoverflow.com/questions/17536411/write-individual-bits-to-a-file-in-python
we can't

But 001110 can be treated the same as 1110, which should not happen, if we convert them into int. 

http://bhrigu.me/blog/2017/01/17/huffman-coding-python-implementation/
