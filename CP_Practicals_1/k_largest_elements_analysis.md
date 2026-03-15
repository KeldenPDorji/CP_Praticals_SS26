# Problem 6 — K Largest Elements

## Problem Summary
Given N numbers and an integer K, find and print the K largest numbers in descending order.

## Algorithm Explanation
1. Read N integers into a vector.
2. Build a max-heap `priority_queue<int>` from the vector — the largest element is always accessible at the top in O(1).
3. Pop the top element K times, printing each extracted value. Each pop rearranges the heap in O(log N).

## Time Complexity
- Building the heap from N elements: O(N)
- K extractions, each O(log N): O(K log N)
- **Overall: O(N + K log N)**

## Space Complexity
- Heap stores all N elements: **O(N)**

## Screenshot
![Program Output](k_largest_elements_screenshot.png)

## Reflection
This problem showed how `std::priority_queue` (a max-heap by default) is perfectly suited for "top-K" problems. The heap property guarantees the maximum is always at the root, so extracting the K largest values is straightforward. An alternative is to sort the array in descending order (O(N log N)) and take the first K elements, but the heap approach is more efficient when K << N.
