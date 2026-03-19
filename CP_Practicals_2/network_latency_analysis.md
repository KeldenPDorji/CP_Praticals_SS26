# Problem 5 — Network Latency

## Problem Summary
Given a network of N routers connected by M bidirectional cables with latencies, find the **minimum total latency** to travel from router 1 to router N.

## Algorithm Explanation
1. Build an **undirected weighted graph** where nodes are routers and edges are cables.
2. Apply **Dijkstra's algorithm**:
   - Initialize distances to all nodes as infinity, except the source (router 1) which is 0.
   - Use a **min-heap priority queue** to always process the node with the smallest known distance.
   - For each node `u` being processed, relax all its edges to neighbors:
     - If `dist[u] + weight < dist[v]`, update `dist[v]` and enqueue `v`.
3. Continue until the priority queue is empty.
4. Return `dist[N]` if it's finite; otherwise return **-1** (unreachable).

## Time Complexity
- **O((N + M) log N)** with a binary heap (typical for Dijkstra)

## Space Complexity
- **O(N + M)** for the graph and distance array

## Screenshot
![Program Output](network_latency_screenshot.png)

## Reflection
This problem is a direct application of **Dijkstra's shortest path algorithm**. The key insight is recognizing when to use this classic algorithm. Dijkstra works for non-negative edge weights (latencies here) and efficiently finds the shortest path from a single source to all other nodes. The priority queue optimization ensures we always explore the most promising node next, making it much faster than a simple BFS or DFS approach. This is a foundational algorithm for any competitive programmer.

