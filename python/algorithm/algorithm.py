# Created by Long Le on 3/28/18.
# Copyright © 2018 Long Le. All rights reserved.



import heapq # heapq = heap queue (a.k.a priority queue)
import nltk # Natural Language ToolKit
import queue

class Huffman_node:
    def __init__(self, name, freq, left_child = None, right_child = None, parent = None, coding = None):
        self.name = name
        self.freq = freq
        self.parent = parent
        self.left_child = left_child
        self.right_child = right_child
        self.coding = coding

    def __lt__(self, other): # overriding the comparison obj1 < obj2
        return self.freq < other.freq

# Read in the txt file and convert it to a dictionary of occurrence
# of each char
def txt2dict(file_path):
    file = open(file_path).read()
    # Frequency distribution. Return a more abstract dictionary as described
    return nltk.FreqDist(file)

# turn the frequency distribution (in the form of dictionary) into a priority queue
def priority_queue(freq_distr):
    heap = []
    for key, value in dict(freq_distr).items():
        new_node = Huffman_node(key, value)
        heapq.heappush(heap, (value, new_node))
    return heap

# Make the Huffman_tree
# return [(value of the tree's Root, name of the tree's root)]
# = [( total # of all character occurrences, 'sum')]
def Huffman_tree(heap):
    while(len(heap)>1):
        elem1_node = heapq.heappop(heap)[1]
        elem2_node = heapq.heappop(heap)[1]

        parent = Huffman_node('sum', elem1_node.freq + elem2_node.freq, elem1_node, elem2_node)
        elem1_node.parent = parent
        elem2_node.parent = parent
        heapq.heappush(heap,(parent.freq,parent))
        # print("debug")
    return heap

# tranverse the Huffman tree in Breadth-first-search manner and index all the coding into a dict
def tree2codingDict(tree): # feed topNode of the tree in
    tree.coding = ''
    q = queue.Queue()
    q.put(tree)
    name2coding = {}
    while (q.qsize() != 0):
        parent = q.get()
        left_child = parent.left_child
        right_child = parent.right_child

        if left_child != None:
            left_child.coding = parent.coding + '0'
            q.put(left_child)
            if left_child.name != 'sum':
                name2coding[left_child.name] = left_child.coding


        if right_child != None:
            right_child.coding = parent.coding + '1'
            q.put(right_child)
            if right_child.name != 'sum':
                name2coding[right_child.name] = right_child.coding


    return (name2coding, tree)

def startHuffman(file_path):
    freq_distr = txt2dict(file_path)
    priority_q = priority_queue(freq_distr)
    tree = Huffman_tree(priority_q)
    print('tree', tree)
    return tree2codingDict(tree[0][1])