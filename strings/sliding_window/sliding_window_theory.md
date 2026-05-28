# Sliding Window

---

## what even is a window

just a subarray. a contiguous chunk between two pointers `i` and `j`.

```
arr = [1, 3, 2, 6, 4, 8]
         ^        ^
         i        j

window = [3, 2, 6, 4]
```

`i` → start  
`j` → end  
size → `j - i + 1`

---

## why not just brute force

brute force = two loops = O(n²). works, but too slow for large inputs.

sliding window = O(n). instead of recomputing the whole window every time, you just:
- add the new element on the right (`j` moves in)
- remove the old element on the left (`i` moves out)

previous computation gets reused. that's the whole trick.

---

## two types

```
type 1 → fixed size window    (k is given)
type 2 → variable size window (a condition is given, find longest/shortest)
```

---

## type 1 — fixed size window

k is given. window must be exactly of size k. slide it across.

```
arr = [1, 3, -1, -3, 5, 3]   k = 3

window 1: [1,  3, -1]
window 2:    [3, -1, -3]
window 3:       [-1, -3, 5]
window 4:           [-3, 5, 3]
```

### how it works

```
keep expanding j
when size hits k → valid window, calculate answer
then remove arr[i], move i forward
then move j forward
repeat
```

### full trace

```
arr = [1, 3, -1, -3, 5, 3]   k = 3
i=0, j=0

j=0: add 1  → window=[1]        size=1, not k yet,     j++
j=1: add 3  → window=[1,3]      size=2, not k yet,     j++
j=2: add -1 → window=[1,3,-1]   size=3 == k → answer!
             remove arr[0]=1, i=1, j++

j=3: add -3 → window=[3,-1,-3]  size=3 == k → answer!
             remove arr[1]=3, i=2, j++

j=4: add 5  → window=[-1,-3,5]  size=3 == k → answer!
             remove arr[2]=-1, i=3, j++

j=5: add 3  → window=[-3,5,3]   size=3 == k → answer!
             remove arr[3]=-3, i=4, j++

j=6: loop ends
```

### template

```cpp
int i = 0, j = 0;
// whatever you're tracking (sum, map, deque...)

while (j < n) {
    // add arr[j] into your data structure

    if (j - i + 1 < k) {
        j++;
    }
    else if (j - i + 1 == k) {
        // valid window → calculate answer here

        // remove arr[i] from data structure
        i++;
        j++;
    }
}
```

### what actually changes between questions

the template above never changes. what changes is just what you're tracking inside.

```
max sum of subarray size k          → track running sum (int)
max element in every window size k  → track monotonic deque
first negative in every window      → track queue of negatives
count of anagrams in string         → track frequency map
```

same skeleton. different internals.

---

## type 2 — variable size window

no fixed k. instead a condition is given. find the longest (or shortest) window that satisfies it.

```
examples:
- sum == k
- sum <= k
- all characters unique
- at most k distinct characters
```

### how it works

```
expand j → as long as condition holds or might hold
shrink i → the moment condition is violated
```

that's it. two rules.

### full trace

```
arr = [2, 1, 5, 2, 3, 2]
find longest subarray with sum <= 7

i=0, j=0, sum=0

j=0: add 2  → sum=2  ≤ 7 → valid  → ans=1,  j++
j=1: add 1  → sum=3  ≤ 7 → valid  → ans=2,  j++
j=2: add 5  → sum=8  > 7 → violated!
             remove arr[0]=2 → sum=6, i=1
             sum=6 ≤ 7 → valid → ans=2, j++

j=3: add 2  → sum=8  > 7 → violated!
             remove arr[1]=1 → sum=7, i=2
             sum=7 ≤ 7 → valid → ans=2, j++

j=4: add 3  → sum=10 > 7 → violated!
             remove arr[2]=5 → sum=5, i=3
             sum=5 ≤ 7 → valid → ans=2, j++

j=5: add 2  → sum=7  ≤ 7 → valid  → ans=3 ← new max!, j++

done. answer = 3
```

### template

```cpp
int i = 0, j = 0;
int ans = 0;
// whatever you're tracking

while (j < n) {
    // add arr[j] into your data structure

    while (condition is violated) {
        // remove arr[i] from data structure
        i++;
    }

    // if you reach here, condition is satisfied
    ans = max(ans, j - i + 1);
    j++;
}
```

for smallest window, replace `max` with `min` and only update ans when condition is met, not always.

### what changes between questions

just the violation condition and what you're tracking.

```
longest subarray sum <= k          → violated when sum > k
longest substring all unique       → violated when any freq > 1
longest substr at most k distinct  → violated when map.size() > k
smallest subarray sum >= k         → violated never (shrink when valid instead)
```

---

## how to identify which type

```
"subarray of size k"                → fixed size
"longest subarray where..."         → variable, maximize
"smallest subarray where..."        → variable, minimize
"count subarrays where..."          → variable, count valid windows
```

---

## one thing that never changes

```
i never goes back.
j never goes back.
every element enters once, leaves once → O(n).
```

this is why it's faster than brute force. no element is processed more than twice.

---

## data structures commonly used inside window

```
sum / product           → int
character frequencies   → vector<int>(26) or unordered_map
max or min of window    → monotonic deque
first negative number   → queue
count of distinct       → unordered_map, check .size()
```

---

## before coding any sliding window question, answer these

```
1. fixed size or variable?
2. what am i tracking inside the window?
3. what does valid mean?
4. what does violated mean?
5. maximizing or minimizing window size?
6. what exactly is the answer? (length, value, count?)
```

answer these six → the code follows naturally.