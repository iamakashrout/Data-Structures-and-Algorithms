# Graph Data Structure Explained

## What is a Graph?

A **Graph** is a non-linear data structure consisting of two main components:
1.  **Vertices (Nodes)**: The entities (like people, cities, or web pages).
2.  **Edges (Connections)**: The lines connecting the vertices (like friendships, roads, or hyperlinks).

Unlike trees, graphs do not have a strict hierarchy (no root node). A graph is just a network of things connected to other things. In fact, a Tree is just a specific type of Graph (connected, acyclic, undirected).

---

## Analogy: Social Networks

Think of Facebook or LinkedIn.
*   **You** are a **Vertex**.
*   **Your Friend** is another **Vertex**.
*   If you are friends, there is a line (**Edge**) connecting you.

If you want to see how you are connected to a celebrity, you traverse the graph from your node to their node through the edges of mutual friends.

---

## Key Terminology

1.  **Directed Graph (Digraph)**: Edges have a direction (one-way street).
    *   *Example*: Twitter/Instagram (You follow them, they might not follow you). `A -> B`
2.  **Undirected Graph**: Edges have no direction (two-way street).
    *   *Example*: Facebook Friends (If A is friends with B, B is friends with A). `A - B`
3.  **Weighted Graph**: Edges have a "weight" or "cost" associated with them.
    *   *Example*: Google Maps (Distance or time between cities).
4.  **Cyclic vs. Acyclic**: A graph has a cycle if you can start at a node and follow edges back to the same node.

---

## How to Represent a Graph?

There are two common ways to store a graph in code:

### 1. Adjacency Matrix
A 2D array (grid) of size `V x V` (where V is the number of vertices).
*   `matrix[i][j] = 1` if there is an edge from `i` to `j`.
*   **Pros**: Fast to check if an edge exists (O(1)).
*   **Cons**: Uses a lot of memory (O(V^2)), even if there are few edges.

### 2. Adjacency List (Most Common)
A list or dictionary where each vertex stores a list of its neighbors.
*   `{ 'A': ['B', 'C'], 'B': ['A'], 'C': ['A'] }`
*   **Pros**: Saves memory (O(V + E)). Efficient for iterating over neighbors.
*   **Cons**: Slightly slower to check if a specific edge exists.

---

## Graph Traversals

Just like trees, we need ways to visit every node in a graph.

### 1. Breadth-First Search (BFS)
*   **Strategy**: Explore neighbors first, then neighbors of neighbors. (Wave-like motion).
*   **Data Structure**: Queue.
*   **Use Case**: Finding the **shortest path** in an unweighted graph (e.g., "degrees of separation").

### 2. Depth-First Search (DFS)
*   **Strategy**: Go as deep as possible down one path before backtracking.
*   **Data Structure**: Stack (or Recursion).
*   **Use Case**: Maze solving, detecting cycles, checking connectivity.

---

## Famous Graph Algorithms

1.  **Dijkstra's Algorithm**: Finds the shortest path from a starting node to all other nodes in a weighted graph (like GPS).
2.  **Bellman-Ford Algorithm**: Similar to Dijkstra but handles negative edge weights.
3.  **Prim's & Kruskal's Algorithms**: Finds the **Minimum Spanning Tree (MST)** – connecting all nodes with the minimum total edge weight (used in network design).
4.  **Topological Sort**: Arranges nodes linearly based on dependencies (used in build systems like Webpack or Makefiles).

---

## Complexity Analysis

| Operation | Adjacency List | Adjacency Matrix |
| :--- | :--- | :--- |
| **Space** | O(V + E) | O(V^2) |
| **Add Vertex** | O(1) | O(V^2) (Resize) |
| **Add Edge** | O(1) | O(1) |
| **BFS/DFS** | O(V + E) | O(V^2) |

*   **V**: Number of Vertices
*   **E**: Number of Edges

---

## Practical Use Cases

*   **Google Maps**: Finding the shortest route (Weighted Graph).
*   **Social Media**: Suggesting friends ("People you may know").
*   **World Wide Web**: PageRank algorithm treats the web as a massive graph of links.
*   **Network Routing**: How data packets travel across the internet.
*   **Recommendation Systems**: Netflix/Amazon connecting users to products.

---

## Code Example (Python)

Here is a simple implementation of a Graph using an Adjacency List and a BFS traversal.

```python
from collections import deque

class Graph:
    def __init__(self):
        # Dictionary to store the graph: {node: [neighbors]}
        self.adj_list = {}

    def add_edge(self, u, v):
        # For undirected graph, add connection both ways
        if u not in self.adj_list: self.adj_list[u] = []
        if v not in self.adj_list: self.adj_list[v] = []
        
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def bfs(self, start_node):
        visited = set()
        queue = deque([start_node])
        visited.add(start_node)

        print(f"BFS starting from {start_node}:", end=" ")

        while queue:
            current = queue.popleft()
            print(current, end=" ")

            for neighbor in self.adj_list.get(current, []):
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        print()

# Usage
g = Graph()
g.add_edge('A', 'B')
g.add_edge('A', 'C')
g.add_edge('B', 'D')
g.add_edge('C', 'E')

# Graph Structure:
#      A
#     / \
#    B   C
#    |   |
#    D   E

g.bfs('A')
# Output: BFS starting from A: A B C D E 
```

## Summary
Graphs are the ultimate data structure for modeling **relationships**.
*   Use **BFS** for shortest paths.
*   Use **DFS** for exploring and searching.
*   Use **Dijkstra** when distance/cost matters.