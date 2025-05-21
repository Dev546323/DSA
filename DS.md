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


### Pair (`pair.cpp`)
- Used to store two values.
- Common in sorting and mapping.


### Stack (`stack.cpp`)
- LIFO (Last In, First Out).
- Push/pop from the top only.
- Useful for recursion, parsing, etc.


### Queue (`queue.cpp`)
- FIFO (First In, First Out).
- Push at back, pop from front.
- Used in BFS, scheduling, etc.
    ### Priority Queue
    - Max Heap by default (`priority_queue<int>`).
        - highest value stays on top
    - For Min Heap: `priority_queue<int, vector<int>, greater<int>>`.
        - lowest value stays on top 
    - Useful for greedy algorithms, Dijkstra’s, etc.
    - interanlly a  binary tree


### Map (`map.cpp`)
- internally balanced binary tree. 
- Stores key-value pairs in sorted order by key.
- keys are always unique, and corresponds to a value. 
- keys are lexicographically sorted
- O(log n) insertion/search using Red-Black Tree.
    ### Multimap
    - Allows duplicate keys.
    - Elements stored in lexicographically sorted order.
    - can't use [], instead must use `.insert` function

    ### Unordered Map
    - Hash table internally.
    - Average O(1) insertion/search.
    - No guaranteed order.
    


### Set (`set.cpp`)
- Stores unique elements in sorted order.
- ignores duplicate values. 
- Based on balanced BST.
    ### Multiset
    - Like set, but allows duplicates.
    ### Unordered Set
    - Like set, but no order guarantee.
    - Based on hash table.


EXTRA
### while passing values () passes values directly ({}) creates an object that passes the value. 
- emplace function doesn't require object creation

## comparators 
- they are nothing but boolean functions. check (`sort.cpp`) to see a 
