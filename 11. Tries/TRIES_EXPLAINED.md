# Trie (Prefix Tree) Data Structure

## What is a Trie?

A **Trie** (pronounced "try") or **Prefix Tree** is a tree-based data structure used to efficiently store and retrieve keys in a dataset of strings. Unlike a binary search tree, nodes in a Trie do not store the key associated with that node. Instead, a node's position in the tree defines the key with which it is associated.

It is particularly useful for tasks involving **prefixes** of strings.

### Key Concepts

1.  **Root**: The top node, usually empty (doesn't hold a character).
2.  **Nodes**: Each node represents a character of a string.
3.  **Edges**: Links connecting nodes.
4.  **End of Word Marker**: A flag (boolean) in a node indicating that the path from the root to this node forms a complete word.
5.  **Children**: Usually an array or hash map pointing to the next characters.

---

## Visual Representation

Imagine storing the words: "cat", "car", "dog".

```text
        [ Root ]
        /      \
      [c]      [d]
       |        |
      [a]      [o]
      / \       |
    [t] [r]    [g]*
     *   *
```
*   `*` marks the end of a word.
*   "cat" and "car" share the prefix "ca".

---

## Common Operations

### 1. Insertion
To insert a word (e.g., "apple"):
1.  Start at the Root.
2.  Check if the first character ('a') exists as a child. If not, create a new node.
3.  Move to that node and repeat for the next character ('p').
4.  After the last character, mark the current node as `is_end_of_word = True`.

### 2. Search
To find a word (e.g., "app"):
1.  Start at the Root.
2.  Traverse down character by character.
3.  If you get stuck (child doesn't exist), the word is not there.
4.  If you reach the end of the string, check if the current node is marked as `is_end_of_word`. If yes, found!

### 3. Prefix Search (StartsWith)
Similar to search, but you don't need the `is_end_of_word` flag to be true. You just need to verify that the path exists.

---

## Time Complexity

| Operation | Complexity | Explanation |
| :--- | :--- | :--- |
| **Insertion** | O(L) | L is the length of the word. |
| **Search** | O(L) | You only traverse the length of the word. |
| **Prefix Search** | O(L) | Same as search. |

*Note: The complexity depends on the word length, not the number of words in the database (N).*

## Advantages and Disadvantages

### Advantages
*   **Prefix Matching**: Extremely efficient for finding words with a common prefix (autocomplete).
*   **Predictable Speed**: Lookup time depends on word length, not the size of the dataset.
*   **Sorting**: Can provide alphabetical ordering of data.

### Disadvantages
*   **Memory Usage**: Can be memory-intensive because each node needs to store pointers to children (often 26 pointers for the English alphabet), even if many are null.
*   **Complexity**: More complex to implement than a simple Hash Table.

## Practical Use Cases

*   **Autocomplete**: When you type in a search bar, Tries help suggest words starting with what you typed.
*   **Spell Checkers**: Quickly verify if a word exists in the dictionary.
*   **IP Routing**: Longest prefix matching for internet routers.
*   **T9 Text Prediction**: Old mobile phone predictive text.

---

## Code Example (Python)

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def starts_with(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

# Usage
trie = Trie()
trie.insert("apple")
print(trie.search("apple"))   # True
print(trie.search("app"))     # False
print(trie.starts_with("app")) # True
trie.insert("app")
print(trie.search("app"))     # True
```

## Summary
Use a **Trie** when you are working with strings and need efficient **prefix-based** operations like autocomplete or spell checking.