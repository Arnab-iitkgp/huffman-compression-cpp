# Huffman Compression (C++)

A C++ project implementing Huffman Coding for lossless text compression. It supports both terminal-based and file-based encoding/decoding of `.txt` files.

---

## 📦 Features

- Builds Huffman Tree from input
- Generates binary codes for each character
- Compresses input string or file to Huffman-encoded binary
- Decodes back using the tree
- Shows compression statistics (in bits)
- Reads from `input.txt`, writes to `encoded.txt` and `decoded.txt`

---

## Sample Run

- Input: `aaaaabbbbccccddddaaaabbbbccccddddaaaabbbbccccdddd`
- Original Bits: 392
- Data Bits (Encoded): 98
- Code Map Bits: 40
- Total Compressed: 138
- Compression Ratio: **64.80%**

 **Note:** Huffman coding is highly effective on repetitive input. For small input texts, the total compressed size may occasionally exceed the original size due to the overhead of storing the Huffman code map. This is expected behavior and becomes negligible for larger inputs.

---

## File Structure

| File | Purpose |
|------|---------|
| `main.cpp` | Core logic |
| `input.txt` | Plaintext input |
| `encoded.txt` | Huffman-encoded binary string |
| `decoded.txt` | Output after decompression |
| `*.h` files | Header files (tree, frequency map, etc.) |

---

## How to Build & Run

### Compile

```bash
g++ main.cpp -o huffman
```

### RUN

#### on Linux/Mac

```bash
./huffman
```

#### on Windows

```bash
huffman.exe
```

### input

Put text into input.txt, or enter manually in terminal if file missing.

## Future Enhancements

- Bitwise file writing (true disk compression)
- Save/load Huffman Tree for cross-run decoding
- CLI menu system

---

## 🧑‍💻 Author

Built with ❤️ by Arnab Chakraborty
