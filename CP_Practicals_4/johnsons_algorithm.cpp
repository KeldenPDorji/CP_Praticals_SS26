#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

vector<pair<int, long long>> adj[505];
vector<Edge> edges;
long long dist[505];
int n, m;

// Bellman-Ford algorithm to detect negative cycles and compute potentials
bool bellmanFord(int src) {
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    
    // Check for negative cycles
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            return false;  // Negative cycle detected
        }
    }
    return true;
}

// Dijkstra's algorithm with modified weights
void dijkstra(int src, vector<long long>& d) {
    fill(d.begin(), d.end(), INF);
    d[src] = 0;
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        
        if (cost > d[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            // Modified weight using potential function
            long long modW = w + dist[u] - dist[v];
            if (d[u] + modW < d[v]) {
                d[v] = d[u] + modW;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        edges.push_back({u, v, w});
    }
    
    // Step 1: Add source vertex with edges to all vertices
    int source = 0;
    for (int i = 1; i <= n; i++) {
        adj[source].push_back({i, 0});
        edges.push_back({source, i, 0});
    }
    
    // Step 2: Run Bellman-Ford from source to compute potentials
    if (!bellmanFord(source)) {
        cout << "Graph contains negative cycle!\n";
        return 0;
    }
    
    // Store potentials
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; i++) {
        h[i] = dist[i];
    }
    
    // Step 3: Run Dijkstra from each vertex
    cout << "Shortest paths from each vertex:\n";
    for (int src = 1; src <= n; src++) {
        vector<long long> d(n + 1);
        dijkstra(src, d);
        
        cout << "From vertex " << src << ":\n";
        for (int dest = 1; dest <= n; dest++) {
            if (d[dest] == INF) {
                cout << "  To " << dest << ": INF\n";
            } else {
                // Original distance = modified distance - h[src] + h[dest]
                long long originalDist = d[dest] - h[src] + h[dest];
                cout << "  To " << dest << ": " << originalDist << "\n";
            }
        }
    }
    
    return 0;
}
