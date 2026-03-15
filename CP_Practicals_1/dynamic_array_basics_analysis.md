# Problem 1 — Dynamic Array Basics

## Problem Summary
Read N integers into a dynamic container and compute three basic statistics: the maximum element, the minimum element, and the sum of all elements.

## Algorithm Explanation
1. Read integer N from input.
2. Allocate a `vector<int>` of size N and populate it by reading N integers.
3. Use STL functions `max_element` and `min_element` to find the extremes.
4. Use `accumulate` to sum all elements.
5. Print the three results.

## Time Complexity
- Reading input: O(N)
- `max_element` / `min_element`: O(N) each
- `accumulate`: O(N)
- **Overall: O(N)**

## Space Complexity
- Storing N elements in a vector: **O(N)**

## Screenshot
![Program Output](dynamic_array_basics_screenshot.png)

## Reflection
This problem introduced the most fundamental use-case of `std::vector` — a resizable, contiguous-memory container. I learnt that STL algorithms like `max_element`, `min_element`, and `accumulate` eliminate the need to write manual loops for these common operations, making code shorter and less error-prone. Using `long long` for the sum guards against integer overflow when the elements are large.
