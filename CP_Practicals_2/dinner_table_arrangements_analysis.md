# Problem 1 — Dinner Table Arrangements

## Problem Summary
Arrange N friends around a circular table such that no two adjacent people share any common allergy. Determine if such an arrangement exists.

## Algorithm Explanation
1. Represent each friend's allergies as a **bitset of size 30** (for allergy IDs 1-30).
2. Use **backtracking** to try all permutations of seating arrangements.
3. For each position, try placing each unused friend if:
   - They share **no common allergies** with the previous person (bitwise AND = 0).
4. When all N positions are filled, verify the last person is compatible with the first person to close the circle.
5. If any complete arrangement is found, return **YES**; otherwise **NO**.

## Time Complexity
- Worst case: **O(N!)** for exploring all permutations
- With pruning via allergy checks, practical performance is much better

## Space Complexity
- Bitsets for allergies: **O(N)**
- Recursion stack: **O(N)**
- Total: **O(N)**

## Screenshot
![Program Output](dinner_table_arrangements_screenshot.png)

## Reflection
This problem introduced me to using **bitsets** for efficient set operations on small fixed-size domains. The key insight is that checking if two people share allergies is just a bitwise AND operation — if the result is 0, they're compatible. The circular constraint adds complexity: after filling all positions, we must verify the last person is compatible with the first. Backtracking with pruning makes this feasible for N ≤ 20.

