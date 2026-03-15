#include <iostream>
#include <deque>
#include <string>
using namespace std;

void printDeque(const deque<int>& dq) {
    cout << "Line: [ ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    deque<int> line;
    int q;
    cout << "Enter number of operations: ";
    cin >> q;
    cin.ignore();

    cout << "Operations: push_front x | push_back x | pop_front | pop_back" << endl;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x;
            cin >> x;
            line.push_front(x);
            cout << "After push_front " << x << ": ";
        } else if (op == "push_back") {
            int x;
            cin >> x;
            line.push_back(x);
            cout << "After push_back " << x << ": ";
        } else if (op == "pop_front") {
            if (!line.empty()) {
                cout << "After pop_front (removed " << line.front() << "): ";
                line.pop_front();
            } else {
                cout << "pop_front failed — line is empty." << endl;
                continue;
            }
        } else if (op == "pop_back") {
            if (!line.empty()) {
                cout << "After pop_back (removed " << line.back() << "): ";
                line.pop_back();
            } else {
                cout << "pop_back failed — line is empty." << endl;
                continue;
            }
        } else {
            cout << "Unknown operation: " << op << endl;
            continue;
        }

        printDeque(line);
    }

    return 0;
}
