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

## compress.cpp
Purpose: Compress a character array in-place by replacing sequences of the same character with the character followed by its count.

- Iterates through the array, counting consecutive duplicates.
- For each group, appends the character and its count (if >1) to the array.
- Handles single and multi-digit counts.
- Erases the original segment and prints the compressed result.

## reverse.cpp
Purpose: Reverse the order of words in a string, preserving the words themselves.

- Reverses the entire string, then reverses each word to restore their original order.
- Skips extra spaces between words.
- Returns the resulting string with words in reverse order, separated by single spaces.

## sieve.cpp
Purpose: Count the number of prime numbers less than or equal to a given number using the Sieve of Eratosthenes.

- Uses a boolean vector to mark non-prime numbers.
- Skips even numbers for efficiency, except for 2.
- Iterates from 3 upwards, marking multiples as non-prime.
- Handles edge cases (n = 0, 1, 2) efficiently.
- Returns the count of primes up to n.

## HCF.cpp
Purpose: Compute the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of two integers using both brute-force and Euclidean algorithms.

- `brute`: Checks all possible divisors from min(a, b) down to 1.
- `euclid`: Uses the efficient Euclidean algorithm (modulus-based).
- Handles negative and zero inputs robustly.
- Includes LCM calculation using GCD.
- Measures and compares execution time for both GCD methods.
- Includes comprehensive test cases for correctness and performance.

## slow_fast.cpp
Purpose: Find the duplicate number in an array using Floyd's Tortoise and Hare (cycle detection) algorithm.

- Uses two pointers (slow and fast) to detect a cycle in the array, treating values as next indices.
- Efficiently finds the duplicate without modifying the array or using extra space.
- Handles various edge cases and large test cases.
- Time Complexity: O(n), Space Complexity: O(1).

## twosum.cpp
Purpose: Solve the Two Sum problem using multiple approaches and benchmark their performance.

- Implements brute-force, two-pointer (after sorting), and hashing (unordered_map) solutions.
- Includes comprehensive test cases and stress tests for correctness and efficiency.
- Demonstrates index/value mapping and edge case handling.



