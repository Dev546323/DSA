#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>

vector<int> brute(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans; // Return empty if no solution found
}

void test(vector<int>& nums, int target) {
    vector<int> ans;
    sort(nums.begin(), nums.end());
    int start=0, end=nums.size();
    while(start<end){
        if(nums[start] + nums[end-1] == target){
            ans.push_back(start);
            ans.push_back(end-1);
        }
        else if(nums[start] + nums[end-1] < target){
            start++;
        }
        else{
            end--;
        }
    }
    print <int> p(ans);
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

vector<pair<int,int>> test_cases = {
    {0, 1}, // vec1
    {1, 2}, // vec2
    {0, 1}, // vec3
    {3, 4}, // vec4
    {-1, -1}, // vec5 (not enough elements)
    {2, 4}, // vec6
    {0, 2}, // vec7
    {0, 3}, // vec8
    {1, 3}, // vec9
    {0, 9999} // vec10
};
print <int> p1(test_cases);

    return 0;
}