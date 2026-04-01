# Floyd-Warshall Algorithm - All Pairs Shortest Path

## Problem Summary
Compute the shortest paths between **every pair of vertices** in a weighted directed graph. The graph can contain negative edge weights but must not have negative cycles.

## Algorithm Explanation

### Core Concept
Floyd-Warshall uses **dynamic programming** with three nested loops to build up shortest paths progressively.

### How It Works

1. **Initialization**:
   - Create a distance matrix `dist[i][j]`
   - Set `dist[i][i] = 0` for all vertices
   - Set `dist[i][j] = weight(i,j)` if edge exists, else `INF`

2. **Dynamic Programming**:
   - For each **intermediate vertex k** from 1 to n:
     - For each **source i** from 1 to n:
       - For each **destination j** from 1 to n:
         - Check if path through k is shorter:
           ```
           dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
           ```

3. **Key Insight**:
   - In iteration k, we consider paths using only vertices 1 to k as intermediate nodes
   - After k iterations, all shortest paths considering vertices 1 to k are found
   - After n iterations, all shortest paths are computed

### Example
```
Graph: 3 vertices, edges: 1→2(4), 2→3(2), 1→3(10)

Initial dist:
  1  2  3
1 0  4  10
2 ∞  0  2
3 ∞  ∞  0

After k=1 (using vertex 1):
  1  2  3
1 0  4  10
2 ∞  0  2
3 ∞  ∞  0

After k=2 (using vertices 1,2):
  1  2  3
1 0  4  6     (1→2→3 = 6 < 10)
2 ∞  0  2
3 ∞  ∞  0

After k=3 (using all vertices):
  1  2  3
1 0  4  6
2 ∞  0  2
3 ∞  ∞  0
```

## Complexity Analysis

### Time Complexity
- **O(n³)** - Three nested loops over n vertices
- This is **optimal** for all-pairs shortest path with negative weights
- Better than running Dijkstra from each vertex: O(n · (n + m) log n)

### Space Complexity
- **O(n²)** - For the distance matrix
- No additional logarithmic factors like in heap-based algorithms

## Characteristics

| Feature | Details |
|---------|---------|
| **Handles Negative Edges** | ✅ Yes |
| **Detects Negative Cycles** | ✅ Yes (check diagonal for negatives after algorithm) |
| **Best For** | Dense graphs, all-pairs shortest paths |
| **Parallelizable** | ⚠️ Limited (outer loop k must be sequential) |
| **Space Efficient** | ❌ Requires O(n²) space |

## Advantages & Disadvantages

### Advantages ✅
1. **Simple to implement** - Three nested loops
2. **Handles negative weights** - Works with any weight
3. **Detects negative cycles** - Can identify them
4. **Computes all-pairs paths** - Single algorithm solves complete problem
5. **Fixed time complexity** - O(n³) guaranteed, no randomization

### Disadvantages ❌
1. **O(n³) time complexity** - Impractical for very large n (>1000)
2. **O(n²) space** - Must store entire matrix
3. **Not suitable for sparse graphs** - Faster alternatives exist (Dijkstra n times)
4. **No early termination** - Always runs full n³ iterations
5. **Cache unfriendly** - Poor cache locality in nested loops

## When to Use

✅ Use Floyd-Warshall when:
- Need all-pairs shortest paths
- Graph has negative edge weights
- Graph is dense (m ≈ n²)
- n is small (≤ 500)
- Need to detect negative cycles

❌ Avoid when:
- Graph is sparse and only need single-source paths
- n is very large (>1000) - use Dijkstra or Bellman-Ford instead
- Negative cycles are known to not exist

## Real-World Applications

1. **Network Routing** - Find all routes between routers
2. **Transitive Closure** - Determine reachability between all pairs
3. **Game AI Pathfinding** - Precompute distances for intelligent movement
4. **Traffic Analysis** - Analyze all possible routes in road networks
5. **Database Query Optimization** - Compute connectivity relationships

## Implementation Details

- **Overflow Protection**: Check if intermediate values might overflow
- **Negative Cycle Detection**: If dist[i][i] < 0 after algorithm, negative cycle exists
- **Space Optimization**: Can use two matrices to save intermediate states (rarely needed)
- **Initialization**: Properly handle non-existent edges as INF

## Reflection

Floyd-Warshall is an elegant demonstration of **dynamic programming's power**. What makes it brilliant is how it transforms the "all-pairs shortest path" problem from something that seems quadratic in nature (n² pairs) into a straightforward DP solution. The key insight—processing intermediate vertices in order—ensures that when we consider a path through vertex k, all optimal paths using only vertices 1 to k-1 are already known.

Unlike Dijkstra or Bellman-Ford which work from a single source, Floyd-Warshall treats the problem holistically. Its O(n³) complexity is acceptable for small to medium graphs, and there's a beautiful symmetry to it: three nested loops, three conceptual roles (source, destination, intermediate). It's a problem where the algorithm complexity matches the problem's inherent complexity.

The ability to handle negative weights (including detecting negative cycles) makes it versatile. In competitive programming, it's often the go-to choice when the problem explicitly allows negative weights or requires all-pairs computation, especially when n ≤ 500.
