# Problem 10 — Count of Subsets with Sum Equal to Target

## Problem Summary
Given N non-negative integers and a target sum X, count how many distinct subsets of the array have elements that sum exactly to X.  
(GeeksForGeeks: https://www.geeksforgeeks.org/dsa/count-of-subsets-with-sum-equal-to-x/)

## Algorithm Explanation
Uses **1D subset-sum Dynamic Programming** (space-optimised version of the classic 2D DP):

- `dp[j]` = number of subsets of elements processed so far that sum to exactly `j`.
- **Base case:** `dp[0] = 1` (the empty subset always sums to 0).
- **Transition:** For each element `arr[i]`, iterate `j` from `target` down to `arr[i]` and update:
  ```
  dp[j] += dp[j - arr[i]]
  ```
  Traversing right-to-left ensures each element is considered **at most once** per subset (0/1 knapsack style).

**Example: arr = {1, 2, 3}, target = 3**

Subsets that sum to 3: `{3}` and `{1, 2}` → **Answer: 2**

| i | arr[i] | dp[0] | dp[1] | dp[2] | dp[3] |
|---|--------|-------|-------|-------|-------|
| - | -      | 1     | 0     | 0     | 0     |
| 0 | 1      | 1     | 1     | 0     | 0     |
| 1 | 2      | 1     | 1     | 1     | 1     |
| 2 | 3      | 1     | 1     | 1     | 2     |

## Time Complexity
- Outer loop over N elements, inner loop over `target` values: **O(N × target)**

## Space Complexity
- 1D DP array of size `target + 1`: **O(target)**

## Screenshot
![Program Output](count_subsets_target_sum_screenshot.png)

## Reflection
This problem introduced me to the classic 0/1 knapsack DP pattern applied to counting. The crucial detail is iterating `j` from right-to-left in the inner loop — if iterated left-to-right, the same element could be used multiple times (unbounded knapsack). I initially implemented the 2D version (`dp[i][j]`), which is easier to reason about, then optimised it to 1D. The DP approach is far superior to bitmask enumeration for large N since it is polynomial rather than exponential.
