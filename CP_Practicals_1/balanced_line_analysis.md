# Problem 5 — Balanced Line Problem

## Problem Summary
Simulate a queue-like line where people can join or leave from either the front or the back. After each operation print the current state of the line.

## Algorithm Explanation
1. Use a `deque<int>` to represent the line — it supports O(1) insertions and deletions at both ends.
2. Read the number of operations Q.
3. For each operation:
   - `push_front x` → `dq.push_front(x)`
   - `push_back x` → `dq.push_back(x)`
   - `pop_front` → check non-empty, then `dq.pop_front()`
   - `pop_back` → check non-empty, then `dq.pop_back()`
4. After every valid operation, iterate and print the entire deque.

## Time Complexity
- Each operation: O(1)
- Printing after each operation: O(current size of deque)
- **Overall for Q operations: O(Q · N)** where N is the max line length

## Space Complexity
- Deque stores at most all inserted elements: **O(N)**

## Screenshot
![Program Output](balanced_line_screenshot.png)

## Reflection
This problem illustrated the power of `std::deque` as a double-ended queue. Unlike a `vector` (which is expensive at the front) or a plain `queue` (which only supports one-end removal), a `deque` offers O(1) push/pop at *both* ends. I also learnt to guard pop operations against an empty deque to avoid undefined behaviour.
