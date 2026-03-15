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

    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i];
        if (i != 0) cout << " ";
    }
    cout << endl;

    return 0;
}
