#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>
using namespace std;

const double INF = 1e18;

struct Edge {
    int to;
    double a, b;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        double a, b;
        cin >> u >> v >> a >> b;
        graph[u].push_back({v, a, b});
    }

    // Modified Dijkstra for time-dependent edges
    vector<double> arrivalTime(n + 1, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    arrivalTime[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();

        if (t > arrivalTime[u]) continue;

        for (auto& edge : graph[u]) {
            double travelTime = edge.a * t + edge.b;
            double newArrival = t + travelTime;

            if (newArrival < arrivalTime[edge.to]) {
                arrivalTime[edge.to] = newArrival;
                pq.push({newArrival, edge.to});
            }
        }
    }

    if (arrivalTime[n] == INF) {
        cout << "-1\n";
    } else {
        cout << fixed << setprecision(2) << arrivalTime[n] << "\n";
    }

    return 0;
}
