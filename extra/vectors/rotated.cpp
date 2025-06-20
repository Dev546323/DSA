#include<iostream>
#include<vector>

using namespace std; 
//modified binary search. 
//one side of the array will always be sorted in a rotated error

int search(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) return mid;

        // Check if the left half is sorted
        if (arr[start] <= arr[mid]) {
            // Now check if target lies within this sorted left half
            if (arr[start] <= target && target < arr[mid]) {
                // Target is in the sorted left half
                end = mid - 1;
            } else {
                // Target is not in the sorted left half, search in the right half
                start = mid + 1;
            }
        }
        // If left half isn't sorted, then right half must be sorted
        else {
            // Check if target lies within the sorted right half
            if (arr[mid] < target && target <= arr[end]) {
                // Target is in the sorted right half
                start = mid + 1;
            } else {
                // Target is not in the sorted right half, search in the left half
                end = mid - 1;
            }
        }
    }

    return -1; // Target not found
}


int main(){
    vector <int> test ={4,5,6,7,0,1,2};
    int target = 6;
    cout<<search(test, target)<<endl;
}