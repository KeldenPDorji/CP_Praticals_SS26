# Problem 8 — Subset Generation

## Problem Summary
Given a set of N numbers, enumerate and print all 2^N possible subsets (including the empty set).

## Algorithm Explanation
Each subset of N elements can be uniquely represented by a **bitmask** — an integer from `0` to `2^N - 1`. In bitmask `mask`, if bit `i` is **1** it means element `arr[i]` is included in that subset; if **0** it is excluded.

**Steps:**
1. Compute `totalSubsets = 1 << N` (i.e., 2^N).
2. Loop `mask` from `0` to `totalSubsets - 1`.
3. For each `mask`, loop over all bit positions `i` from `0` to `N-1`. If `mask & (1 << i)` is non-zero, include `arr[i]` in the printed subset.

**Example for N=3, arr={1,2,3}:**

| mask (binary) | Subset   |
|---------------|----------|
| 000           | {}       |
| 001           | {1}      |
| 010           | {2}      |
| 011           | {1 2}    |
| 100           | {3}      |
| 101           | {1 3}    |
| 110           | {2 3}    |
| 111           | {1 2 3}  |

## Time Complexity
- Outer loop: 2^N iterations
- Inner loop: N iterations per mask
- **Overall: O(N · 2^N)**

## Space Complexity
- No extra data structures beyond the input array: **O(N)**

## Screenshot
![Program Output](subset_generation_screenshot.png)

## Reflection
Bitmasking is a very elegant technique for subset enumeration. Instead of using recursion or an explicit stack, every possible selection state is encoded in a single integer. I learnt to check individual bits using `mask & (1 << i)` and to generate all masks with a simple loop. This pattern is the foundation of many DP-on-subsets problems in competitive programming.
