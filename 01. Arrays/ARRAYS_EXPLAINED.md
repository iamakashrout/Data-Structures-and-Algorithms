# Array Data Structure

## What is an Array?

An **Array** is a collection of items stored at contiguous memory locations. The idea is to store multiple items of the same type together. This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., the memory location of the first element of the array.

### Key Concepts

1.  **Element**: Each item stored in an array is called an element.
2.  **Index**: Each location of an element in an array has a numerical index, which is used to identify the element. Indexing usually starts at 0.
3.  **Size/Length**: The total number of elements an array can hold.

---

## Visual Representation

Imagine an array of integers with size 5: `[10, 20, 30, 40, 50]`

```text
Index:   0    1    2    3    4
       +----+----+----+----+----+
Data:  | 10 | 20 | 30 | 40 | 50 |
       +----+----+----+----+----+
Address: 200  204  208  212  216  (assuming 4 bytes per int)
```

---

## Types of Arrays

### 1. Static Array
The size is fixed at compile time. You cannot change the size later.
*   *Example*: `int arr[5];` in C++.

### 2. Dynamic Array
The size can change during runtime. If it gets full, it automatically resizes itself (usually by doubling its size).
*   *Example*: `std::vector` in C++, `list` in Python, `ArrayList` in Java.

---

## Common Operations

### 1. Access (Get/Set)
You can access any element instantly if you know its index.
*   `arr[2]` gives `30`.

### 2. Traversal
Visiting every element in the array one by one.

### 3. Insertion
*   **At the end**: Fast (O(1)) for dynamic arrays (amortized).
*   **In the middle/beginning**: Slow (O(n)) because you have to shift all subsequent elements to make space.

### 4. Deletion
*   **At the end**: Fast (O(1)).
*   **In the middle/beginning**: Slow (O(n)) because you have to shift elements to fill the gap.

---

## Time Complexity

| Operation | Complexity | Explanation |
| :--- | :--- | :--- |
| **Access** | O(1) | Instant access via index math. |
| **Search** | O(n) | Linear search (checking one by one). O(log n) if sorted (Binary Search). |
| **Insertion** | O(n) | Worst case (inserting at start). |
| **Deletion** | O(n) | Worst case (deleting from start). |

## Advantages and Disadvantages

### Advantages
*   **Fast Access**: Reading or writing an element at a specific index is very fast (O(1)).
*   **Memory Efficiency**: Arrays have less overhead compared to linked lists (no pointers stored).
*   **Cache Friendliness**: Because memory is contiguous, iterating over an array is very fast due to CPU caching.

### Disadvantages
*   **Fixed Size**: Static arrays cannot grow.
*   **Costly Insert/Delete**: Adding or removing elements in the middle requires shifting data.

## Practical Use Cases

*   **Lookup Tables**: Fast access to data using indices.
*   **Matrices**: 2D arrays used in image processing and math.
*   **Implementing other structures**: Heaps, Hash Tables, Vectors, and Strings are often built on top of arrays.

---

## Code Example (Python)

In Python, the built-in `list` acts as a dynamic array.

```python
# Creating an array (list)
arr = [10, 20, 30, 40]

# Accessing elements (O(1))
print(arr[0])  # Output: 10
print(arr[2])  # Output: 30

# Insertion (O(n) in worst case, O(1) at end)
arr.append(50)      # Add to end
arr.insert(1, 15)   # Insert at index 1 (shifts 20, 30, 40, 50)

print(arr) 
# Output: [10, 15, 20, 30, 40, 50]

# Deletion (O(n))
arr.pop(0)          # Remove element at index 0 (shifts everything else)
print(arr)
# Output: [15, 20, 30, 40, 50]

# Traversal (O(n))
for num in arr:
    print(num, end=" ")
```

## Summary
Use an **Array** when you need fast access to elements by index and the number of elements is known or doesn't change often. Avoid it if you need frequent insertions and deletions in the middle of the collection.