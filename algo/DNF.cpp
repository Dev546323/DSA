//DNF = DUTCH NATIONAL FLAG ALGO.

#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<random>

using namespace std; 


void dnf(vector<int>& arr){ //since i'm changing the value in the og vector itself, it is necessary to pass by reference &
    int low=0, mid=0, high = (arr.size()-1);
    /*LOGIC
    0 should be present in the range 0-low-1
    1 should be present in the range low to mid-1
    2 should be present in the range high+1 to n-1*/

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            mid++; //to go to the next digit
            low++; //so that 0 doesn't exceed low-1
        }
        else if (arr[mid]==1){
            mid++; //so 1 is exactly at mid-1
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
                high--; //so 2 is exactly at high+1
            
        }
    }
}

int main(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine rng(seed);
    // Test 1: Normal mix
vector<int> test1 = {2, 0, 2, 1, 1, 0};
dnf(test1);

// Test 2: Already sorted
vector<int> test2 = {0, 0, 1, 1, 2, 2};
dnf(test2);

// Test 3: Reverse sorted
vector<int> test3 = {2, 2, 1, 1, 0, 0};
dnf(test3);

// Edge 1: All 0s
vector<int> edge1 = {0, 0, 0, 0, 0};
dnf(edge1);

// Edge 2: All 1s
vector<int> edge2 = {1, 1, 1, 1};
dnf(edge2);

// Edge 3: All 2s
vector<int> edge3 = {2, 2, 2};
dnf(edge3);

// Edge 4: Single element
vector<int> edge4 = {1};
dnf(edge4);

// Edge 5: Empty array
vector<int> edge5 = {};
dnf(edge5);

// Stress 1: 1e5 elements evenly balanced
vector<int> stress1(33333, 0);
stress1.insert(stress1.end(), 33334, 1);
stress1.insert(stress1.end(), 33333, 2);
shuffle(stress1.begin(), stress1.end(),rng);
dnf(stress1);

// Stress 2: 1e5 elements skewed (more 2s)
vector<int> stress2(20000, 0);
stress2.insert(stress2.end(), 20000, 1);
stress2.insert(stress2.end(), 60000, 2);
shuffle(stress2.begin(), stress2.end(), rng);
dnf(stress2);

}