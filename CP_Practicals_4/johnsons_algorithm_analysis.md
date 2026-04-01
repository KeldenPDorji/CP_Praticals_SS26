# Johnson's Algorithm - All Pairs Shortest Path

## Problem Summary
Compute the shortest paths between **every pair of vertices** in a weighted directed graph with **possibly negative edge weights** (but no negative cycles), more efficiently than Floyd-Warshall for sparse graphs.

## Algorithm Explanation

### Core Concept
Johnson's Algorithm combines **Bellman-Ford** (to handle negative weights and detect cycles) with **Dijkstra** (which is faster on non-negative weights). It "reweights" edges to eliminate negative weights while preserving shortest path relationships.

### How It Works

#### Step 1: Add Source Vertex
- Create a virtual source vertex `s` (vertex 0)
- Add edges from `s` to all other vertices with weight 0
- This ensures all vertices are reachable from `s`

#### Step 2: Run Bellman-Ford
- Run Bellman-Ford from source `s` to compute potentials `h[v]` for all vertices
- These represent the shortest path distances from `s` to each vertex
- If negative cycle is detected during this step, **report and exit**

#### Step 3: Reweight Edges
- For each edge `(u, v)` with weight `w`, create new weight:
  ```
  w'(u, v) = w(u, v) + h[u] - h[v]
  ```
- **Key property**: All new weights are non-negative!
- **Shortest paths are preserved**: If path P in original graph has distance d, 
  then path P in reweighted graph has distance d + h[source] - h[destination]

#### Step 4: Run Dijkstra
- For each source vertex `src` (1 to n):
  - Run **Dijkstra** on reweighted graph
  - Get distances d'[v]
  - Convert back to original distances:
    ```
    d[src][v] = d'[v] - h[src] + h[v]
    ```

### Example
```
Original Graph:
  1 → 2 (4)
  2 → 3 (-3)
  1 → 3 (3)

After adding source 0:
  0 → 1 (0), 0 → 2 (0), 0 → 3 (0)

Bellman-Ford from 0 gives potentials:
  h[0] = 0, h[1] = 0, h[2] = 4, h[3] = 1

Reweighting:
  (1,2): 4 + 0 - 4 = 0
  (2,3): -3 + 4 - 1 = 0
  (1,3): 3 + 0 - 1 = 2

All non-negative! Now Dijkstra works perfectly.
```

## Complexity Analysis

### Time Complexity
- **Bellman-Ford**: O(n · m)
- **Dijkstra (n times)**: O(n · (m + n) log n) with binary heap
- **Total**: O(n · m + n² · log n)
- For sparse graphs (m = O(n)): **O(n² log n)** - **better than Floyd-Warshall's O(n³)**
- For dense graphs (m = O(n²)): **O(n³)** - comparable to Floyd-Warshall

### Space Complexity
- **O(n + m)** for graph representation
- **O(n)** for potential values and Dijkstra structures
- **Total**: O(n + m) - much better than Floyd-Warshall's O(n²)

## Characteristics

| Feature | Details |
|---------|---------|
| **Handles Negative Edges** | ✅ Yes (but no negative cycles) |
| **Detects Negative Cycles** | ✅ Yes (Bellman-Ford step) |
| **Best For** | Sparse graphs, all-pairs shortest paths |
| **Space Efficiency** | ✅ O(n + m) vs Floyd-Warshall's O(n²) |
| **Faster for Sparse** | ✅ Yes, O(n² log n) vs O(n³) |
| **Complexity** | ⚠️ More complex to implement |

## Advantages & Disadvantages

### Advantages ✅
1. **Better for sparse graphs** - O(n² log n) vs O(n³)
2. **Space efficient** - O(n + m) vs O(n²)
3. **Handles negative weights** - Like Bellman-Ford
4. **Detects negative cycles** - Via Bellman-Ford
5. **Theoretical elegance** - Clever reweighting idea

### Disadvantages ❌
1. **More complex** - Two algorithms combined
2. **Higher constant factors** - Reweighting and conversion overhead
3. **Not faster for dense graphs** - O(n³) like Floyd-Warshall
4. **Slower than Floyd-Warshall for small n** - Due to complexity overhead
5. **Requires graph representation** - Adjacency list needed

## When to Use

✅ Use Johnson's when:
- Graph is **sparse** (m << n²)
- Need all-pairs shortest paths with negative weights
- Space is limited
- n is moderate (100-10,000)
- Want better asymptotic complexity than Floyd-Warshall

❌ Avoid when:
- Graph is **dense** (m ≈ n²) - use Floyd-Warshall
- n is very large (>10,000) - single-source algorithms may suffice
- All vertices aren't reachable - needs modification
- Negative cycles exist - handle separately

## Key Insight: Reweighting

The reweighting formula `w'(u,v) = w(u,v) + h[u] - h[v]` is brilliant:

1. **Preserves shortest paths** - Shortest path distances remain identical
2. **Eliminates negative weights** - All new weights become non-negative
3. **Provably correct** - Mathematical guarantee of correctness
4. **Enables Dijkstra** - Allows use of faster algorithm

This is a beautiful example of **algorithm composition**: combining Bellman-Ford's power with Dijkstra's speed.

## Real-World Applications

1. **Network Routing Protocols** - OSPF-like algorithms for sparse networks
2. **Logistics & Transportation** - Compute all-pairs travel times efficiently
3. **Database Query Planning** - Graph traversal cost estimation
4. **Game AI** - Precompute distances in large game worlds
5. **Social Networks** - Analyze connectivity between many pairs

## Implementation Details

- **Potential values**: h[v] represents shortest path from source to v
- **Reweighting condition**: Always w' ≥ 0 after proper h computation
- **No zero-weight edges after reweighting**: Guarantees Dijkstra correctness
- **Back-conversion**: d[s][v] = d'[v] - h[s] + h[v]

## Comparison: Johnson vs Floyd-Warshall

| Aspect | Johnson | Floyd-Warshall |
|--------|---------|-----------------|
| Time Complexity | O(n² log n) sparse | O(n³) always |
| Space Complexity | O(n + m) | O(n²) |
| Implementation | Complex | Simple |
| Negative Weights | ✅ Yes | ✅ Yes |
| Best for n ≤ 500 | ❌ Floyd-W better | ✅ Yes |
| Best for sparse | ✅ Yes | ❌ No |
| Constant factors | ⚠️ Higher | ✅ Lower |

## Reflection

Johnson's Algorithm is a **masterclass in algorithm design and optimization**. It takes two well-known algorithms (Bellman-Ford and Dijkstra) and combines them ingeniously through the concept of reweighting.

The genius lies in recognizing that:
1. Bellman-Ford can handle negative weights but is O(nm) overall
2. Dijkstra is O((m + n) log n) per source but requires non-negative weights
3. By computing potentials via Bellman-Ford once, then reweighting edges to be non-negative, we can use Dijkstra repeatedly

The reweighting formula itself is elegant—it's not arbitrary but mathematically grounded in the principle that "detours" through intermediate vertices with different potentials cancel out, preserving shortest path distances.

In competitive programming, Johnson's Algorithm is chosen when:
- The problem explicitly states sparse graphs with negative weights
- You need all-pairs shortest paths
- Memory is limited

It's a powerful reminder that algorithm design isn't always about inventing something new, but about cleverly **combining existing techniques** to achieve better performance. The fact that it works—that reweighting truly preserves shortest paths—is a beautiful mathematical insight that shows why understanding algorithm theory matters.
