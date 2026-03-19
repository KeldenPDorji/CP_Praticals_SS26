#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxAnd = 0;

        // Check all subarrays of length k
        for (int i = 0; i <= n - k; i++) {
            int currentAnd = arr[i];
            for (int j = i + 1; j < i + k; j++) {
                currentAnd &= arr[j];
            }
            maxAnd = max(maxAnd, currentAnd);
        }

        cout << maxAnd << "\n";
    }

    return 0;
}
