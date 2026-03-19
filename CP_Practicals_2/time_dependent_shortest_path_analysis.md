# Problem 6 — Time-Dependent Shortest Path

## Problem Summary
Find the **earliest arrival time** from node 1 to node N when each directed edge has a time-dependent travel function f(t) = a·t + b, where t is the time we enter the edge.

## Algorithm Explanation
1. Model the problem as a **modified Dijkstra's algorithm** adapted for time-dependent edges.
2. For each edge from node `u` to node `v` with parameters (a, b):
   - If we arrive at `u` at time `t`, the travel time on this edge is `a·t + b`.
   - Arrival time at `v` is `t + (a·t + b) = (1 + a)·t + b`.
3. Maintain an arrival time array and use a **min-heap priority queue**:
   - Start at node 1 with time 0.
   - For each node `u` with arrival time `t`, relax all outgoing edges:
     - Calculate new arrival time at each neighbor `v`.
     - If this is better than the current best, update and enqueue.
4. Return the arrival time at node N.

## Time Complexity
- **O((N + M) log N)** — similar to standard Dijkstra (assuming the time function is linear)

## Space Complexity
- **O(N + M)** for the graph and distance array

## Screenshot
![Program Output](time_dependent_shortest_path_screenshot.png)

## Reflection
This problem extended my understanding of Dijkstra's algorithm to handle **time-dependent edge weights**. The key realization is that despite the edges being "dynamic," the algorithm still works because we process nodes in order of earliest arrival time. The linear time function (a·t + b) ensures that the order remains consistent. This teaches an important lesson: many graph algorithms can be adapted for more complex models by carefully reformulating the state and relaxation conditions.

