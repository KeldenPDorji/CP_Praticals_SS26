# Problem 9 — Count Subsets with Even Sum

## Problem Summary
Given N integers, count how many of the 2^N possible subsets have a sum that is divisible by 2 (even). The empty set (sum = 0) is also counted.

## Algorithm Explanation
Uses the same **bitmask enumeration** as Problem 8:

1. Iterate `mask` from `0` to `2^N - 1`.
2. For each mask, compute the subset sum by checking which bits are set.
3. If `sum % 2 == 0`, increment the counter.
4. Print the final count.

**Example for N=3, arr={1,2,3}:**

| mask | Subset   | Sum | Even? |
|------|----------|-----|-------|
| 000  | {}       | 0   | ✓     |
| 001  | {1}      | 1   | ✗     |
| 010  | {2}      | 2   | ✓     |
| 011  | {1,2}    | 3   | ✗     |
| 100  | {3}      | 3   | ✗     |
| 101  | {1,3}    | 4   | ✓     |
| 110  | {2,3}    | 5   | ✗     |
| 111  | {1,2,3}  | 6   | ✓     |

Count = **4**

**Mathematical insight:** For any array with at least one odd number, exactly half of all 2^N subsets have even sum. If all numbers are even, all 2^N subsets have even sum.

## Time Complexity
- 2^N masks × N-bit check per mask: **O(N · 2^N)**

## Space Complexity
- No extra data structures: **O(N)**

## Screenshot
![Program Output](count_subsets_even_sum_screenshot.png)

## Reflection
This problem built naturally on Problem 8. I re-used the bitmask enumeration and added a simple parity check. An interesting observation is that for arrays containing at least one odd element, the answer is always exactly `2^(N-1)`. Knowing this mathematical property could allow an O(1) solution after a linear scan, but the bitmask approach is more general and educational.
