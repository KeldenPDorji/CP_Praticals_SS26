#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return false;
        
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    vector<vector<pair<int, long long>>> adj(n);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
        adj[edges[i].u].push_back({edges[i].v, edges[i].w});
        adj[edges[i].v].push_back({edges[i].u, edges[i].w});
    }
    
    DSU dsu(n);
    vector<Edge> mst;
    long long totalWeight = 0;
    vector<bool> visited(n, false);
    vector<int> component(n);  // To track connected components
    
    // Boruvka's Algorithm
    for (int i = 0; i < n; i++) {
        component[i] = i;
    }
    
    int numComponents = n;
    
    while (numComponents > 1) {
        vector<Edge> minEdges(n, {-1, -1, LLONG_MAX});
        
        // For each component, find minimum outgoing edge
        for (const auto& e : edges) {
            int compU = dsu.find(e.u);
            int compV = dsu.find(e.v);
            
            // Edge connects different components
            if (compU != compV) {
                // Track minimum edge from component compU
                if (e.w < minEdges[compU].w) {
                    minEdges[compU] = e;
                }
                // Track minimum edge from component compV
                if (e.w < minEdges[compV].w) {
                    minEdges[compV] = e;
                }
            }
        }
        
        // Add minimum edges to MST
        for (int i = 0; i < n; i++) {
            if (minEdges[i].u != -1) {
                if (dsu.unite(minEdges[i].u, minEdges[i].v)) {
                    mst.push_back(minEdges[i]);
                    totalWeight += minEdges[i].w;
                    numComponents--;
                }
            }
        }
    }
    
    // Output MST
    cout << "Minimum Spanning Tree (Boruvka's Algorithm):\n";
    cout << "Total Weight: " << totalWeight << "\n";
    cout << "Edges in MST:\n";
    for (const auto& e : mst) {
        cout << "  " << e.u + 1 << " -- " << e.v + 1 << " (weight: " << e.w << ")\n";
    }
    cout << "Total edges in MST: " << mst.size() << "\n";
    
    return 0;
}
