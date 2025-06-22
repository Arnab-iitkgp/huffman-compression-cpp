// frequency_map.h
#ifndef FREQUENCY_MAP_H //we often reuse the same header files in different parts of our program. Without header guards, the compiler might try to read the same file multiple times, which can cause errors.
#define FREQUENCY_MAP_H

#include <unordered_map>
#include <string>

std::unordered_map<char, int> buildFrequencyMap(const std::string& input) {
    std::unordered_map<char, int> freq;
    for (char ch : input) {
        freq[ch]++;
    }
    return freq;
}

#endif
