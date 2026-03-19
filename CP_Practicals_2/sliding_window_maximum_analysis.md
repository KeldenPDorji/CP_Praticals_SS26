# Problem 3 — Sliding Window Maximum

## Problem Summary
Given an array of N integers and a window size K, find the maximum element in every sliding window of size K as it moves from left to right.

## Algorithm Explanation
1. Use a **deque (double-ended queue)** that stores **array indices** in monotonically decreasing order by value.
2. For each new index `i`:
   - **Remove stale indices** from the front: if `dq.front() < i - k + 1`, that index is outside the current window.
   - **Remove smaller elements** from the back: if `arr[dq.back()] <= arr[i]`, they can never be the maximum for future windows.
   - **Add the current index** to the back.
3. Once the first full window is formed (`i >= k - 1`), the front of the deque holds the index of the maximum element in the current window.
4. Print `arr[dq.front()]` for each complete window.

## Time Complexity
- Each element is pushed and popped from the deque **at most once**: **O(N)**

## Space Complexity
- Deque holds **at most K indices** at any time: **O(K)**

## Screenshot
![Program Output](sliding_window_maximum_screenshot.png)

## Reflection
This is a classic problem that demonstrates how **monotonic deques** can optimize window-based queries. The naive approach of scanning each window takes O(N · K), but the deque technique reduces this to O(N). The key insight is recognizing that once we see a larger element, all smaller elements before it in the deque are irrelevant for future maximums. This problem is fundamental in competitive programming and taught me to think about data structure invariants carefully.

