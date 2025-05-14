#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool possible(vector<int> arr, int no, int mid){
    
    int laststall = arr[0];
    int cows = 1;
    for(int i=1;i<arr.size();i++){
        if((arr[i]-laststall) >= mid){
            cows++;
            laststall = arr[i];
        }
        if(cows == no) return true;

    }
    return false;
}

int optimize(vector<int> arr, int no){
    int   ans{0};
    sort(arr.begin(),arr.end());
    int end=0,start{};
   for (int i:arr){
    end = max(end,i);
    start=min(start,i);
   }
    end = end -start;
   
    
    while(start<=end){
        int mid= start+ (end-start)/2;

        if(possible(arr,no,mid)){
            ans= mid;
            start=mid+1;
        }
        else end=mid-1; 
    }
    return ans;
}

int main(){
    // 🐄 Test Case 1: Normal Case 1
// Stalls: [1, 2, 4, 8, 9], Cows: 3
// Expected Output: 3
cout << "Normal 1: " << optimize({1, 2, 4, 8, 9}, 3) << endl;

// 🐄 Test Case 2: Normal Case 2
// Stalls: [5, 17, 100, 11], Cows: 2
// Expected Output: 95
cout << "Normal 2: " << optimize({5, 17, 100, 11}, 2) << endl;

// 🐄 Test Case 3: Edge Case — Minimum Cows (1)
// Any stall is fine, max distance is irrelevant
// Expected Output: 99 (max stall - min stall)
cout << "Edge Case (1 cow): " << optimize({1, 100, 99, 2}, 1) << endl;

// 🐄 Test Case 4: Edge Case — All Cows = All Stalls
// Cows = number of stalls, so place one cow per stall
// Expected Output: 1 (minimum possible distance)
cout << "Edge Case (cows == stalls): " << optimize({1, 2, 3, 4, 5}, 5) << endl;

// 🐄 Test Case 5: Duplicate Stalls
// Stalls at the same location should still work
// Expected Output: 0
cout << "Duplicate stalls: " << optimize({5, 5, 5, 5}, 2) << endl;

// 🐄 Test Case 6: Large Gaps
// Ensures your binary search handles big differences
// Expected Output: 500000
cout << "Large Gaps: " << optimize({1, 1000001, 2000001, 3000001, 4000001}, 3) << endl;

// 🐄 Test Case 7: Tight spacing, high cow count
// All stalls are adjacent, but too many cows
// Expected Output: 1
cout << "Tight & Max Cows: " << optimize({1, 2, 3, 4, 5, 6}, 6) << endl;

// 🐄 Test Case 8: Stress Test — 1e5 stalls in order
// Spaced by 1, cows = 2, should return 99999
vector<int> stalls(1e5);
iota(stalls.begin(), stalls.end(), 1);
cout << "Stress (1e5 stalls, 2 cows): " << optimize(stalls, 2) << endl;

// 🐄 Test Case 9: Stress Test — 1e5 stalls, cows = 50000
// Should return around 2
cout << "Stress (1e5 stalls, 50000 cows): " << optimize(stalls, 50000) << endl;

// 🐄 Test Case 10: All stalls same location, multiple cows
// Can't place cows with any distance > 0
// Expected Output: 0
cout << "All stalls same: " << optimize(vector<int>(10, 42), 3) << endl;

}