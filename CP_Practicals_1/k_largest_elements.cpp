#include <iostream>
#include <vector>
#include <queue>
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

    // Max-heap: the largest element is always at the top
    priority_queue<int> maxHeap(arr.begin(), arr.end());

    cout << "K largest elements: ";
    for (int i = 0; i < k; i++) {
        cout << maxHeap.top();
        maxHeap.pop();
        if (i != k - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
