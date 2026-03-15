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
    int count = 0;

    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum % 2 == 0) {
            count++;
        }
    }

    cout << "Number of subsets with even sum: " << count << endl;

    return 0;
}
