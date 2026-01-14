# Dynamic Programming (DP) Explained

## What is Dynamic Programming?

**Dynamic Programming (DP)** is a method for solving complex problems by breaking them down into simpler subproblems. It is essentially **Recursion + Optimization**.

The core idea is simple: **Don't solve the same problem twice.** If you've already solved a subproblem, store the result and reuse it later instead of re-calculating it.

### The "1+1+1" Analogy

*   **Question**: What is `1 + 1 + 1 + 1 + 1`?
*   **You**: It's 5.
*   **Question**: (Adds another `1` to the left) What is `1 + 1 + 1 + 1 + 1 + 1`?
*   **You**: It's 6.
*   **Question**: How did you know that so fast? Did you recount?
*   **You**: No, I just added 1 to the previous answer (5).

**That is Dynamic Programming.** You "remembered" the answer to the smaller problem (5) to solve the larger problem (6).

---

## When to Use DP?

DP is useful when a problem has two key properties:

1.  **Overlapping Subproblems**: The problem can be broken down into smaller pieces, and these pieces are reused multiple times. (e.g., Fibonacci: `fib(5)` needs `fib(4)` and `fib(3)`; `fib(4)` also needs `fib(3)`).
2.  **Optimal Substructure**: The optimal solution to the big problem can be constructed from the optimal solutions of its subproblems. (e.g., Shortest path from A to C is Shortest path A->B + Shortest path B->C).

---

## The Approaches

Let's use the **Fibonacci Sequence** (`0, 1, 1, 2, 3, 5, 8...`) to explain the evolution from recursion to optimized DP.
Goal: Find `Fib(n)`.

### 1. Naive Recursion (The "Forgetful" Way)
You simply call the function recursively.

```text
       fib(5)
      /      \
  fib(4)     fib(3)
  /    \     /    \
fib(3) fib(2) fib(2) fib(1)
```
*   **Problem**: Notice `fib(3)` is calculated twice, and `fib(2)` is calculated three times!
*   **Complexity**: O(2^n) - Exponential (Very Slow).

### 2. Memoization (Top-Down DP)
This is **Recursion + Caching**.
Before calculating `fib(n)`, check a "memo" (dictionary or array) to see if you've already solved it. If yes, return the saved value. If no, calculate it and save it.

*   **Analogy**: Writing down the answer to a math problem on a notepad so you don't have to solve it again.
*   **Complexity**: O(n) - Linear (Fast).
*   **Space**: O(n) for the recursion stack + O(n) for the map.

### 3. Tabulation (Bottom-Up DP)
This removes recursion entirely. We start from the smallest subproblem (`fib(0)` and `fib(1)`) and iteratively build up the table to reach `fib(n)`.

*   **Visual**: `[0, 1, _, _, _, _]` -> `[0, 1, 1, 2, 3, 5]`
*   **Complexity**: O(n).
*   **Space**: O(n) for the table.

### 4. Space Optimization
In Fibonacci, to calculate the *current* number, you only need the *previous two* numbers. You don't need the whole history.

*   **Strategy**: Keep only two variables, `prev` and `curr`.
*   **Complexity**: O(n).
*   **Space**: O(1) - Constant space!

---

## Code Example (Python)

Here is how the code evolves for the Fibonacci sequence.

```python
# 1. Naive Recursion
def fib_recursive(n):
    if n <= 1: return n
    return fib_recursive(n-1) + fib_recursive(n-2)

# 2. Memoization (Top-Down)
def fib_memo(n, memo={}):
    if n in memo: return memo[n]
    if n <= 1: return n
    
    memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo)
    return memo[n]

# 3. Tabulation (Bottom-Up)
def fib_tab(n):
    if n <= 1: return n
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

# 4. Space Optimization
def fib_optimized(n):
    if n <= 1: return n
    prev2, prev1 = 0, 1
    for _ in range(2, n + 1):
        curr = prev1 + prev2
        prev2 = prev1
        prev1 = curr
    return prev1
```

---

## Comparison

| Approach | Direction | Recursion? | Speed | Space |
| :--- | :--- | :--- | :--- | :--- |
| **Naive** | Top-Down | Yes | Slow (Exp) | High (Stack) |
| **Memoization** | Top-Down | Yes | Fast (Linear) | Medium (Stack + Map) |
| **Tabulation** | Bottom-Up | No | Fast (Linear) | Medium (Table) |
| **Space Opt** | Bottom-Up | No | Fast (Linear) | Low (Variables) |

---

## Advantages and Disadvantages

### Advantages
*   **Performance**: Drastically reduces time complexity from exponential (O(2^n)) to polynomial (O(n^2) or O(n)).
*   **Correctness**: Guarantees finding the optimal solution (unlike Greedy, which only guesses).

### Disadvantages
*   **Memory Usage**: Often requires a table (array/matrix) of size O(n) or O(n*m) to store intermediate results.
*   **Complexity**: It can be hard to define the "state" and the "recurrence relation" (the formula connecting subproblems).

---

## Practical Applications

1.  **Shortest Path Algorithms**: Bellman-Ford and Floyd-Warshall algorithms use DP to find shortest paths in graphs (like Google Maps).
2.  **Text Comparison**:
    *   **Longest Common Subsequence (LCS)**: Used in `git diff` to see changes between files.
    *   **Edit Distance (Levenshtein)**: Used in Spell Checkers and Autocorrect.
3.  **0/1 Knapsack Problem**: Selecting the most valuable items to fit in a backpack with a weight limit.
4.  **Bioinformatics**: DNA sequence alignment.
5.  **Finance**: Algorithmic trading strategies often use DP to maximize profit over time.

## How to Solve a DP Problem?

1.  **Define the State**: What variables describe the problem at a specific step? (e.g., `dp[i]` = max profit at day `i`).
2.  **Find the Recurrence Relation**: How does the current state depend on previous states? (e.g., `dp[i] = dp[i-1] + dp[i-2]`).
3.  **Identify Base Cases**: What are the simplest cases? (e.g., `dp[0] = 0`).
4.  **Choose Approach**:
    *   Use **Memoization** if you want to write it recursively and the problem space is sparse.
    *   Use **Tabulation** if you want to save stack space and iterate cleanly.

## Summary

**Dynamic Programming** is just a fancy name for **"Smart Recursion"**.
*   If you see a problem asking for a **Maximum**, **Minimum**, **Longest**, or **Total ways**, and it has overlapping subproblems, think DP!
*   **Memoization**: Remember what you calculated.
*   **Tabulation**: Build the solution from the ground up.