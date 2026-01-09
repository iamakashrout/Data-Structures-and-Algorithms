# String Data Structure

## What is a String?

A **String** is essentially a sequence of characters used to represent text. In computer memory, a string is often implemented as an **Array of Characters**.

For example, the word "Hello" is stored as a sequence of 5 characters: 'H', 'e', 'l', 'l', 'o'.

### Key Concepts

1.  **Character**: The basic building block (e.g., 'a', '7', '$').
2.  **Index**: Just like arrays, characters in a string can be accessed by their position (index), usually starting at 0.
3.  **Encoding**: How characters are mapped to binary numbers (e.g., ASCII, UTF-8).

---

## Visual Representation

String: `"CODE"`

```text
Index:   0    1    2    3
       +----+----+----+----+
Char:  | C  | O  | D  | E  |
       +----+----+----+----+
```

## Mutability: A Crucial Distinction

One of the most important things to know about strings in different programming languages is whether they are **Mutable** or **Immutable**.

### 1. Immutable Strings (Python, Java, JavaScript, C#)
*   **Definition**: Once created, the string cannot be changed.
*   **Implication**: If you want to change a character (e.g., change "Cat" to "Bat"), the computer actually creates a **whole new string** "Bat" in memory and points your variable to it. The old "Cat" is discarded.
*   **Why?**: Thread safety, security, and memory optimization (String Pool).

### 2. Mutable Strings (C++, C, Ruby)
*   **Definition**: You can change individual characters in place without creating a new string.
*   **Implication**: `str[0] = 'B'` directly modifies the memory.

---

## Common Operations & Complexity

| Operation | Complexity | Explanation |
| :--- | :--- | :--- |
| **Access** | O(1) | Get character at index `i`. |
| **Search** | O(n) | Find if a character or substring exists. |
| **Concatenation** | O(n + m) | Joining two strings (length n and m). In immutable languages, this copies both strings. |
| **Substring** | O(n) | Extracting a part of the string (copying data). |

---

## Common String Algorithms

Strings are a favorite topic in interviews. Here are common patterns:

1.  **Two Pointers**: Used for reversing a string or checking for palindromes (reads the same forwards and backwards).
2.  **Sliding Window**: Used for finding the longest substring without repeating characters.
3.  **Hashing**: Used for checking anagrams (words with same characters like "listen" and "silent").

---

## Code Example (Python)

Since Python strings are immutable, notice how operations work.

```python
# 1. Creation
s = "Hello World"

# 2. Access (O(1))
print(s[0])       # Output: H
print(s[-1])      # Output: d (Last char)

# 3. Slicing / Substring (O(k))
print(s[0:5])     # Output: Hello

# 4. Immutability
# s[0] = 'Y'      # This would raise a TypeError!

# To "modify", we create a new string:
new_s = "Y" + s[1:] 
print(new_s)      # Output: Yello World

# 5. Common Methods
print(s.lower())  # hello world
print(s.split())  # ['Hello', 'World'] (Splits into list of strings)

# 6. Palindrome Check (Pythonic way)
word = "racecar"
is_palindrome = word == word[::-1] # Reverses string and compares
print(is_palindrome) # True
```

## Summary

*   Treat Strings like **Arrays of Characters**.
*   Be aware of **Immutability** in your language; repeated concatenation in a loop can be very slow (O(n²)) in immutable languages (use a StringBuilder or list join instead).
*   Master the **Two Pointer** technique for string problems.