#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove indices from back whose values are <= current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Start printing once the first full window is formed
        if (i >= k - 1) {
            cout << arr[dq.front()];
            if (i != n - 1) cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
