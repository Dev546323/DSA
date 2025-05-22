## palindrome.cpp
Purpose: Determine if a given string is a valid palindrome.

- Ignores non-alphanumeric characters (e.g., punctuation, spaces).
- Case-insensitive comparison.
- Uses two-pointer technique: start from both ends and move inward.

## occurences.cpp
Purpose: Continuously remove all occurrences of a substring `part` from a string `s`.

- Uses `string::find` to locate the first appearance of `part`.
- Uses `string::erase` to remove it.
- Loops until `part` no longer appears.
- Edge Case: Ensure index updates after each erase.

## water.cpp (Container With Most Water)
Purpose: Given an array of heights, find the max water that can be contained between two lines.

- Brute Force: Try all pairs of lines (O(n^2)).
- Optimal: Two-pointer approach — start at both ends, move the pointer pointing to the shorter line inward.

## unique.cpp
Purpose: Find the single unique element in a sorted array where all others appear exactly twice.

- Brute: Linear scan, check neighbors.
- Optimal: Binary search. Unique element lies on the side where `mid^1` ≠ pair.
- Time Complexity: O(log n).

## time.cpp
Purpose: Demonstrate various time complexities using example scenarios.

- O(1): Constant time (e.g., direct access).
- O(n): Linear time (e.g., array traversal).
- O(n^2): Nested loops (e.g., pair sums).
- O(n^3): Triple loops (e.g., subarray sums).

## space.cpp
Purpose: Explain how space complexity is measured in algorithms.

- Includes only extra memory (not input size).
- Stack space from recursion counts.
- Arrays/vectors created inside functions count.

## selfpdt.cpp (Product of Array Except Self)
Purpose: Return an array where each element is the product of all elements in the input except itself.

- Brute: Nested loops.
- Optimized: Use prefix and suffix product arrays.
- Most Optimal: Use output array for prefix; track suffix in a single variable.
- Time: O(n), Space: O(1) (excluding output).

## rotated.cpp
Purpose: Search in a rotated sorted array.

- One half is always sorted — use this to eliminate half the search space each time.
- Modified binary search approach.

## power.cpp
Purpose: Compute `a^b` efficiently.

- Uses binary exponentiation — reduces number of multiplications by squaring.
- Time: O(log b)

## pointers.cpp
Purpose: Explore pointers, pointer-to-pointer, arrays as pointers, and pointer arithmetic.

- Understand memory referencing and dereferencing.
- Practice pointer arithmetic with arrays.

## mountain.cpp
Purpose: Find the peak index in a mountain array (strictly increasing then strictly decreasing).

- Modified binary search — peak is always greater than neighbors.
- Time: O(log n)

## books.cpp
Purpose: Allocate books among students such that the maximum number of pages assigned to a student is minimized.

- Binary search on the range of possible max pages.
- Use greedy check function to validate allocations.

## cows.cpp (Aggressive Cows)
Purpose: Place cows in stalls to maximize the minimum distance between any two cows.

- Binary search on distance.
- Feasibility check: try placing cows greedily at `>= mid` distance.

## buy.cpp (Stock Buy & Sell)
Purpose: Find the maximum profit from buying and selling a stock once.

- Track the minimum price seen so far.
- Update max profit with current price - min price.
- One-pass linear time solution.