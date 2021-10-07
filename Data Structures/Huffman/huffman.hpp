#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iterator>

/*
One node of the Huffman tree data structure
Contains the character (`data`), the frequency in the data (`freq`)
and two pointers to the left and right nodes
*/
struct HuffmanTreeNode
{
    char data;
    unsigned int freq;
    struct HuffmanTreeNode *left;
    struct HuffmanTreeNode *right;

    HuffmanTreeNode(char data, unsigned int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
Takes in a string and builds a std::map containing each character
and its frequency in the string
*/
void buildCharFreqMap(std::string s);

/*
Comparator used for building min heap
*/
struct compare
{
    bool operator()(HuffmanTreeNode *left, HuffmanTreeNode *right)
    {
        return left->freq > right->freq;
    }
};

/*
Builds the Huffman tree data structure by inserting nodes into a min heap, 
taking the two minimum frequency nodes at a time and creating a new node from them
Repreat this process until size of min heap is 1
*/
HuffmanTreeNode *buildHuffmanTree(std::string str);

/*
Store the Huffman code for each character in the input string str
This is achieved using a DFS traversal of the Huffman tree
*/
void storeCodes(HuffmanTreeNode *root, std::string str);

/*
Encode the string character by character 
using the mapping created in storeCodes()
*/
std::string HuffmanEncode(HuffmanTreeNode *root, std::string str);

/*
Decode the encoded string using a traversal of the Huffman tree
*/
std::string HuffmanDecode(HuffmanTreeNode *root, std::string str);

#endif