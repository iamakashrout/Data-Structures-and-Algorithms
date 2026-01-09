# Matrix (2D Array) Data Structure

## What is a Matrix?

A **Matrix** (or 2D Array) is a collection of elements arranged in a grid of **rows** and **columns**. It is essentially an array of arrays.

If you think of a 1D array as a single line of boxes, a 2D array is a table or a spreadsheet.

### Key Concepts

1.  **Dimension**: Usually denoted as `R x C` (Rows by Columns).
2.  **Element Access**: Accessed using two indices: `matrix[row_index][column_index]`.
3.  **Cell**: An individual location in the matrix.

---

## Visual Representation

A 3x4 Matrix (3 Rows, 4 Columns):

```text
       Col 0   Col 1   Col 2   Col 3
Row 0 [  1   |   2   |   3   |   4  ]
Row 1 [  5   |   6   |   7   |   8  ]
Row 2 [  9   |  10   |  11   |  12  ]
```

*   Element at `[1][2]` is **7**.
*   Element at `[0][0]` is **1**.

---

## Memory Representation

Even though we visualize matrices as grids, computer memory is linear (1D). There are two ways to store a 2D grid in linear memory:

### 1. Row-Major Order (C, C++, Python, Java)
Elements are stored row by row.
`[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]`

### 2. Column-Major Order (Fortran, MATLAB)
Elements are stored column by column.
`[1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12]`

---

## Common Operations

### 1. Traversal
Visiting every cell. Usually requires nested loops (one for rows, one for columns).

### 2. Transpose
Flipping the matrix over its diagonal. Row `i` becomes Column `i`.
*   Element at `[r][c]` moves to `[c][r]`.

### 3. Rotation
Rotating the matrix 90 degrees clockwise or counter-clockwise.

### 4. Search
*   **Linear Search**: O(R * C).
*   **Sorted Matrix Search**: If rows and columns are sorted, you can search in O(R + C).

---

## Time Complexity

| Operation | Complexity | Explanation |
| :--- | :--- | :--- |
| **Access** | O(1) | `matrix[i][j]` is instant. |
| **Traversal** | O(R * C) | Must visit every element. |
| **Insertion/Deletion** | O(R * C) | Shifting elements in a dense grid is expensive. |

## Advantages and Disadvantages

### Advantages
*   **Structured Data**: Perfect for representing grids, tables, and mathematical matrices.
*   **Fast Access**: Like arrays, accessing any specific cell is O(1).

### Disadvantages
*   **Fixed Size**: In static implementations, dimensions are fixed.
*   **Contiguous Memory**: Large matrices require large blocks of contiguous memory (in row-major languages), which might fail allocation.

## Practical Use Cases

*   **Image Processing**: Images are stored as 2D matrices of pixels (or 3D for RGB).
*   **Game Boards**: Chess, Tic-Tac-Toe, Sudoku grids.
*   **Graphs**: Adjacency Matrices to represent connections between nodes.
*   **Dynamic Programming**: DP tables are often 2D matrices.
*   **Mathematics**: Solving systems of linear equations.

---

## Code Example (Python)

```python
# Creating a 3x3 Matrix
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

# Accessing elements
print(matrix[0][0]) # Output: 1
print(matrix[1][2]) # Output: 6

# Traversal
print("Traversal:")
for r in range(len(matrix)):
    for c in range(len(matrix[0])):
        print(matrix[r][c], end=" ")
    print()

# Transpose (Swap rows and cols)
# Result: [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
transposed = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
print("Transposed:", transposed)
```

## Summary
Use a **Matrix** when your data naturally forms a grid or table, or when you are dealing with coordinate systems (x, y).