#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include <string>
#include <chrono>
#include <algorithm>


using namespace std;
using namespace std::chrono;

//recursion stops as soon as target is found, hence time is dependant on position of target in the array.
bool search(vector<int> &arr, int target, int index = 0) {
    if (index >= arr.size()) {
        return false; // Base case: if index exceeds array size, target not found
    }
    if (arr[index] == target) {
        return true; // Target found at current index
    }
    return search(arr, target, index + 1); // Recursive call with next index
}

bool binarysearch(vector<int> &arr, int target, int start = 0, int end = -1) {
    if (end == -1) {
        end = arr.size() - 1; // Initialize end on first call
       sort(arr.begin(), arr.end()); 
    }
    if (start > end) {
        return false; // Base case: if start index exceeds end index, target not found
    }
    int mid = start + (end - start) / 2; // Calculate mid index
    if (arr[mid] == target) {
        return true; // Target found at mid index
    } else if (arr[mid] < target) {
        return binarysearch(arr, target, mid + 1, end); // Search in right half
    } else {
        return binarysearch(arr, target, start, mid - 1); // Search in left half
    }
}

int main() {
   const int N = 100000; // 1e5 is recursion-safe for linear
    vector<int> v10(N);

    // Fill array with 0 to N-1
    for (int i = 0; i < N; ++i) v10[i] = i;  
    
    int target = N-50000;
    
    auto start_brute = high_resolution_clock::now();
    cout<<boolalpha<<search(v10, target) << endl; // Output: true if found, false otherwise
      auto end_brute = high_resolution_clock::now();
    auto duration_brute = duration_cast<microseconds>(end_brute - start_brute);
    cout << "Time taken by brute: " << duration_brute.count() << " microseconds" << endl;

     auto start = high_resolution_clock::now();
    cout<<boolalpha<<binarysearch(v10, target) << endl; // Output: true if found, false otherwise
      auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by binary: " << duration.count() << " microseconds" << endl;
    return 0;
}