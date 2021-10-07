#include "huffman.hpp"

std::map<char, std::string> codes; //Store mapping between character and its Huffman code
std::map<char, int> freqMap;       //Store mapping between character and its frequency in the string

void buildCharFreqMap(std::string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        std::map<char, int>::iterator it = freqMap.find(s[i]); //Find the character in the map
        if (it == freqMap.end())                               //If character not in map
        {
            freqMap.insert({s[i], 1}); //Insert character into map with freq 1
        }
        else
        {
            it->second++; //Increase count of character by 1
        }
    }
}

HuffmanTreeNode *buildHuffmanTree(std::string s)
{
    buildCharFreqMap(s);
    //min-heap implementation using priority queue
    std::priority_queue<HuffmanTreeNode *, std::vector<HuffmanTreeNode *>, compare> minHeap;

    // Insert all the characters one by one into the min heap
    for (auto it : freqMap)
    {
        char data = it.first;
        int freq = it.second;
        HuffmanTreeNode *node = new HuffmanTreeNode(data, freq);
        minHeap.push(node);
    }
    HuffmanTreeNode *left = NULL;
    HuffmanTreeNode *right = NULL;
    HuffmanTreeNode *internalNode = NULL;
    while (minHeap.size() != 1)
    {

        //Pick the two nodes with least frequency from the min heap
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        //Create an internal node with value '$' and sum of the two min frequency nodes
        internalNode = new HuffmanTreeNode('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        //Push the newly created internal node into the min-heap
        minHeap.push(internalNode);
    }

    // Return the root of the min-heap
    return minHeap.top();
}

void storeCodes(HuffmanTreeNode *root, std::string str)
{
    if (root == NULL)
        return;
    if (root->data != '$')              //Leaf nodes have data as some character, not '$'
        codes[root->data] = str;        //Upon encountering a leaf node, store its code into the data
    storeCodes(root->left, str + "0");  //If encountering the left sub-heap, add '0' to the code
    storeCodes(root->right, str + "1"); //If encountering the right sub-heap, add '1' to the code
}

std::string HuffmanEncode(HuffmanTreeNode *root, std::string str)
{
    storeCodes(root, ""); //Generate the codes for each character
    //Print the codes for each character
    for (auto x : codes)
    {
        std::cout << x.first << ' ' << x.second << '\n';
    }
    std::string encodedString = "";
    for (auto x : str)
    {
        encodedString += codes[x]; //For each character in the original string, append its code
                                   //to the encoded string
    }
    return encodedString;
}

std::string HuffmanDecode(HuffmanTreeNode *root, std::string str)
{
    std::string decodedString = "";
    HuffmanTreeNode *curr = root;
    //Check if Huffman tree exists
    if (curr == NULL)
    {
        std::cout << "Please construct Huffman tree first!" << '\n';
        return "";
    }
    for (auto x : str)
    {
        if (x != '0' && x != '1')
        {
            std::cout << "Invalid input string for decode!";
            break;
        }
        else if (x == '0')         //If 0 found in encoded string, move left
        {
            curr = curr->left;
        }
        else if (x == '1')         //If 1 found in encoded string, move right
        {
            curr = curr->right;
        }
        if (curr->left == NULL && curr->right == NULL)      //If leaf node, add character to decoded string
        {                                                   //and back-track to the root
            decodedString += curr->data;
            curr = root;
        }
    }
    return decodedString;
}
