# Heap Data Structure

## What is a Heap?

A **Heap** is a specialized tree-based data structure that satisfies the **Heap Property**. It is essentially a **Complete Binary Tree**, which means all levels of the tree are fully filled except possibly the last level, which is filled from left to right.

Because it is a complete binary tree, heaps are usually implemented using **Arrays** rather than Node objects with pointers.

### Types of Heaps

1.  **Max-Heap**: The value of each node is **greater than or equal to** the values of its children. The largest element is always at the Root.
2.  **Min-Heap**: The value of each node is **less than or equal to** the values of its children. The smallest element is always at the Root.

---

## Visual Representation (Min-Heap)

**Tree View:**
```text
       [ 1 ]
      /     \
   [ 3 ]   [ 6 ]
   /   \   /
[ 5 ] [ 9 ][ 8 ]
```
*   Root (1) is the smallest.
*   Parents are smaller than children.

**Array View:**
`[ 1, 3, 6, 5, 9, 8 ]`

### Array Index Mapping
If a node is at index `i`:
*   **Left Child**: `2 * i + 1`
*   **Right Child**: `2 * i + 2`
*   **Parent**: `(i - 1) // 2`

---

## Common Operations

### 1. Insertion
Add the new element to the end of the array (bottom-left of the tree). Then, **"Bubble Up"** (or Heapify Up) by swapping it with its parent until the heap property is restored.

### 2. Extraction (Pop Max/Min)
Remove the Root (the max or min). Move the **last element** of the heap to the Root position. Then, **"Bubble Down"** (or Heapify Down) by swapping it with the larger/smaller child until the heap property is restored.

### 3. Peek
Return the value at the Root without removing it.

---

## Time Complexity

| Operation | Complexity | Explanation |
| :--- | :--- | :--- |
| **Access Max/Min** | O(1) | It's always at index 0. |
| **Insertion** | O(log n) | You might have to swap up the height of the tree. |
| **Deletion (Extract)** | O(log n) | You might have to swap down the height of the tree. |
| **Search** | O(n) | Heaps are not optimized for searching arbitrary elements. |

## Advantages and Disadvantages

### Advantages
*   **Efficiency**: Finds the minimum or maximum element in O(1) time.
*   **Memory**: Efficiently implemented using arrays, no overhead for pointers.
*   **Sorting**: Basis for Heap Sort, which is O(n log n) in place.

### Disadvantages
*   **Not for Searching**: Finding an arbitrary element takes O(n), unlike a BST which takes O(log n).
*   **Not Ordered**: Unlike a BST, printing a heap does not give sorted data (except for the root).

## Practical Use Cases

*   **Priority Queues**: Used in scheduling tasks where some tasks have higher priority (e.g., CPU scheduling).
*   **Dijkstra's Algorithm**: Used to find the shortest path in graphs efficiently.
*   **Heap Sort**: An efficient sorting algorithm.
*   **K-th Largest/Smallest Element**: Efficiently finding the top K items in a stream of data.

---

## Code Example (Python)

Python has a built-in module `heapq` that implements a Min-Heap.

```python
import heapq

# Create an empty heap
min_heap = []

# Insertion (Push)
heapq.heappush(min_heap, 10)
heapq.heappush(min_heap, 1)
heapq.heappush(min_heap, 5)

print("Heap:", min_heap) 
# Output might look like [1, 10, 5] (Array representation)

# Access Smallest (Peek)
print("Smallest:", min_heap[0]) 
# Output: 1

# Extraction (Pop)
smallest = heapq.heappop(min_heap)
print("Removed:", smallest) 
# Output: 1
print("New Heap:", min_heap)
# Output: [5, 10]

# Converting a list to a heap
nums = [5, 7, 9, 1, 3]
heapq.heapify(nums)
print("Heapified List:", nums)
```

## Summary
Use a **Heap** when you constantly need to access the **highest** or **lowest** priority element efficiently, but don't need to search for arbitrary elements.