#include <iostream>
#include <vector>
#include <algorithm>
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

    // Sort so that duplicates are adjacent
    sort(arr.begin(), arr.end());

    // unique shifts duplicates to the end and returns iterator to new logical end
    auto newEnd = unique(arr.begin(), arr.end());
    arr.erase(newEnd, arr.end());

    cout << "Unique elements: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i != (int)arr.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
