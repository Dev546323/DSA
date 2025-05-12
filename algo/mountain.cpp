#include<iostream>
#include <vector>

using namespace std;

int index(vector<int> arr){
    int start=0; 
    int end = arr.size()-1;
    int mid;
    
    while (start<=end){
        mid = start + (end-start)/2;
        if(arr[mid]>=arr[mid-1]and arr[mid]>=arr[mid+1]) return mid;

        if(arr[mid]>=arr[mid-1]){
            start=mid+1;
        }
        else end=mid;
    }
    return mid;
}
int main(){
    vector<int> mountain = {2, 5, 8, 10, 7, 4};
    cout<<index(mountain)<<endl;

    vector<int> mountain_min = {1, 3, 2};                // Peak at index 1 (smallest valid mountain)
vector<int> mountain_left_peak = {1, 2, 3, 4, 3};    // Peak closer to right, index 3
vector<int> mountain_right_skewed = {1, 5, 9, 11, 13, 10, 6}; // Peak at index 4
vector<int> mountain_far_peak = {1, 3, 5, 7, 9, 8, 6, 2};     // Peak at index 4
vector<int> mountain_big = [] {
    vector<int> v;
    for(int i = 1; i <= 100000; i++) v.push_back(i);
    for(int i = 99999; i >= 1; i--) v.push_back(i);
    return v;
}(); // Peak at index 99999

vector<int> not_mountain_decreasing = {5, 4, 3};     // Invalid: only decreasing
vector<int> not_mountain_increasing = {1, 2, 3};     // Invalid: only increasing
vector<int> not_mountain_flat_peak = {1, 3, 3, 2};   // Invalid: plateau
vector<int> not_mountain_duplicates = {1, 2, 2, 3, 2, 1}; // Invalid: duplicates before peak

cout<<index(mountain_min) <<endl;
cout<<index(mountain_left_peak) <<endl;
cout<<index(mountain_right_skewed) <<endl;
cout<<index(mountain_far_peak) <<endl;
cout<<index(not_mountain_decreasing) <<endl;
cout<<index(not_mountain_increasing) <<endl;
cout<<index(not_mountain_flat_peak) <<endl;
cout<<index(not_mountain_duplicates) <<endl;
cout<<index(mountain_big) <<endl;

}