#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalSubsets = 1 << n; // 2^N subsets

    cout << "All subsets:" << endl;
    for (int mask = 0; mask < totalSubsets; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is set in the current mask
            if (mask & (1 << i)) {
                cout << arr[i] << " ";
            }
        }
        cout << "}" << endl;
    }

    return 0;
}
