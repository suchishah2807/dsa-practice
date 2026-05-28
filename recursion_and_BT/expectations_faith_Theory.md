# Recursion — The Mental Model

---

## The Core Idea

Recursion is not magic. It's just a function calling itself with a smaller version of the problem.  
But to *think* in recursion, you need a framework. Here it is:

### The 3-Step Framework

```
1. Set the expectation   → what output do I want?
2. Have faith            → assume it works for smaller cases (don't trace the stack!)
3. Make the connection   → use the smaller result to build the bigger one
```

This is exactly like **Mathematical Induction**:
- Assume true for `k`
- Prove for `k+1`

Same energy. Same logic.

---

## Example 1 — Print Increasing (1 to n)

**Expected output for n=5:**
```
1
2
3
4
5
```

**Thought process:**
- I want `1, 2, 3, 4, 5`
- *Faith:* assume `printIncreasing(4)` prints `1, 2, 3, 4` — I don't know how, I just trust it
- *Connection:* call `printIncreasing(n-1)` first, then print `n`

```cpp
void printIncreasing(int n) {
    if (n == 0) return;       // base case
    printIncreasing(n - 1);   // faith — prints 1 to n-1
    cout << n << endl;        // then print n
}
```

---

## Example 2 — Print Decreasing (n to 1)

**Expected output for n=5:**
```
5
4
3
2
1
```

**Thought process:**
- I want `5, 4, 3, 2, 1`
- *Faith:* assume `printDecreasing(4)` prints `4, 3, 2, 1`
- *Connection:* print `n` first, then call `printDecreasing(n-1)`

```cpp
void printDecreasing(int n) {
    if (n == 0) return;       // base case
    cout << n << endl;        // print n first
    printDecreasing(n - 1);   // faith — prints n-1 to 1
}
```

---

## Understanding the Call Stack

This is where it clicks. Let's trace `pd(4)` **step by step:**

```
Step 1 — pd(4) is called, prints 4, then calls pd(3)
|_______|
| pd(4) |  ← printed 4, now waiting for pd(3)...
|_______|

Step 2 — pd(3) is called, prints 3, then calls pd(2)
|_______|
| pd(3) |  ← printed 3, now waiting for pd(2)...
| pd(4) |  ← still waiting...
|_______|

Step 3 — pd(2) is called, prints 2, then calls pd(1)
|_______|
| pd(2) |  ← printed 2, now waiting for pd(1)...
| pd(3) |  ← still waiting...
| pd(4) |  ← still waiting...
|_______|

Step 4 — pd(1) is called, prints 1, then calls pd(0)
|_______|
| pd(1) |  ← printed 1, now waiting for pd(0)...
| pd(2) |  ← still waiting...
| pd(3) |  ← still waiting...
| pd(4) |  ← still waiting...
|_______|

Step 5 — pd(0) hits base case, returns nothing, stack unwinds
|_______|
| pd(1) |  ← pd(0) returned, now pd(1) prints "wiping off: 1" and exits
| pd(2) |
| pd(3) |
| pd(4) |
|_______|

Step 6 — pd(1) done, pd(2) prints "wiping off: 2" and exits
|_______|
| pd(2) |  ← prints "wiping off: 2" and exits
| pd(3) |
| pd(4) |
|_______|

Step 7 — pd(2) done, pd(3) prints "wiping off: 3" and exits
|_______|
| pd(3) |  ← prints "wiping off: 3" and exits
| pd(4) |
|_______|

Step 8 — pd(3) done, pd(4) prints "wiping off: 4" and exits
|_______|
| pd(4) |  ← prints "wiping off: 4" and exits
|_______|

Step 9 — stack is empty, program ends
|_______|
|       |
|_______|
```

Each call prints its number and then **waits** for the call below it to finish.  
When `pd(0)` hits the base case — it returns nothing.  
Then each frame **wipes off** the stack one by one.

```cpp
void pd(int n) {
    if (n == 0) return;
    cout << n << endl;
    pd(n - 1);
    cout << "wiping off the stack: " << n << endl;
}
```

**Output of `pd(5)`:**
```
5
4
3
2
1
wiping off the stack: 1
wiping off the stack: 2
wiping off the stack: 3
wiping off the stack: 4
wiping off the stack: 5
```

The lines *after* the recursive call run **on the way back up** — after all smaller calls have finished.  
This is the key insight behind postorder traversal, merge sort, and a hundred other algorithms.

---

## The Golden Rule

> **Never trace the full recursion tree in your head while coding.**  
> Set the expectation. Have faith. Make the connection. Write the base case. Done.

The stack takes care of itself.

---

*Notes by me — based on my own understanding while learning DSA.*