### Arrays (`array.cpp`)
- Fixed size, continuous memory.
- Name of the array is a constant pointer to `a[0]`.
- Can use pointer arithmetic: `a+2` refers to `a[2]`.
- Relational operators work on pointers.

### Vectors  (`vectors.cpp`)
- Dynamic arrays (auto-resizable).
- Support random access.
- Useful in most competitive programming problems.

### Deque  (`deque.cpp`)
- internally built using dynamic arrays
- Double-ended queue.
- Allows insertion/removal from both ends in O(1).
- Supports random access (via `[]`, `at()`, iterators).
- Useful in sliding window problems.

### List  (`list.cpp`)
- internally built using Doubly linked list.
- Constant time insertion/deletion anywhere.
- No random access (unlike vectors).

### Pair
- Used to store two values.
- Common in sorting and mapping.

### Stack
- LIFO (Last In, First Out).
- Push/pop from the top only.
- Useful for recursion, parsing, etc.

### Queue
- FIFO (First In, First Out).
- Push at back, pop from front.
- Used in BFS, scheduling, etc.

### Map
- Stores key-value pairs in sorted order by key.
- O(log n) insertion/search using Red-Black Tree.

### Multimap
- Allows duplicate keys.
- Elements stored in sorted order.

### Unordered Map
- Hash table implementation.
- Average O(1) insertion/search.
- No guaranteed order.

### Set
- Stores unique elements in sorted order.
- Based on balanced BST.

### Multiset
- Like set, but allows duplicates.

### Unordered Set
- Like set, but no order guarantee.
- Based on hash table.