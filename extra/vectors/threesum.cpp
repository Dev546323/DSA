#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include <utility> 
#include <set>
#include <algorithm>
using namespace std;

// Brute-force O(n^3) solution: Try all triplets, use set to avoid duplicates
void threesum (vector<int>& nums) {
    set<vector<int>> ans; // Stores unique triplets
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                // Check if the sum of the triplet is zero
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end()); // Sort to ensure uniqueness
                    ans.insert(triplet); // Insert sorted triplet into set
                }
            }
        }
    }
    // Print all unique triplets found
    for(auto i: ans) {
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    cout<<endl;
    if(ans.empty()) {
        cout<<"No triplet found"<<endl;
    }
}

// Optimized O(n^2) solution: For each i, use a set to find pairs that sum to -nums[i]
void optimized (vector<int>& nums) {
    set<vector<int>> ans; // Stores unique triplets
    int n=nums.size();
    for(int i=0;i<n;i++){
        int target = -nums[i];
        set<int> nos; // Set to store seen numbers for current i
        for(int j=i+1;j<n;j++){
            // If complement exists, we found a triplet
            if(nos.find(target-nums[j]) != nos.end()) {
                vector<int> triplet = {nums[i], nums[j], target-nums[j]};
                ans.insert(triplet);
            }
            nos.insert(nums[j]); // Add current number to set
        }
    }
    // Print all unique triplets found
    for(auto i: ans) {
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    cout<<endl;
    if(ans.empty()) {
        cout<<"No triplet found"<<endl;
    }
}

// Two-pointer O(n^2) solution: Sort, then fix one element and use two pointers for the rest
void twopointer(vector<int> &nums){
    sort(nums.begin(), nums.end()); // Sort the array first
    set<vector<int>> ans; // Stores unique triplets
    int n = nums.size();    
    for(int i=0;i<n;i++){
        int target = -nums[i];
        int start = i+1, end = n-1;
        while(start<end){
            if(nums[start] + nums[end] == target){
                vector<int> triplet = {nums[i], nums[start], nums[end]};
                sort(triplet.begin(), triplet.end()); // Sort to ensure uniqueness
                ans.insert(triplet);
                start++;
                end--;
            }
            else if(nums[start] + nums[end] < target){ 
                start++;
            }
            else{
                end--;
            }
        }
    }
    vector<vector<int>> ans_vec(ans.begin(), ans.end()); // Convert set to vector for easier printing
    // Print all unique triplets found
   
}

using namespace std;

int main() {
    // Test cases for various edge and normal scenarios
    vector<int> input1 = {};  // Edge: Empty input
    vector<int> input2 = {0};  // Edge: Single element
    vector<int> input3 = {0, 0};  // Edge: Two elements
    vector<int> input4 = {0, 0, 0};  // Valid: [0, 0, 0]
    vector<int> input5 = {-1, 0, 1, 2, -1, -4};  // Standard: [[-1, -1, 2], [-1, 0, 1]]
    vector<int> input6 = {-2, 0, 0, 2, 2};  // Valid: [[-2, 0, 2]]
    vector<int> input7 = {3, -2, 1, 1,-1};  // Valid: [[-2, 1, 1] or similar]
    vector<int> input8 = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};  // Stress w/ duplicates
    vector<int> input9 = {-100000, -99999, 199999};  // Stress: Large values that cancel out

    // Uncomment to test each approach
    // threesum(input1);  
    // threesum(input2);  
    // threesum(input3);  
    // threesum(input4);  
    // threesum(input5);  
    // threesum(input6);  
    // threesum(input7);  
    // threesum(input8);  
    // threesum(input9); 

    // optimized(input5);
    twopointer(input5);
    return 0;
}