# Binary Search Algorithm

## What is Binary Search?

**Binary Search** is an efficient algorithm for finding an item from a **sorted** list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

It is much faster than **Linear Search** (checking every element one by one) but requires the data to be sorted beforehand.

### Key Concept: Divide and Conquer
Instead of guessing one by one, you guess the middle.
*   If the middle is what you are looking for, great!
*   If the middle is *higher* than your target, you know the target must be in the *lower* half.
*   If the middle is *lower* than your target, you know the target must be in the *higher* half.

---

## Visual Representation

Target: **7**
Array: `[1, 3, 5, 7, 9, 11, 13]`

**Step 1:**
Indices: 0  1  2  3  4   5   6
Values: [1, 3, 5, 7, 9, 11, 13]
Low: 0, High: 6
Mid: (0+6)//2 = 3
Value at Mid (index 3) is **7**.
**7 == 7**. Found!

---

## Algorithm Steps

1.  Set `Low` to 0 and `High` to `n - 1`.
2.  While `Low <= High`:
    *   Calculate `Mid = (Low + High) // 2`.
    *   If `Arr[Mid] == Target`, return `Mid`.
    *   If `Arr[Mid] < Target`, the target is in the right half. Set `Low = Mid + 1`.
    *   If `Arr[Mid] > Target`, the target is in the left half. Set `High = Mid - 1`.
3.  If the loop ends, the target is not in the array.

---

## Time Complexity

| Case | Complexity | Explanation |
| :--- | :--- | :--- |
| **Best Case** | O(1) | The target is exactly at the middle on the first try. |
| **Average Case** | O(log n) | Each step cuts the search space in half. |
| **Worst Case** | O(log n) | The target is at the ends or not present. |

*   **O(log n)** means if you have 1,000,000 items, it takes only about 20 steps to find an item (since 2^20 ≈ 1,000,000). Linear search would take 1,000,000 steps.

## Space Complexity
*   **Iterative**: O(1) - Uses a constant amount of extra space.
*   **Recursive**: O(log n) - Uses stack space for recursion.

---

## Advantages and Disadvantages

### Advantages
*   **Speed**: Extremely fast for large datasets compared to linear search.
*   **Efficiency**: Reduces the search space exponentially.

### Disadvantages
*   **Sorted Data Required**: The array **must** be sorted. Sorting an unsorted array takes O(n log n), which is slower than the search itself.
*   **Complex Memory**: Works best with contiguous memory (arrays) where random access (jumping to the middle) is O(1). Not efficient for Linked Lists.

## Practical Use Cases
*   **Dictionary Search**: Looking up a word in a physical dictionary (you open the middle, check if the word is before or after).
*   **Debugging**: "Git Bisect" uses binary search to find which commit introduced a bug.
*   **Database Indexing**: Databases use tree structures (like B-Trees) which are based on binary search principles to find records quickly.
*   **Standard Libraries**: `std::binary_search` in C++, `bisect` in Python, `Arrays.binarySearch` in Java.

---

## Code Example (Python)

### Iterative Implementation (Recommended)
```python
def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = arr[mid]

        if guess == target:
            return mid
        if guess > target:
            high = mid - 1
        else:
            low = mid + 1
    
    return -1  # Target not found

# Usage
my_list = [1, 3, 5, 7, 9]
print(binary_search(my_list, 3))  # Output: 1
print(binary_search(my_list, -1)) # Output: -1
```

## Summary
Use **Binary Search** whenever you have a **sorted** dataset and need to perform frequent lookups. It is one of the most fundamental and efficient algorithms in computer science.