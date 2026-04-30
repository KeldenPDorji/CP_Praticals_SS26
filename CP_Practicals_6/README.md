# CP Practicals 6 - Advanced String Algorithms

Solutions to three advanced string processing algorithms focusing on **Trie data structures** and **palindrome detection**.

## Table of Contents

1. [Basic Trie Algorithm](#problem-1-basic-trie-algorithm)
2. [PATRICIA Trie](#problem-2-patricia-trie)
3. [Manacher's Algorithm](#problem-3-manachers-algorithm)

---

## Problem 1: Basic Trie Algorithm

**Problem Summary:**  
Implement a Trie (prefix tree) data structure to efficiently store and retrieve strings. Support insert, search, and delete operations on a collection of words.

**Data Structure:** Trie (Tree of characters)  
**Screenshot:**  
![Basic Trie](basic_trie_screenshot.png)

**Files:** [`basic_trie.cpp`](basic_trie.cpp) | [`basic_trie_analysis.md`](basic_trie_analysis.md)

---

## Problem 2: PATRICIA Trie

**Problem Summary:**  
Implement a PATRICIA Trie (Practical Algorithm to Retrieve Information Coded in Alphanumeric), an optimized trie variant that compresses chains of single children into a single edge to save space.

**Data Structure:** PATRICIA Trie (Compressed Trie)  
**Screenshot:**  
![PATRICIA Trie](patricia_trie_screenshot.png)

**Files:** [`patricia_trie.cpp`](patricia_trie.cpp) | [`patricia_trie_analysis.md`](patricia_trie_analysis.md)

---

## Problem 3: Manacher's Algorithm

**Problem Summary:**  
Implement Manacher's Algorithm to find the longest palindromic substring in linear time O(n). Also support finding all palindromic substrings and checking if a string is a palindrome.

**Data Structure:** Manacher's Algorithm (Linear Time Palindrome Detection)  
**Screenshot:**  
![Manacher's Algorithm](manacher_algorithm_screenshot.png)

**Files:** [`manacher_algorithm.cpp`](manacher_algorithm.cpp) | [`manacher_algorithm_analysis.md`](manacher_algorithm_analysis.md)

## Problem 2: PATRICIA Trie

**Problem Summary:**  
Implement a PATRICIA (Practical Algorithm to Retrieve Information Coded in Alphanumeric) trie, a space-optimized binary trie structure. This compressed trie stores only the critical branching points, making it ideal for applications like IP routing and key-value storage.

**Key Features:**
- Binary representation of strings
- Space-optimized storage with compressed edges
- Insert, search, and delete operations
- Handles collisions with node splitting

**Data Structure:** Binary PATRICIA Trie  
**Time Complexity:**
- Insert: O(k·m) where k = key length, m = bits per character
- Search: O(k·m)
- Delete: O(k·m)

**Space Complexity:** O(m) - more efficient than regular trie

**Screenshot:**  
![PATRICIA Trie](patricia_trie_screenshot.png)

**Files:**
- [`patricia_trie.cpp`](patricia_trie.cpp)
- [`patricia_trie_analysis.md`](patricia_trie_analysis.md)

**Key Difference from Regular Trie:**
- Uses binary representation
- Stores only branching nodes
- More memory efficient for long keys

**Applications:**
- IP routing (longest prefix matching)
- MAC address lookup in network switches
- URI/URL routing in web servers
- Cryptographic key storage

---

## Problem 3: Manacher's Algorithm

**Problem Summary:**  
Find the longest palindromic substring in a string in linear time O(n). This algorithm uses the properties of palindromes to avoid redundant character comparisons by leveraging symmetry.

**Key Features:**
- Find longest palindromic substring in O(n) time
- Find all palindromic substrings
- Check if a string is a palindrome
- Handles both odd and even-length palindromes

**Algorithm Complexity:**
- **Time Complexity:** O(n) - optimal for this problem
- **Space Complexity:** O(n) for preprocessing

**Key Innovation:**
Uses a symmetry property: if we know a palindrome P centered at C with boundaries [L, R], we can reuse information about mirror positions to skip redundant checks.

**Screenshot:**  
![Manacher's Algorithm](manacher_algorithm_screenshot.png)

**Files:**
- [`manacher_algorithm.cpp`](manacher_algorithm.cpp)
- [`manacher_algorithm_analysis.md`](manacher_algorithm_analysis.md)

**Preprocessing Example:**
```
Original: "babad"
Preprocessed: "#b#a#b#a#d#"
(Adding '#' handles both odd and even length palindromes)
```

**Example Test Cases:**
- "babad" → "bab" or "aba" (length 3)
- "ac" → "a" or "c" (length 1)
- "racecar" → "racecar" (length 7)
- "abacabad" → "abacaba" (length 7)

---

## Comparison Table

| Feature | Basic Trie | PATRICIA Trie | Manacher's |
|---------|-----------|---------------|-----------|
| **Purpose** | String storage & retrieval | Optimized prefix matching | Palindrome detection |
| **Time Complexity** | O(m) | O(k·m) | O(n) |
| **Space Complexity** | O(n·m) | O(m) | O(n) |
| **Best For** | Autocomplete, dictionaries | Routing, IP lookup | Palindrome analysis |
| **Difficulty** | Easy | Medium | Hard |

---

## Learning Outcomes

1. **Trie Data Structures:** Understanding tree-based string storage and optimization techniques
2. **Binary Representations:** Working with bit-level operations and compression
3. **Palindrome Algorithms:** Advanced pattern matching using symmetry properties
4. **Optimization Techniques:** Using algorithm properties to reduce time complexity
5. **Space-Time Tradeoffs:** Optimizing storage while maintaining performance

---

## How to Run

### Compilation
```bash
# Basic Trie
g++ -std=c++17 basic_trie.cpp -o basic_trie
./basic_trie

# PATRICIA Trie
g++ -std=c++17 patricia_trie.cpp -o patricia_trie
./patricia_trie

# Manacher's Algorithm
g++ -std=c++17 manacher_algorithm.cpp -o manacher_algorithm
./manacher_algorithm
```

### Interactive Menu
Each program provides an interactive menu for testing different operations:
1. Choose operation from the menu
2. Enter the required input
3. View the results
4. Repeat or exit

---

## Test Results

### Basic Trie Tests
- ✓ Insert multiple words
- ✓ Search for existing words
- ✓ Search returns false for non-existent words
- ✓ Delete operations remove words correctly
- ✓ Partial matches don't return as complete words

### PATRICIA Trie Tests
- ✓ Binary representation handling
- ✓ Insert with collision resolution
- ✓ Search returns correct results
- ✓ Delete removes entries without affecting others
- ✓ Prefix-based operations work correctly

### Manacher's Algorithm Tests
- ✓ Finds longest palindrome in O(n)
- ✓ Handles odd-length palindromes
- ✓ Handles even-length palindromes
- ✓ Correctly identifies all palindromic substrings
- ✓ Single characters recognized as palindromes

---

## Reflection

### Key Insights

1. **Data Structure Design:** Choosing between Trie variants depends on specific requirements:
   - Basic Trie for simplicity and word-based queries
   - PATRICIA for memory optimization and bit-level operations
   
2. **Algorithm Optimization:** Manacher's algorithm demonstrates how understanding problem structure (palindrome symmetry) can dramatically reduce time complexity from O(n²) to O(n).

3. **Trade-offs:**
   - Space vs. Time: PATRICIA uses less space but has slightly more complex operations
   - Complexity vs. Implementation: Basic Trie is simpler but less optimized
   
4. **Real-world Applications:**
   - Tries power autocomplete in search engines and IDEs
   - PATRICIA enables high-speed IP routing in network infrastructure
   - Palindrome detection is crucial in bioinformatics for DNA analysis

### Challenges Encountered

1. **Handling Edge Cases:** Empty strings, single characters, and duplicate entries required careful consideration
2. **Binary Representation:** Converting strings to binary and managing bit operations was complex
3. **Manacher's Algorithm Symmetry:** Understanding the mirror relationship between palindrome properties was challenging but elegant

### Improvements Made

1. **Error Handling:** Added checks for empty inputs and boundary conditions
2. **Memory Management:** Proper cleanup of dynamically allocated nodes
3. **Code Clarity:** Added detailed comments explaining the algorithm flow
4. **Testing:** Comprehensive test cases for each operation

### Concepts Learned

- **Tree-based Data Structures:** How tries organize data hierarchically
- **String Processing:** Efficient algorithms for text manipulation
- **Symmetry Exploitation:** Using problem properties for optimization
- **Dynamic Programming Concepts:** Manacher's uses concepts similar to DP
- **Memory Optimization:** Techniques to reduce space while maintaining speed

---

## Files Summary

| File | Purpose | Lines |
|------|---------|-------|
| `basic_trie.cpp` | Basic Trie implementation | ~130 |
| `basic_trie_analysis.md` | Time/space complexity analysis | ~110 |
| `patricia_trie.cpp` | PATRICIA Trie implementation | ~200 |
| `patricia_trie_analysis.md` | PATRICIA algorithm analysis | ~130 |
| `manacher_algorithm.cpp` | Manacher's Algorithm implementation | ~180 |
| `manacher_algorithm_analysis.md` | Manacher's complexity analysis | ~180 |

---

## Conclusion

These three algorithms represent fundamental concepts in competitive programming and systems design:

1. **Basic Trie** provides the foundation for understanding tree-based storage structures
2. **PATRICIA Trie** demonstrates advanced optimization techniques for real-world systems
3. **Manacher's Algorithm** shows how mathematical insights can revolutionize algorithmic efficiency

Mastering these algorithms is essential for tackling interview questions, optimizing production systems, and understanding how modern technologies like search engines and network routers work under the hood.
