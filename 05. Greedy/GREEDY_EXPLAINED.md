# Greedy Algorithms Explained

## What is a Greedy Algorithm?

A **Greedy Algorithm** is an approach to solving problems by making the **locally optimal choice** at each stage with the hope of finding a **global optimum**.

In simple terms: At every step, you choose what looks best *right now*, without worrying about the future consequences. You never go back to change your mind.

---

## Analogy: The Cashier's Problem

Imagine you are a cashier and you need to give a customer **$0.67** in change using the fewest number of coins possible.

**The Greedy Strategy:**
1.  Start with the largest coin value possible.
2.  Can I use a Quarter ($0.25)? Yes. (Remaining: $0.42)
3.  Can I use another Quarter? Yes. (Remaining: $0.17)
4.  Can I use another Quarter? No ($0.25 > $0.17). Try the next largest.
5.  Can I use a Dime ($0.10)? Yes. (Remaining: $0.07)
6.  Can I use a Nickel ($0.05)? Yes. (Remaining: $0.02)
7.  Can I use a Penny ($0.01)? Yes. (Remaining: $0.01)
8.  Can I use a Penny? Yes. (Remaining: $0.00)

You made the "greedy" choice to always take the biggest chunk out of the debt as possible.

---

## Key Properties

For a Greedy algorithm to work correctly, the problem usually needs two properties:

1.  **Greedy Choice Property**: You can choose the best immediate option and still reach the overall best solution.
2.  **Optimal Substructure**: The optimal solution to the problem contains optimal solutions to the sub-problems.

---

## When Greedy Fails

Greedy doesn't always work!

**Example**:
*   **Coins available**: `[1, 3, 4]`
*   **Target**: `6`

**Greedy Approach**:
1.  Pick largest: `4`. Remaining: `2`.
2.  Pick largest <= 2: `1`. Remaining: `1`.
3.  Pick largest <= 1: `1`. Remaining: `0`.
*   **Result**: `4, 1, 1` (3 coins).

**Optimal Approach**:
*   Pick `3`, then `3`.
*   **Result**: `3, 3` (2 coins).

*In this case, being greedy was not the best long-term strategy. You would need Dynamic Programming here.*

---

## Advantages and Disadvantages

### Advantages
*   **Speed**: Usually very fast because they make a single pass through the data.
*   **Simplicity**: Often easier to implement than Dynamic Programming or Backtracking.

### Disadvantages
*   **Correctness**: Hard to prove that a greedy strategy will actually produce the global optimum for every case.
*   **Short-sighted**: It cannot "look ahead" to see if a current bad choice might lead to a better outcome later.

## Practical Use Cases

1.  **Activity Selection Problem**: Scheduling the maximum number of activities that don't overlap.
2.  **Huffman Coding**: Used for data compression (ZIP files).
3.  **Dijkstra's Algorithm**: Finding the shortest path in a graph (Greedy because it always picks the closest unvisited node).
4.  **Prim's and Kruskal's Algorithms**: Finding the Minimum Spanning Tree (MST) in a graph.

---

## Code Example (Python)

Here is a simple implementation of the Coin Change problem (assuming standard currency where Greedy works).

```python
def min_coins(coins, amount):
    # Sort coins in descending order to pick largest first
    coins.sort(reverse=True)
    count = 0
    change = []

    for coin in coins:
        while amount >= coin:
            amount -= coin
            change.append(coin)
            count += 1
    return change

# Usage
print(min_coins([1, 5, 10, 25], 67))
# Output: [25, 25, 10, 5, 1, 1]
```

## Summary
Use **Greedy Algorithms** for optimization problems where local best choices lead to a global best result. They are fast and efficient but require careful verification to ensure they actually solve the problem correctly.