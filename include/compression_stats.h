// compression_stats.h
#ifndef COMPRESSION_STATS_H
#define COMPRESSION_STATS_H

#include <string>
#include <iostream>

void printCompressionStats(
    const std::string& input,
    const std::string& encoded,
    const std::unordered_map<char, std::string>& huffmanCode
) {
    int originalBits   = input.length() * 8;
    int dataBits       = encoded.length();

    // 1) Compute map overhead
    int mapBits = 0;
    for (auto& p : huffmanCode) {
        mapBits += 8               // 8 bits to store the character
                 + p.second.length();  // plus the length of its code
    }

    int totalCompressedBits = dataBits + mapBits;
    float ratio = 100.0f * (1.0f - (float)totalCompressedBits / originalBits);

    std::cout << "\nCompression Stats:\n";
    std::cout << " Original Bits:     " << originalBits   << "\n";
    std::cout << " Data Bits:         " << dataBits       << "\n";
    std::cout << " Code Map Bits:     " << mapBits        << "\n";
    std::cout << " Total Compressed:  " << totalCompressedBits << "\n";
    std::cout << " Compression Ratio: " << ratio << "%\n";
}

#endif
