#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int query = 0; query < q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            arr[pos - 1] = val; // pos is 1-indexed
        } else {
            int i;
            cin >> i; // i is 1-indexed

            // Find maximum in window [i - k + 1, i] (1-indexed)
            // Convert to 0-indexed: [i-k, i-1]
            int maxVal = INT_MIN;
            for (int j = max(0, i - k); j < i; j++) {
                maxVal = max(maxVal, arr[j]);
            }
            cout << maxVal << "\n";
        }
    }

    return 0;
}
