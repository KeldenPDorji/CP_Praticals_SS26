// Count of Subsets with Sum Equal to Target
// Reference: https://www.geeksforgeeks.org/dsa/count-of-subsets-with-sum-equal-to-x/
//
// Approach: Dynamic Programming (subset-sum DP)
//   dp[i][j] = number of subsets of the first i elements that sum to j
//   Transition:
//     - Exclude arr[i-1]: dp[i][j] = dp[i-1][j]
//     - Include arr[i-1] (if j >= arr[i-1]): dp[i][j] += dp[i-1][j - arr[i-1]]
//   Base case: dp[i][0] = 1 for all i (empty subset always sums to 0)

#include <iostream>
#include <vector>
using namespace std;

int countSubsetsWithTargetSum(const vector<int>& arr, int target) {
    int n = arr.size();

    // dp[j] = number of subsets seen so far that sum to j
    // (space-optimised 1D DP — iterate j backwards to avoid using same element twice)
    vector<long long> dp(target + 1, 0);
    dp[0] = 1; // empty subset

    for (int i = 0; i < n; i++) {
        // Traverse right-to-left to avoid counting arr[i] more than once
        for (int j = target; j >= arr[i]; j--) {
            dp[j] += dp[j - arr[i]];
        }
    }

    return (int)dp[target];
}

int main() {
    int n, target;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    int result = countSubsetsWithTargetSum(arr, target);
    cout << "Number of subsets with sum " << target << ": " << result << endl;

    return 0;
}
