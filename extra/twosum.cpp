#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <chrono>
#include <unordered_map>
#include <random>


void brute(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    // print <int> p(ans);
    
}

void test(vector<int>& nums, int target) {
    vector<int> ans;
    vector <int> temp(nums);
    sort(temp.begin(), temp.end());
    int start=0, end=nums.size()-1;
    while(start<end){
        if(temp[start] + temp[end] == target and start != end){
            ans.push_back(temp[start]);
            ans.push_back(temp[end]);
            break;
        }
        else if(temp[start] + temp[end] < target){
            start++;
        }
        else{
            end--;
        }
    }
    if (ans.empty()) {
        // cout << "No two numbers found that add up to " << target << endl;
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i] == ans[0]){
            ans[0] = i;
            break;
        }
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i] == ans[1]){
            ans[1] = i;
            break;
        }
    }
    // print <int> p(ans);
}

void hashing(vector<int>&nums , int target){
    pair<int, int> ans={-1,-1};
    unordered_map<int, int> fast;
    for(int i=0;i<nums.size();i++){

        int complement = target - nums[i];
        if(fast.find(complement) != fast.end()) {
            if(fast[complement] == nums[i]) continue; // Avoid using the same element
            ans.first = fast[complement];
            ans.second = i;
            break; // Found the pair, exit loop
        }
       fast[nums[i]] = i; 


    }
  // print <pair<int, int>> p(ans);
}



using namespace std;

int main() {
    // Format: {nums, target}
vector<int> vec1 = {2, 7, 11, 15}; // target = 9 → indices: 0,1
vector<int> vec2 = {3, 2, 4};      // target = 6 → indices: 1,2
vector<int> vec3 = {3, 3};         // target = 6 → indices: 0,1 (duplicates)
vector<int> vec4 = {1, 2, 3, 4, 4}; // target = 8 → indices: 3,4 (same value)
vector<int> vec5 = {1};            // target = 2 → should fail or return empty (not enough elements)
vector<int> vec6 = {-1, -2, -3, -4, -5}; // target = -8 → indices: 2,4
vector<int> vec7 = {INT_MAX, INT_MIN, 0}; // target = INT_MAX → indices: 0,2
vector<int> vec8 = {0, 4, 3, 0};    // target = 0 → indices: 0,3
vector<int> vec9 = {1, 5, 1, 5};    // target = 10 → indices: 1,3 (repeats)
vector<int> vec10(1e4, 1); vec10[0] = 2; vec10[9999] = 3; // target = 5 → indices: 0,9999 (stress test)

    using namespace std::chrono;
    auto start_brute = high_resolution_clock::now();
    brute(vec1, 9);
    brute(vec2, 6);
    brute(vec3, 6);
    brute(vec4, 8);
    brute(vec5, 2);
    brute(vec6, -8);
    brute(vec7, INT_MAX);
    brute(vec8, 0);
    brute(vec9, 10);
    brute(vec10, 5);
    auto end_brute = high_resolution_clock::now();
    auto duration_brute = duration_cast<microseconds>(end_brute - start_brute);
    cout << "Time taken by brute: " << duration_brute.count() << " microseconds" << endl;

    auto start_test = high_resolution_clock::now();
    test(vec1, 9);
    test(vec2, 6);
    test(vec3, 6);
    test(vec4, 8);
    test(vec5, 2);
    test(vec6, -8);
    test(vec7, INT_MAX);
    test(vec8, 0);
    test(vec9, 10);
    test(vec10, 5);
    auto end_test = high_resolution_clock::now();
    auto duration_test = duration_cast<microseconds>(end_test - start_test);
    cout << "Time taken by test: " << duration_test.count() << " microseconds" << endl;

        auto start = high_resolution_clock::now();
    hashing(vec1, 9);
    hashing(vec2, 6);
    hashing(vec3, 6);
    hashing(vec4, 8);
    hashing(vec5, 2);   
    hashing(vec6, -8);
    hashing(vec7, INT_MAX);
    hashing(vec8, 0);
    hashing(vec9, 10);
   hashing(vec10, 5);
     auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by hashing: " << duration.count() << " microseconds" << endl;

    vector<int> stress1(1e4, 5);         int target1 = 10;        // All elements are the same
vector<int> stress2(1e5);            int target2 = 199998;    // Strictly increasing
for (int i = 0; i < 1e5; i++) stress2[i] = i;

vector<int> stress3(1e5);            int target3 = 123456;
for (int i = 0; i < 1e5; i++) stress3[i] = 1e5 - i; // Strictly decreasing

vector<int> stress4(1e5);            int target4 = 199999;
for (int i = 0; i < 1e5; i++) stress4[i] = i * 2;  // Large gaps between numbers

vector<int> stress5(1e5, INT_MAX);   int target5 = INT_MAX * 2; // Possible overflow, all same large value

vector<int> stress6(1e5);            int target6 = 100000;
for (int i = 0; i < 1e5; i++) stress6[i] = i % 1000;  // Lots of repetition

vector<int> stress7(1e5);            int target7 = 100;
for (int i = 0; i < 1e5; i++) stress7[i] = rand() % 1000;  // Random numbers, small range

vector<int> stress8(1e6);            int target8 = 1999998;
for (int i = 0; i < 1e6; i++) stress8[i] = i;  // Huge input, strictly increasing

vector<int> stress9(1e6);            int target9 = 500001;
for (int i = 0; i < 1e6; i++) stress9[i] = rand() % 500000;  // Large, high-collision input

vector<int> stress10(1e6);           int target10 = 987654;
for (int i = 0; i < 1e6; i++) stress10[i] = (i * 7) % 1000000; // Pseudo-random unique values

    auto start_stress = high_resolution_clock::now();
    test(stress1, target1);
    test(stress2, target2);
    test(stress3, target3);
    test(stress4, target4);
    test(stress5, target5);
    test(stress6, target6);
    test(stress7, target7);
    test(stress8, target8);
    test(stress9, target9);
    test(stress10, target10);
    auto end_stress = high_resolution_clock::now();
    auto duration_stress = duration_cast<milliseconds>(end_stress - start_stress);
    cout << "Time taken by test on stress cases: " << duration_stress.count() << " microseconds" << endl;

    auto start_hashing = high_resolution_clock::now();
    hashing(stress1, target1);
    hashing(stress2, target2);
    hashing(stress3, target3);
    hashing(stress4, target4);
    hashing(stress5, target5);
    hashing(stress6, target6);
    hashing(stress7, target7);
    hashing(stress8, target8);
    hashing(stress9, target9);
    hashing(stress10, target10);
    auto end_hashing = high_resolution_clock::now();
    auto duration_hashing = duration_cast<milliseconds>(end_hashing - start_hashing);   
    cout << "Time taken by hashing on stress cases: " << duration_hashing.count() << " microseconds" << endl;


    return 0;
}