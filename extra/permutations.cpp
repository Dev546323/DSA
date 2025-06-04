#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>


using namespace std;

void permutations(vector<int> &nums, vector<vector<int>> &ans, int index =0){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        if(i != index/*to ensure a single output in case all elements are the same*/ && nums[i] == nums[index]) continue; // Skip duplicates
        swap(nums[index], nums[i]); // Swap current index with i
        permutations(nums, ans, index + 1); // Recur for next index
        swap(nums[index], nums[i]); // Backtrack to original order
    }
}

int main() {
    vector<int> v1 = {1};
vector<int> v2 = {1, 2};
vector<int> v3 = {1, 2, 3};
vector<int> v4 = {0, 0, 0};       // All duplicates
vector<int> v5 = {1, 1, 2};       // Partial duplicates
vector<int> v6 = {5, 5, 5, 4};    // Stress test for duplicates
vector<int> v7 = {3, 2, 1, 4};
vector<int> v8 = {-1, 0, 1};      // Includes negative
vector<int> v9  = {1, 2, 3, 4, 5, 6};          // 6! = 720 permutations
vector<int> v10 = {1, 2, 3, 4, 5, 6, 7, 8};    // 8! = 40,320 permutations

vector<vector<int>> ans;

    permutations(v1 ,ans);
    print <vector<vector<int>>> p(ans);
    ans.clear(); // Clear previous results
    permutations(v2 ,ans);
     print <vector<vector<int>>> p1(ans);
    ans.clear(); // Clear previous results
    permutations(v3 ,ans);
     print <vector<vector<int>>> p2(ans);
    ans.clear(); // Clear previous resultsi != index 
    permutations(v4 ,ans);
     print <vector<vector<int>>> p3(ans);
    ans.clear(); // Clear previous results
    permutations(v5 ,ans);
     print <vector<vector<int>>> p4(ans);
    ans.clear(); // Clear previous results
    permutations(v6 ,ans);
     print <vector<vector<int>>> p5(ans);
    ans.clear(); // Clear previous results
    permutations(v7 ,ans);
     print <vector<vector<int>>> p6(ans);
    ans.clear(); // Clear previous results
    permutations(v8 ,ans);
     print <vector<vector<int>>> p7(ans);
    ans.clear(); // Clear previous results
    permutations(v9 ,ans);
     print <vector<vector<int>>> p8(ans);
    ans.clear(); // Clear previous results
    // permutations(v10 ,ans);
    //  print <vector<vector<int>>> p9(ans);

    return 0;
}