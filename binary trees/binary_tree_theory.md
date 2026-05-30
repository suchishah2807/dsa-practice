# Binary Tree

---

## what is a binary tree

a node with at most two children. left and right.

```
        1          ← root
       / \
      2   3        ← children of 1
     / \
    4   5          ← children of 2
```

every node has:
- a value
- a left pointer (null if no left child)
- a right pointer (null if no right child)

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
```

---

## the only thing you need to understand first

**every binary tree problem is just recursion.**  
and recursion on trees always follows the same 3-step framework from the recursion notes:

```
1. expectation  → what do i want this function to return/do?
2. faith        → assume it works correctly for left and right subtree
3. connection   → use left and right results to build answer for current node
```

plus always:
```
4. base case    → what happens at NULL?
```

if you can answer these 4 things → code writes itself.

---

## traversals — the foundation

three ways to visit every node. only difference is when you process the current node.

### preorder — root, left, right

```
        [1]         ← process 1 first
        / \
      [2]  [3]      ← then go left subtree, then right
      / \
    [4] [5]

order: 1, 2, 4, 5, 3
```

step by step (★ = currently executing):

```
step 1:          step 2:          step 3:          step 4:
   ★1               1                1                1
   / \             / \              / \              / \
  2   3          ★2   3            2   3            2   3
 / \            / \              / \              / \
4   5          4   5           ★4   5            4  ★5

print 1         print 2         print 4          print 5
call left(2)    call left(4)    left=null        left=null
                                right=null       right=null
                                return           return

step 5:
   1
   / \
  2   ★3
 / \
4   5

print 3
left=null
right=null
return
```

```cpp
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    ans.push_back(root->val);   // root
    preorder(root->left, ans);  // left
    preorder(root->right, ans); // right
}
```

### inorder — left, root, right

```
        1
        / \
      2    3
     / \
    4   5

order: 4, 2, 5, 1, 3
```

step by step:

```
step 1:          step 2:          step 3:          step 4:
   1                1                1                1
   / \             / \              / \              / \
  2   3           2   3            2   3            2   3
 / \            / \              / \              / \
4   5          4   5           ★4   5            4  ★5
★ = at 1       ★ = at 2         left=null        left=null
go left(2)     go left(4)       right=null       right=null
               (going left)     print 4 ✓        (back at 2)
                                return           print 2 ✓
                                                 now go right(5)
                                                 print 5 ✓

step 5: back at 1, print 1, go right(3), print 3
order: 4, 2, 5, 1, 3 ✓
```

```cpp
void inorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    inorder(root->left, ans);   // left
    ans.push_back(root->val);   // root
    inorder(root->right, ans);  // right
}
```

### postorder — left, right, root

```
order: 4, 5, 2, 3, 1
```

```cpp
void postorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    postorder(root->left, ans);  // left
    postorder(root->right, ans); // right
    ans.push_back(root->val);    // root
}
```

**one template, just move the push_back line. that's it.**

---

## BFS — level order (queue, not recursion)

process level by level. uses a queue.

```
        1           level 1: [1]
       / \
      2   3         level 2: [2, 3]
     / \
    4   5           level 3: [4, 5]
```

```
start: queue = [1]

pop 1, push 2 and 3:
queue = [2, 3]        → level 1 done

pop 2, push 4 and 5:
queue = [3, 4, 5]
pop 3, no children:
queue = [4, 5]        → level 2 done

pop 4, no children:
pop 5, no children:
queue = []            → level 3 done
```

```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int size = q.size();          // nodes at THIS level
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front(); q.pop();
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

`size` snapshot before the loop = how many nodes belong to current level.

---

## the DFS template — used for almost everything

```cpp
returnType dfs(TreeNode* root, /* anything passing down */) {
    if (root == NULL) return /* base case */;

    auto left  = dfs(root->left,  /* pass down */);
    auto right = dfs(root->right, /* pass down */);

    return /* combine left + right + current node */;
}
```

two questions to answer before coding:
```
what goes DOWN?   → info the children need (max so far, target, depth)
what comes UP?    → info the parent needs (height, count, sum, bool)
```

---

## height of tree

```
        1
       / \
      2   3
     / \
    4   5
```

```
faith: assume height(left) and height(right) work
connection: height of node = 1 + max(height(left), height(right))
base case: null node has height -1 (so leaf has height 0)
```

trace:

```
step 1: at 4         step 2: at 5         step 3: at 2
   1                    1                    1
   / \                  / \                  / \
  2   3                2   3               ★2   3
 / \                  / \                 / \
★4   5               4  ★5              4   5

left=null(-1)        left=null(-1)       left=0 (from 4)
right=null(-1)       right=null(-1)      right=0 (from 5)
return 1+max(-1,-1)  return 1+max(-1,-1) return 1+max(0,0)
     = 0                  = 0                 = 1

step 4: at 3         step 5: at 1
   1                   ★1
   / \                 / \
  2  ★3               2   3
 / \
4   5

left=null(-1)        left=1 (from 2)
right=null(-1)       right=0 (from 3)
return 0             return 1+max(1,0) = 2
```

height of tree = 2 ✓

```cpp
int height(TreeNode* root) {
    if (root == NULL) return -1;
    int left  = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}
```

---

## diameter of tree

diameter = longest path between any two nodes. path passes through some highest point.

at every node: diameter through this node = left height + right height + 2

```
        1
       / \
      2   3
     / \
    4   5

at node 2: left height = 0 (node 4), right height = 0 (node 5)
diameter through 2 = 0 + 0 + 2 = 2 edges ✓
```

key insight — **the function returns height, but updates diameter as a side effect.**

```
what goes DOWN? → nothing
what comes UP?  → height (for parent's diameter calculation)
side effect     → update global max diameter at each node
```

```cpp
int res = 0;

int dfs(TreeNode* root) {
    if (root == NULL) return -1;
    int left  = dfs(root->left);
    int right = dfs(root->right);
    res = max(res, 2 + left + right);   // diameter at this node
    return 1 + max(left, right);        // height for parent
}
```

**one function doing two jobs. returns height upward. updates answer along the way.**

---

## max path sum

same idea as diameter but with values instead of edges.

at every node: path sum through this node = node.val + max(left,0) + max(right,0)

why `max(left, 0)`? → if left path is negative, don't take it. 0 is better.

```
        1
       / \
     -2   3

at node 1:
left = -2 → negative, take 0 instead
right = 3
path through 1 = 1 + max(-2,0) + max(3,0) = 1 + 0 + 3 = 4

returned to parent: 1 + max(left, right, 0) = 1 + max(-2, 3, 0) = 4
```

```cpp
int res = INT_MIN;  // not 0, handles all-negative trees

int dfs(TreeNode* root) {
    if (root == NULL) return 0;
    int left  = dfs(root->left);
    int right = dfs(root->right);
    res = max(res, root->val + max(left,0) + max(right,0));
    return root->val + max({left, right, 0});
}
```

**common mistake: initializing res=0. fails when all nodes are negative.**

---

## good nodes

good node = no node on path from root to it is greater than it.

```
what goes DOWN? → max value seen so far on path
what comes UP?  → count of good nodes in subtree
```

```
        3
       / \
      1   4
     /   / \
    3   1   5

going down left path: 3 → 1 → 3
maxSoFar at each:      3    3    3
is node >= max?        yes  no   yes   → 2 good nodes on this path
```

```cpp
int dfs(TreeNode* root, int maxSoFar) {
    if (root == NULL) return 0;
    int good = (root->val >= maxSoFar) ? 1 : 0;
    int newMax = max(maxSoFar, root->val);
    return good + dfs(root->left, newMax) + dfs(root->right, newMax);
}
```

---

## balanced binary tree

balanced = at every node, |left height - right height| <= 1.

```
what goes DOWN? → nothing
what comes UP?  → height, but return -1 as a signal if unbalanced
```

```
if left returns -1  → already unbalanced below, propagate -1 up
if right returns -1 → same
if |left-right| > 1 → unbalanced here, return -1
else                → return actual height
```

```cpp
int dfs(TreeNode* root) {
    if (root == NULL) return 0;
    int left  = dfs(root->left);
    int right = dfs(root->right);
    if (left == -1 || right == -1)    return -1;  // unbalanced below
    if (abs(left - right) > 1)        return -1;  // unbalanced here
    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
}
```

**-1 as a signal is cleaner than a global bool. once unbalanced, -1 propagates all the way up.**

---

## same tree / symmetric tree / subtree

all three use the same idea — compare two nodes simultaneously.

### same tree

```
are p and q identical?

both null         → true  (base case, matched till here)
one null one not  → false (structure differs)
values differ     → false
else              → recurse: same(p.left, q.left) AND same(p.right, q.right)
```

### symmetric tree

mirror of left and right subtree.

difference from same tree — instead of comparing same sides, compare opposite sides.

```
same tree:   left.left  vs right.left    (same side)
symmetric:   left.left  vs right.right   (opposite side) ← flip this
             left.right vs right.left    (opposite side) ← and this
```

### subtree of another tree

is subRoot a subtree of root?

```
at every node of root: is this node's subtree == subRoot?
if yes → true
if no  → check left subtree and right subtree
```

```cpp
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

---

## LCA — lowest common ancestor

lowest node that has both p and q in its subtree.

```
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

LCA(6, 4) = 5
LCA(6, 8) = 3
```

key insight:
```
if root == p or root == q → root is the LCA (or one of them is ancestor of other)
if p is in left and q is in right → current node is LCA
if both in left → LCA is in left subtree
if both in right → LCA is in right subtree
```

```cpp
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    if (root == p || root == q) return root;

    TreeNode* left  = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if (left && right) return root;   // p and q on different sides
    return left ? left : right;       // both on same side
}
```

---

## right side view

what you see looking from the right = last node at each level.

```
        1           → see 1
       / \
      2   3         → see 3
     / \
    4   5           → see 5
```

BFS + take last element of each level.

```cpp
// inside level order loop:
if (i == size - 1) ans.push_back(node->val);  // last node of level
```

---

## min depth vs max depth

max depth → standard height. go as deep as possible.

min depth → first leaf node you hit in BFS.

**common mistake with min depth using DFS:**

```
        1
       /
      2

min depth = 2, not 1.
node 1 has no right child, but that doesn't make it a leaf.
leaf = both children NULL.
```

```cpp
// wrong for min depth:
return 1 + min(left, right);   // ❌ returns 1 if one child is null

// correct:
if (!root->left)  return 1 + right;   // no left, must go right
if (!root->right) return 1 + left;    // no right, must go left
return 1 + min(left, right);          // both exist, take min
```

or just BFS — first leaf you encounter is always at min depth.

---

## things you keep missing (from our sessions)

### 1. global variable gets overwritten

```cpp
bool ans = true;
// somewhere deep in recursion:
ans = true;   // ❌ overwrites a false set earlier
```

fix: never set back to true once false. or use return value instead of global.

```cpp
if (condition bad) ans = false;   // only ever set false, never set true again
```

### 2. returning wrong thing from recursive function

```cpp
return max(leftsum, rightsum);          // ❌ missing root->val
return root->val + max(leftsum, rightsum, 0);  // ✓
```

always ask: what does the parent need from me?

### 3. not clamping negative paths to 0

```cpp
res = max(res, root->val + left + right);           // ❌ adds negative paths
res = max(res, root->val + max(left,0) + max(right,0)); // ✓
```

### 4. initializing result as 0 instead of INT_MIN

```cpp
int res = 0;      // ❌ fails for all-negative trees
int res = INT_MIN; // ✓
```

### 5. null pointer crash

```cpp
root->left->val    // ❌ crashes if root->left is null
```

always check: `if (root->left)` before accessing left's children.

### 6. assignment instead of comparison

```cpp
if (root = NULL)   // ❌ sets root to null, always returns
if (root == NULL)  // ✓
```

---

## how to identify it's a binary tree problem

```
"given a tree, find..."          → DFS with return value
"path from root to..."           → DFS passing info downward
"some property at every node..." → DFS with global tracking
"level by level..."              → BFS with queue
"compare two trees..."           → simultaneous DFS on both
"lowest common..."               → LCA pattern
```

---

## the 4 questions before coding any tree problem

```
1. base case      → what do i return when root is NULL?
2. what goes down → what info do children need from parent?
3. what comes up  → what info does parent need from children?
4. what's the answer → where do i update/return the final answer?
```

answer these → code writes itself. every time.