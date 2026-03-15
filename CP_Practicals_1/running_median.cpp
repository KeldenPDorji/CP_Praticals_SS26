// Running Median
// Reference: https://www.hackerrank.com/challenges/find-the-running-median/problem
//
// Approach: Two heaps
//   - maxHeap (lower half): stores the smaller half of elements seen so far
//   - minHeap (upper half): stores the larger half of elements seen so far
//
// Invariants maintained after every insertion:
//   1. |maxHeap.size() - minHeap.size()| <= 1
//   2. maxHeap.top() <= minHeap.top()  (every element in lower half <= every element in upper half)
//
// Median:
//   - If both heaps are equal size  -> average of both tops
//   - If maxHeap is larger          -> maxHeap.top()
//   - If minHeap is larger          -> minHeap.top()

#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Max-heap for the lower half
    priority_queue<int> maxHeap;
    // Min-heap for the upper half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << fixed << setprecision(1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // Step 1: Insert into the correct heap
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        // Step 2: Rebalance so sizes differ by at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Step 3: Print current median
        if (maxHeap.size() == minHeap.size()) {
            cout << (maxHeap.top() + minHeap.top()) / 2.0 << "\n";
        } else if (maxHeap.size() > minHeap.size()) {
            cout << (double)maxHeap.top() << "\n";
        } else {
            cout << (double)minHeap.top() << "\n";
        }
    }

    return 0;
}
