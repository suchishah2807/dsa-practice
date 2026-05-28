# Stack & Queue

---

## stack

last in, first out. think of a pile of plates.  
you put a plate on top. you take a plate from the top. that's it.

```
push 1       push 2       push 3       pop
             
|   |        |   |        | 3 |        |   |
|   |   →    | 2 |   →    | 2 |   →    | 2 |
| 1 |        | 1 |        | 1 |        | 1 |
|___|        |___|        |___|        |___|

                                    returned 3
```

### operations

```
push(x)  → add x on top          O(1)
pop()    → remove top             O(1)
top()    → see top without remove O(1)
empty()  → is it empty?           O(1)
```

### in c++

```cpp
stack<int> st;
st.push(5);
st.top();    // 5
st.pop();    // removes 5
st.empty();  // true
```

### always check before top() or pop()

```cpp
if (!st.empty()) st.top();   // never call top on empty stack
if (!st.empty()) st.pop();   // never call pop on empty stack
```

calling top() or pop() on empty stack = runtime crash. always guard it.

---

## queue

first in, first out. think of a line at a ticket counter.  
first person to join is the first to leave.

```
enqueue 1    enqueue 2    enqueue 3    dequeue

front        front        front        front
  ↓            ↓            ↓            ↓
[ 1 ]  →    [ 1, 2 ]  →  [ 1, 2, 3 ] → [ 2, 3 ]
                                       
                                       returned 1
```

### operations

```
push(x)   → add to back           O(1)
pop()     → remove from front     O(1)
front()   → see front element     O(1)
back()    → see back element      O(1)
empty()   → is it empty?          O(1)
```

### in c++

```cpp
queue<int> q;
q.push(5);
q.push(10);
q.front();   // 5  (first in)
q.back();    // 10 (last in)
q.pop();     // removes 5
```

---

## how to think about stack problems

stack is useful when you need to:

```
1. remember something from the past and compare with current
2. find the nearest element (left or right) that is greater or smaller
3. undo the last operation
4. match pairs (brackets, parentheses)
5. process things in reverse order
```

the key property of stack — **the most recent thing you saw is always on top.**  
that's why it's perfect for "nearest previous" or "nearest next" problems.

---

## monotonic stack — the most important pattern

a stack where elements are always in increasing or decreasing order.  
when a new element breaks the order, you pop until order is restored.

### increasing monotonic stack (nearest greater element)

find the nearest greater element to the right for each element.

```
arr = [2, 1, 5, 3, 4]

i=0: push 2  → stack: [2]
i=1: push 1  → stack: [2, 1]      (1 < 2, order maintained)
i=2: see 5
     5 > top(1) → pop 1, nearest greater of 1 is 5
     5 > top(2) → pop 2, nearest greater of 2 is 5
     push 5  → stack: [5]
i=3: see 3
     3 < top(5) → just push
     stack: [5, 3]
i=4: see 4
     4 > top(3) → pop 3, nearest greater of 3 is 4
     4 < top(5) → stop
     push 4  → stack: [5, 4]

remaining in stack → no greater element to right
result: [5, 5, -1, 4, -1]
```

step by step visual for i=2 (when 5 comes in):

```
before:          after pop 1:     after pop 2:     after push 5:
| 1 |            |   |            |   |             | 5 |
| 2 |    →       | 2 |    →       |   |    →        |   |
|___|            |___|            |___|             |___|

  5 > 1              5 > 2            stack empty
  pop 1              pop 2            push 5
  ans[1] = 5         ans[0] = 5
```

### decreasing monotonic stack (nearest smaller element)

same idea but flip the comparison. pop when new element is smaller than top.

```
arr = [3, 1, 2]

i=0: push 3  → stack: [3]
i=1: see 1
     1 < top(3) → pop 3, nearest smaller of 3 is 1
     push 1  → stack: [1]
i=2: see 2
     2 > top(1) → just push
     stack: [1, 2]
```

### the rule

```
want nearest GREATER → pop when current > top  (increasing stack)
want nearest SMALLER → pop when current < top  (decreasing stack)
scanning LEFT  → traverse left to right, answer is what caused the pop
scanning RIGHT → traverse right to left, same logic
```

---

## bracket matching — classic stack use

```
s = "({[]})"

see (  → push (    stack: [ ( ]
see {  → push {    stack: [ (, { ]
see [  → push [    stack: [ (, {, [ ]
see ]  → top is [, matches → pop   stack: [ (, { ]
see }  → top is {, matches → pop   stack: [ ( ]
see )  → top is (, matches → pop   stack: [ ]

stack empty at end → valid string ✓
```

```
s = "({)"

see (  → push     stack: [ ( ]
see {  → push     stack: [ (, { ]
see )  → top is { → doesn't match ) → invalid ✗
```

pattern: open bracket → push. close bracket → check if top matches, if yes pop, if no invalid.

---

## how to think about queue problems

queue is useful when you need to:

```
1. process things in the order they came (BFS, level order)
2. maintain a sliding window of recent elements
3. simulate real-world queues (printers, task scheduling)
```

the key property of queue — **order is preserved.**  
whatever came first gets processed first.

---

## BFS with queue — the most important queue pattern

level order traversal. process all nodes at level 1, then level 2, then level 3.

```
tree:
        1
       / \
      2   3
     / \
    4   5

queue at each step:

start:   [ 1 ]
pop 1, push 2,3:   [ 2, 3 ]          → level 1 done: [1]
pop 2, push 4,5:   [ 3, 4, 5 ]
pop 3, no children: [ 4, 5 ]         → level 2 done: [2, 3]
pop 4, no children: [ 5 ]
pop 5, no children: [ ]              → level 3 done: [4, 5]
```

```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int size = q.size();              // how many nodes at this level
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

the `size` snapshot before the loop is what separates levels from each other.

---

## monotonic deque — sliding window maximum

deque = double ended queue. can push and pop from both front and back.

used when you need max or min of a sliding window of size k.

```
arr = [1, 3, -1, -3, 5, 3]   k = 3
find max in every window

deque stores indices. front always has index of max element of current window.

i=0: deque empty, push 0          deque: [0]        (values: [1])
i=1: arr[1]=3 > arr[0]=1
     pop 0 from back (1 is useless, 3 is bigger and will outlast it)
     push 1                        deque: [1]        (values: [3])
i=2: arr[2]=-1 < arr[1]=3
     just push 2                   deque: [1, 2]     (values: [3,-1])
     window complete (i=2, k=3) → max = arr[front] = arr[1] = 3 ✓

i=3: arr[3]=-3 < arr[2]=-1
     just push 3                   deque: [1, 2, 3]  (values: [3,-1,-3])
     front=1, but i-k+1=1, index 1 still in window
     max = arr[1] = 3 ✓

i=4: arr[4]=5 > everything
     pop 3, pop 2, pop 1 from back
     push 4                        deque: [4]        (values: [5])
     max = arr[4] = 5 ✓

i=5: arr[5]=3 < arr[4]=5
     push 5                        deque: [4, 5]     (values: [5,3])
     front=4, i-k+1=3, index 4 still in window
     max = arr[4] = 5 ✓
```

two rules for monotonic deque:
```
1. pop from BACK  when new element >= back element (back is useless)
2. pop from FRONT when front index is outside the window (expired)
```

---

## how to identify it's a stack question

```
"valid parentheses / matching brackets"     → stack, push open, pop on close
"next greater element"                      → monotonic stack
"next smaller element"                      → monotonic stack
"previous greater / smaller"                → monotonic stack, traverse other direction
"largest rectangle in histogram"            → monotonic stack
"daily temperatures"                        → monotonic stack
"evaluate expression"                       → stack (operands + operators)
"undo / backtrack"                          → stack
"decode string"                             → stack
"simplify path"                             → stack
```

if the question involves **looking back at the most recent thing** → stack.

---

## how to identify it's a queue question

```
"level order traversal"                     → queue + BFS
"rotting oranges / flood fill"              → queue + BFS
"maximum in sliding window"                 → monotonic deque
"task scheduler"                            → queue + priority queue
"first negative in window"                  → queue
"generate binary numbers"                   → queue
```

if the question involves **processing in arrival order** or **BFS** → queue.

---

## the thinking process for any stack/queue question

```
step 1: what do i need to remember as i scan?
         → recent elements? → stack
         → oldest elements? → queue

step 2: do i need nearest greater/smaller?
         → monotonic stack

step 3: do i need BFS / level by level?
         → queue

step 4: do i need max/min of a sliding window?
         → monotonic deque

step 5: do i need to match pairs?
         → stack
```

---

## things that will save you from runtime crashes

```cpp
// always before top() or pop() on stack
if (!st.empty()) { ... }

// always before front() or pop() on queue  
if (!q.empty()) { ... }

// in while loops
while (!st.empty() && st.top() < current) { ... }
//                  ^^^^^^^^^^^^^^^^^^^
//                  condition on top() must come AFTER empty check
```

---

## one line summary

```
stack  → care about the most recent thing you saw
queue  → care about the oldest thing you saw
```

everything else is just a variation of this.