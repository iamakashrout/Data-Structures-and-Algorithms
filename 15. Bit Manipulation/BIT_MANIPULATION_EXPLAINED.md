# Bit Manipulation Explained

## What is Bit Manipulation?

Computers don't understand decimal numbers (like 10, 25, 99) directly. They only understand **Binary**: 0s and 1s.
**Bit Manipulation** is the act of directly manipulating these bits to perform operations.

Why do we care?
1.  **Speed**: Bitwise operations are incredibly fast because they happen directly at the CPU level.
2.  **Memory**: You can store a lot of information (like 32 boolean flags) in a single integer.

---

## The Bitwise Operators

Imagine `A = 5` (Binary: `0101`) and `B = 3` (Binary: `0011`).

### 1. AND (`&`)
Returns 1 only if **both** bits are 1.
*   `5 & 3` -> `0101 & 0011` = `0001` (1)
*   *Use*: Checking if a specific bit is set (Masking).

### 2. OR (`|`)
Returns 1 if **at least one** bit is 1.
*   `5 | 3` -> `0101 | 0011` = `0111` (7)
*   *Use*: Setting a specific bit to 1.

### 3. XOR (`^`)
Returns 1 if bits are **different**. (The "Odd One Out" detector).
*   `5 ^ 3` -> `0101 ^ 0011` = `0110` (6)
*   *Property*: `x ^ x = 0` and `x ^ 0 = x`.
*   *Use*: Toggling bits, finding unique numbers.

### 4. NOT (`~`)
Flips all bits (0 becomes 1, 1 becomes 0).
*   `~5` -> `~0101` = `1010` (In signed integers, this is -6 due to Two's Complement).

### 5. Left Shift (`<<`)
Shifts bits to the left, filling with 0. Equivalent to **multiplying by 2**.
*   `5 << 1` -> `0101` becomes `1010` (10).

### 6. Right Shift (`>>`)
Shifts bits to the right. Equivalent to **dividing by 2** (integer division).
*   `5 >> 1` -> `0101` becomes `0010` (2).

---

## The "Magic" Tricks

These are the patterns you need for solving problems.

### 1. Check if a number is Odd or Even
Instead of `n % 2`, use `n & 1`.
*   If `n & 1 == 0` -> **Even** (Last bit is 0).
*   If `n & 1 == 1` -> **Odd** (Last bit is 1).

### 2. Check if the i-th bit is Set
Shift 1 to the left by `i` positions (`1 << i`) to create a mask, then AND it.
*   `if (n & (1 << i)) != 0`: The bit is set.

### 3. Set the i-th bit (Turn to 1)
Use OR (`|`).
*   `n = n | (1 << i)`

### 4. Clear the i-th bit (Turn to 0)
Use AND with NOT.
*   `n = n & ~(1 << i)`

### 5. Toggle the i-th bit (Flip it)
Use XOR (`^`).
*   `n = n ^ (1 << i)`

### 6. Check if a number is a Power of 2
Powers of 2 have exactly one bit set (1, 2, 4, 8 -> 001, 010, 100...).
*   `if (n > 0) and (n & (n - 1) == 0)`: It is a power of 2.
*   *Why?* `n-1` flips all bits after the rightmost 1. If `n` was a power of 2, the result is 0.

### 7. Clear the lowest set bit
*   `n = n & (n - 1)`
*   *Use*: Counting the number of set bits (Brian Kernighan’s Algorithm).

---

## Practical Applications

1.  **Permissions**: Linux file permissions (rwx = 4+2+1 = 7) use bits.
2.  **Compression**: Huffman coding uses variable-length bit sequences.
3.  **Cryptography**: XOR is fundamental in encryption algorithms.
4.  **Graphics**: Colors are often packed into integers (RGB = 8 bits each).
5.  **Competitive Programming**: Solving problems like "Find the single number in an array where every other number appears twice" (XOR all elements).

---

## Code Example (Python)

```python
def count_set_bits(n):
    count = 0
    while n > 0:
        n = n & (n - 1) # Removes the last set bit
        count += 1
    return count

def find_unique(arr):
    unique = 0
    for num in arr:
        unique ^= num
    return unique

# Usage
print("Set bits in 5 (101):", count_set_bits(5)) # Output: 2
print("Unique number in [2, 3, 2]:", find_unique([2, 3, 2])) # Output: 3
```

## Summary
*   **& (AND)**: Extract bits.
*   **| (OR)**: Set bits.
*   **^ (XOR)**: Toggle/Find difference.
*   **<< / >>**: Multiply/Divide by 2.
*   **n & (n-1)**: The most useful trick for bit manipulation problems.