#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);

    cout << "Maximum element: " << maxVal << endl;
    cout << "Minimum element: " << minVal << endl;
    cout << "Sum of elements: " << sum << endl;

    return 0;
}
