// huffman_code.h
#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <unordered_map>
#include <string>
#include "huffman_tree.h"  // for TreeNode definition

// Recursive function to assign binary codes to characters
void generateHuffmanCodes(TreeNode* root, const std::string& path,
                          std::unordered_map<char, std::string>& huffmanCode) {
    if (!root) return;

    // Leaf node: it contains a character
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = path;
        return;
    }

    // Traverse left and right with appended path
    generateHuffmanCodes(root->left, path + "0", huffmanCode);
    generateHuffmanCodes(root->right, path + "1", huffmanCode);
}

// Function to decode the binary string using the Huffman Tree
std::string decodeHuffman(TreeNode* root, const std::string& encodedStr) {
    std::string decoded = "";
    TreeNode* current = root;

    for (char bit : encodedStr) {
        if (bit == '0') current = current->left;
        else if (bit == '1') current = current->right;

        // If we reach a leaf node (character), append it
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;  // reset to root for next char
        }
    }

    return decoded;
}


#endif
