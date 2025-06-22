#include <iostream>
#include <string>
#include <unordered_map>
#include "include/frequency_map.h"
#include "include/huffman_tree.h"
#include "include/huffman_code.h"
#include "include/compression_stats.h"
#include <fstream> 


int main(){
    std::string input;
    // std::cout<<"Enter text to Encode: ";
    // std::getline(std::cin,input);

    //file I/O based compression
    std::ifstream inputFile("input.txt");
    if (inputFile) {
    std::getline(inputFile, input, '\0');  // Read whole file
    inputFile.close();
    std::cout << "Input loaded from input.txt\n";
    } else {
    std::cerr << "Error: Could not open input.txt. Falling back to manual input.\n";
    std::cout << "Enter text to Encode: ";
    std::getline(std::cin, input);
    }

    //building frequency Map
    std::unordered_map<char,int>freqMap=buildFrequencyMap(input);
    std::cout << "\nFrequencies:\n";
    for(auto&pair:freqMap){
        std::cout<<pair.first<<": "<<pair.second<<"\n";
    }
    //Built the Huffman tree
    TreeNode* root = buildHuffmanTree(freqMap);
    std::cout << "\nHuffman Tree built successfully!\n";

    //generate Huffman Codes.
    std::unordered_map<char, std::string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);

    std::cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCode) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    //Encode the input string using Huffman codes
    std::string encodedString = "";
    for (char ch : input) {
    encodedString += huffmanCode[ch];  // look up code and append
    }

    std::cout << "\nEncoded String:\n" << encodedString << "\n";

    std::ofstream encodedFile("encoded.txt");
    if (encodedFile) {
    encodedFile << encodedString;
    encodedFile.close();
    std::cout << "Encoded data written to encoded.txt\n";
    } else {
    std::cerr << "Error writing to encoded.txt\n";
    }

    printCompressionStats(input, encodedString,huffmanCode);

    //decode the encoded string
    std::ifstream encodedInput("encoded.txt");
    std::string encodedFromFile;

    if (encodedInput) {
    std::getline(encodedInput, encodedFromFile, '\0');
    encodedInput.close();
    } else {
    std::cerr << "Error: Could not read from encoded.txt\n";
    return 1;
    }

    std::string decodedString = decodeHuffman(root, encodedFromFile);
    std::cout << "\nDecoded String:\n" << decodedString << "\n";

    // Write decoded text to file
    std::ofstream decodedFile("decoded.txt");
    if (decodedFile) {
    decodedFile << decodedString;
    decodedFile.close();
    std::cout << "Decoded text written to decoded.txt\n";
    } else {
    std::cerr << "Error writing to decoded.txt\n";
    }


    return 0;
}