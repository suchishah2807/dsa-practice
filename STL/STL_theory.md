I. Pairs and Vectors
1. Pairs (std::pair)
Pairs are used to maintain a relationship between two values of any data type.
• Syntax: pair<data_type1, data_type2> p;.
• Initialization: Use p = make_pair(2, "abc"); or the simpler C++11 curly brace syntax: p = {2, "abc"};.
• Access: Use p.first and p.second.
• Practical Use: Arrays of pairs are vital in maintaining linked data during operations like sorting or swapping.
2. Vectors (std::vector)
Vectors are dynamic arrays that resize themselves automatically.
• Basic Operations:
    ◦ push_back(val): Adds an element to the end (O(1)).
    ◦ pop_back(): Removes the last element (O(1)).
    ◦ size(): Returns current element count (O(1)).
• The Cost of Copying: Assigning one vector to another (v2 = v1) is an O(n) operation because it copies elements one by one.
• Functions: Always pass vectors by reference (vector<int> &v) in functions to avoid expensive O(n) copy operations.
• Memory Limits: Local vectors are limited to ~10^5 elements, while global vectors can reach ~10^7 elements.

--------------------------------------------------------------------------------
II. Iterators: Pointer-like Structures
Iterators point to the memory addresses of container elements.
• Essential Iterators:
    ◦ v.begin(): Points to the first element.
    ◦ v.end(): Points to the position after the last element.
• Access: Use the dereference operator *it to get the value. For pairs, use it->first or (*it).first.
• Arithmetic:
    ◦ it++: Moves to the next element (works for all containers).
    ◦ it + 1: Moves to the next memory location (works only for contiguous containers like vectors).

--------------------------------------------------------------------------------
III. C++11 Efficiency Features
1. The auto Keyword
auto allows the compiler to deduce data types automatically, which is essential for shortening long iterator declarations.
• Example: for(auto it = v.begin(); it != v.end(); ++it) replaces vector<int>::iterator.
2. Range-based Loops
This allows direct iteration over elements.
• Value vs. Reference: for(int value : v) creates a copy of each element, whereas for(int &value : v) allows you to modify the actual elements in the container.

--------------------------------------------------------------------------------
IV. Nesting in STL
Nesting allows for multi-dimensional or complex relationships.
• Vector of Pairs: vector<pair<int, int>> v; where each element is a pair.
• Array of Vectors: vector<int> v[N]; creates N vectors with fixed "rows" but dynamic "columns".
• Vector of Vectors: vector<vector<int>> v; creates a fully dynamic 2D structure where both rows and columns are dynamic.

--------------------------------------------------------------------------------
V. Maps (Key-Value Pairs)
1. Ordered Maps (std::map)
Maps store unique keys in sorted order (increasing for numbers, lexicographical for strings).
• Complexity: Insertion and access take O(logn).
• Internal Structure: Implemented using Red-Black Trees.
• Default Behavior: Accessing a non-existent key using m[key] will insert that key with a default value (e.g., 0 for int).
• Functions: m.find(key) returns m.end() if the key is missing; m.erase(key) removes the pair.
2. Unordered Maps (std::unordered_map)
• Complexity: Average time complexity is O(1) due to Hash Tables.
• Trade-offs: Elements are not sorted, and complex types (like pair) cannot be keys because they lack inbuilt hash functions.

--------------------------------------------------------------------------------
VI. Sets (Unique Elements)
1. Ordered Set (std::set)
A collection of unique elements stored in sorted order (O(logn)).
• Use Case: Ideal for maintaining a sorted collection of unique items.
2. Unordered Set (std::unordered_set)
Used for checking the existence of an element in O(1) average time.
3. Multiset (std::multiset)
Allows duplicate elements while maintaining sorted order.
• Important Erase Distinction:
    ◦ s.erase(val): Deletes all instances of that value.
    ◦ s.erase(it): Deletes only the specific instance pointed to by the iterator