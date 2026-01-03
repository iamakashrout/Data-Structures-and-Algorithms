# Stacks and Queues Data Structures

## What is a Stack?

Imagine a stack of plates in a cafeteria. When you put a clean plate on the stack, you place it on the top. When you need a plate, you take the one from the top. The last plate you put on is the first one you take off.

A **Stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle.

### Key Concepts (Stack)
1.  **Top**: The end of the stack where elements are added and removed.
2.  **Push**: Adding an element to the top.
3.  **Pop**: Removing the element from the top.

---

## What is a Queue?

Imagine a line of people waiting to buy movie tickets. The first person to get in line is the first person to buy a ticket and leave. New people join at the back of the line.

A **Queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle.

### Key Concepts (Queue)
1.  **Front (Head)**: The end where elements are removed.
2.  **Rear (Tail)**: The end where elements are added.
3.  **Enqueue**: Adding an element to the rear.
4.  **Dequeue**: Removing an element from the front.

---

## Visual Representation

### Stack
```text
|   Data C   |  <-- Top (Push/Pop happens here)
|   Data B   |
|   Data A   |
+------------+
```

### Queue
```text
      Front (Dequeue)                         Rear (Enqueue)
         |                                         |
         v                                         v
[ Data A | Data B | Data C | Data D ]
```

---

## Stack vs. Queue

| Feature | Stack | Queue |
| :--- | :--- | :--- |
| **Principle** | LIFO (Last In, First Out) | FIFO (First In, First Out) |
| **Insertion** | At the Top (Push) | At the Rear (Enqueue) |
| **Deletion** | From the Top (Pop) | From the Front (Dequeue) |
| **Access** | Only the Top element is accessible | Only the Front/Rear are typically accessible |

## Advantages and Disadvantages

### Advantages
*   **Simplicity**: Both are simple to implement and understand.
*   **Efficiency**: Operations like push/pop and enqueue/dequeue are typically O(1) (constant time).
*   **Memory**: Efficient memory usage when implemented with linked lists or dynamic arrays.

### Disadvantages
*   **Limited Access**: You cannot access elements in the middle without removing the ones before them.
*   **Size Limits**: If implemented with a fixed-size array, they can overflow (Stack Overflow).

## Practical Use Cases

### Stack
*   **Undo/Redo mechanisms**: Text editors use stacks to track changes.
*   **Function Call Stack**: Programming languages use a stack to manage function calls and recursion.
*   **Expression Evaluation**: Checking for balanced parentheses `((a+b))` or evaluating math expressions.
*   **Browser History**: The "Back" button works like a stack.

### Queue
*   **Printer Spooling**: Documents are printed in the order they were sent.
*   **Task Scheduling**: Operating systems schedule tasks for the CPU in a queue.
*   **Data Buffering**: Streaming video or music uses queues to buffer data.
*   **Breadth-First Search (BFS)**: An algorithm used in graphs to find the shortest path.

## Why Learn Stacks and Queues?

1.  **Algorithm Fundamentals**: They are the building blocks for more complex algorithms like Graph traversals (DFS uses Stack, BFS uses Queue).
2.  **System Understanding**: Understanding stacks helps you understand how programs execute and how memory is managed during recursion.
3.  **Problem Solving**: Many coding interview problems are solved efficiently using these structures (e.g., "Valid Parentheses", "Sliding Window Maximum").

---

## Code Example (Python)

Here are simple implementations using Python lists.

### Stack Implementation
```python
class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        return None

    def is_empty(self):
        return len(self.items) == 0

# Usage
stack = Stack()
stack.push(1)
stack.push(2)
print(stack.pop()) # Output: 2
```

### Queue Implementation
```python
class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0) # Note: pop(0) is O(n) in Python lists, collections.deque is better
        return None

    def is_empty(self):
        return len(self.items) == 0

# Usage
queue = Queue()
queue.enqueue("A")
queue.enqueue("B")
print(queue.dequeue()) # Output: A
```

## Summary
*   Use a **Stack** when you need to reverse things or backtrack (LIFO).
*   Use a **Queue** when you need to process things in the order they arrived (FIFO).