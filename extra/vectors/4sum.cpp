#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;
    vector<int> generateHugeVector() {
    vector<int> v;
    for (int i = -5000; i <= 5000; ++i) {
        v.push_back(i);
    }
    return v;
}

void _4sum(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 4) return; // Not enough elements for a quadruplet
    set<vector<int>> uniqueQuadruplets; // To avoid duplicates
    sort(nums.begin(), nums.end()); // Sort the array to use two-pointer technique

    for(int i=0;i<n;i++){
        // int target= nums[i];
        for(int j=i+1;j<n;j++){
            int left =j+1;
            int right = n-1;    
            while(left<right){
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target){
                    vector<int> ans{nums[i], nums[j], nums[left], nums[right]};
                    uniqueQuadruplets.insert(ans);
                }
                if(sum < target){
                    left++;
                }
                else{
                    right--;
                }

            }
        }
    }
    for(auto& quadruplet : uniqueQuadruplets) {
        cout << quadruplet[0] << " " << quadruplet[1] << " " << quadruplet[2] << " " << quadruplet[3] << endl;
    }
}

int main() {
    // Format: vector<int> nums, int target;

vector<int> nums1 = {}; 
int target1 = 0;  // Edge: Empty input
vector<int> nums2 = {1}; 
int target2 = 1;  // Edge: Not enough elements
vector<int> nums3 = {0, 0, 0, 0};
 int target3 = 0;  // All zero, valid: [[0,0,0,0]]
vector<int> nums4 = {1, 0, -1, 0, -2, 2};
 int target4 = 0;  // Valid: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
vector<int> nums5 = {2, 2, 2, 2, 2}; 
int target5 = 8;  // Valid: [[2,2,2,2]]
vector<int> nums6 = {-3, -1, 0, 2, 4, 5}; 
int target6 = 2;  // Valid: [[-3,-1,2,4]]
vector<int> nums7 = {1, -2, -5, -4, -3, 3, 3, 5}; 
int target7 = -11;  // Valid: [[-5,-4,-3,1]]
vector<int> nums8 = {-5,5,4,-3,0,0,4,-2};
 int target8 = 4;  // Multiple combinations with zeros
vector<int> nums9 = {-1000000000,-1000000000,1000000000,1000000000}; int target9 = 0;  // Edge: Large values with overflow potential
vector<int> nums10 = generateHugeVector(); 
int target10 = 0;  // Stress: 10^4 values

_4sum(nums1, target1);
_4sum(nums2, target2);
_4sum(nums3, target3);
_4sum(nums4, target4);
_4sum(nums5, target5);
_4sum(nums6, target6);
_4sum(nums7, target7);
_4sum(nums8, target8);
_4sum(nums9, target9);
_4sum(nums10, target10); 


    return 0;
}