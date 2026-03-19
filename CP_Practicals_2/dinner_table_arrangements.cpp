#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n;
vector<bitset<30>> allergies;
vector<int> arrangement;
vector<bool> used;

bool canPlace(int person, int prevPerson) {
    if (prevPerson == -1) return true;
    return (allergies[person] & allergies[prevPerson]).none();
}

bool solve(int pos, int firstPerson) {
    if (pos == n) {
        // Check if last person is compatible with first person
        return canPlace(firstPerson, arrangement[n - 1]);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int prevPerson = (pos == 0) ? -1 : arrangement[pos - 1];
            if (canPlace(i, prevPerson)) {
                used[i] = true;
                arrangement[pos] = i;
                int nextFirstPerson = (pos == 0) ? i : firstPerson;

                if (solve(pos + 1, nextFirstPerson)) {
                    return true;
                }

                used[i] = false;
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        allergies.assign(n, bitset<30>());
        used.assign(n, false);
        arrangement.assign(n, -1);

        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int allergy;
                cin >> allergy;
                allergies[i][allergy - 1] = 1;
            }
        }

        if (solve(0, -1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
