# Problem 7 — Shortest Path with Toll Booths

## Problem Summary
Navigate through N toll booths starting with M coins and at most K skips allowed. At each booth:
- **Pay toll[i]**: Move forward in 1 minute
- **Skip booth**: Move forward in 2 minutes (costs one skip)

Find the **minimum time** to reach booth N, or **-1** if impossible.

## Algorithm Explanation
1. Use **BFS with state-based exploration**: each state is `(booth_index, coins_remaining, skips_remaining)`.
2. From each state at booth `i`:
   - **Option 1 (Pay)**: If `coins >= toll[i]`, move to booth `i+1` with updated coins in **1 minute**.
   - **Option 2 (Skip)**: If `skipsLeft > 0`, move to booth `i+1` with updated skips in **2 minutes**.
3. Use a visited map to avoid re-exploring the same state with a worse time.
4. When reaching booth N, record the time. Continue exploring to find the minimum.

## Time Complexity
- **States**: N booths × M coins × K skips = **O(N · M · K)**
- **BFS**: Each state is processed once, so **O(N · M · K)**

## Space Complexity
- **O(N · M · K)** for the visited map and queue

## Screenshot
![Program Output](shortest_path_with_toll_booths_screenshot.png)

## Reflection
This problem combines **shortest path thinking with constrained state exploration**. The key insight is recognizing that this is not a simple graph problem but a **state-space search** where each state encodes the booth, coins, and skips. BFS naturally finds the shortest time because we explore states in increasing order of time. The state-based approach is powerful for problems with multiple resources and constraints. This teaches an important lesson: some problems require creative state representation to become tractable.

