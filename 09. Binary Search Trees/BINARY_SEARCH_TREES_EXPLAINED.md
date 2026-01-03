# Binary Search Tree (BST) Data Structure

## What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a specific type of Binary Tree that is organized to allow for fast lookups, additions, and removals. While a regular Binary Tree has no specific order, a BST follows a strict rule that makes it behave like a sorted list but in a tree structure.

### The Golden Rule (BST Property)
For every node in the tree:
1.  All values in the **Left Subtree** are **smaller** than the node's value.
2.  All values in the **Right Subtree** are **larger** than the node's value.

---

## Visual Representation

```text
      [ 8 ]
     /     \
  [ 3 ]   [ 10 ]
  /   \      \
[ 1 ] [ 6 ]  [ 14 ]
```
*   **3** is smaller than **8** (Left).
*   **10** is larger than **8** (Right).
*   **1** is smaller than **3**; **6** is larger than **3**.

---

## Common Operations

### 1. Search
To find a value (e.g., 6):
1.  Start at Root (8).
2.  Is 6 < 8? Yes, go **Left** to (3).
3.  Is 6 > 3? Yes, go **Right** to (6).
4.  Found it!
*This is much faster than checking every node because you eliminate half the tree at every step.*

### 2. Insertion
To add a value (e.g., 4):
1.  Start at Root.
2.  Compare and traverse down (Left if smaller, Right if larger) until you hit an empty spot (`None`).
3.  Insert the new node there.

### 3. Deletion
*   **Leaf Node**: Just remove it.
*   **One Child**: Remove the node and replace it with its child.
*   **Two Children**: Find the **in-order successor** (smallest node in the right subtree) or predecessor, swap values, and delete that successor node.

---

## Time Complexity

| Operation | Average Case | Worst Case (Unbalanced) |
| :--- | :--- | :--- |
| **Search** | O(log n) | O(n) |
| **Insertion** | O(log n) | O(n) |
| **Deletion** | O(log n) | O(n) |

*   **O(log n)**: Very fast. If you double the data, it only takes one extra step.
*   **Worst Case**: If you insert sorted data (1, 2, 3, 4, 5), the tree becomes a straight line (like a Linked List), and speed drops to O(n).

## Advantages and Disadvantages

### Advantages
*   **Fast Lookups**: Much faster than searching an unsorted array or linked list.
*   **Sorted Data**: An **In-order Traversal** (Left, Root, Right) visits all nodes in sorted order automatically.
*   **Dynamic**: Can grow and shrink efficiently.

### Disadvantages
*   **Balancing**: If the tree becomes unbalanced (skewed), it loses its performance benefits. You need self-balancing trees (like AVL or Red-Black Trees) to fix this.
*   **No Random Access**: You cannot jump to the 5th element instantly like in an array.

## Practical Use Cases
*   **Databases**: Indexing to find records quickly.
*   **Sets and Maps**: Implementing abstract data types where keys need to be unique and searchable.
*   **Autocomplete**: Variations of BSTs (like Tries) are used for text prediction.

---

## Code Example (Python)

```python
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def search(root, key):
    if root is None or root.val == key:
        return root
    
    if root.val < key:
        return search(root.right, key)
    
    return search(root.left, key)

# Usage
r = Node(50)
r = insert(r, 30)
r = insert(r, 20)
r = insert(r, 40)
r = insert(r, 70)
r = insert(r, 60)
r = insert(r, 80)

# Search for 60
result = search(r, 60)
if result:
    print("Found:", result.val)
else:
    print("Not Found")
```

## Summary
Use a **Binary Search Tree** when you need to maintain a sorted list of data with fast insertion, deletion, and lookup capabilities.