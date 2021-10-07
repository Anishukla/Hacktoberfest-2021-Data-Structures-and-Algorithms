#include "huffman.hpp"

int main()
{
    std::string myString = "ABRACADABRA";
    HuffmanTreeNode *root = buildHuffmanTree(myString);
    std::string encodedString = HuffmanEncode(root, myString);
    std::string decodedString = HuffmanDecode(root, encodedString);
    std::cout << encodedString << '\n'
              << decodedString << '\n';
    return 0;
}