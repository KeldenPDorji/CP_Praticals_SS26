#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // deque stores indices; front always holds index of current window's max
    deque<int> dq;

    cout << "Sliding window maximums: ";
    for (int i = 0; i < n; i++) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove indices from back whose values are <= current element
        // (they can never be the maximum for any future window)
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
    cout << endl;

    return 0;
}
