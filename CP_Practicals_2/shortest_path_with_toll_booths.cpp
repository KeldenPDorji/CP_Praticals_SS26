#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> toll(n);
    for (int i = 0; i < n; i++) cin >> toll[i];

    struct State {
        int booth, coins, skipsLeft, time;
    };

    queue<State> q;
    map<tuple<int,int,int>, int> visited;

    q.push({0, m, k, 0});
    visited[{0, m, k}] = 0;

    int minTime = INT_MAX;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        int booth = cur.booth;
        int coins = cur.coins;
        int skipsLeft = cur.skipsLeft;
        int time = cur.time;

        if (booth == n) {
            minTime = min(minTime, time);
            continue;
        }

        if (coins >= toll[booth]) {
            int newCoins = coins - toll[booth];
            auto state = make_tuple(booth + 1, newCoins, skipsLeft);
            if (visited.find(state) == visited.end() || visited[state] > time + 1) {
                visited[state] = time + 1;
                q.push({booth + 1, newCoins, skipsLeft, time + 1});
            }
        }

        if (skipsLeft > 0) {
            auto state = make_tuple(booth + 1, coins, skipsLeft - 1);
            if (visited.find(state) == visited.end() || visited[state] > time + 2) {
                visited[state] = time + 2;
                q.push({booth + 1, coins, skipsLeft - 1, time + 2});
            }
        }
    }

    if (minTime == INT_MAX) cout << "-1\n";
    else cout << minTime << "\n";
}