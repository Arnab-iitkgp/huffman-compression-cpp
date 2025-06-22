// huffman_tree.h
#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <unordered_map>
#include <queue>
#include <memory>

// TreeNode structure for the Huffman Tree
struct TreeNode {
    char ch;             // character
    int freq;            // frequency of the character
    TreeNode* left;      // left child
    TreeNode* right;     // right child

    // Constructor
    TreeNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(TreeNode* a, TreeNode* b) {
        return a->freq > b->freq;  // min-heap: lower freq = higher priority
    }
};

// Function to build the Huffman Tree from the frequency map
TreeNode* buildHuffmanTree(const std::unordered_map<char, int>& freqMap) {
    // Min-heap (priority queue) to store tree nodes
    std::priority_queue<TreeNode*, std::vector<TreeNode*>, Compare> minHeap;

    // Step 1: Push all characters as individual nodes into minHeap
    for (const auto& pair : freqMap) {
        TreeNode* node = new TreeNode(pair.first, pair.second);
        minHeap.push(node);
    }

    // Step 2: Combine two smallest nodes until only one remains
    while (minHeap.size() > 1) {
        TreeNode* left = minHeap.top(); minHeap.pop();    // smallest freq
        TreeNode* right = minHeap.top(); minHeap.pop();   // 2nd smallest

        // Create a new internal node with no character, freq = left+right
        TreeNode* merged = new TreeNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);  // push back into heap
    }

    // Step 3: The remaining node is the root of the Huffman Tree
    return minHeap.top();
}

#endif
