#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>


using namespace std;

int fibo (int n){
    if(n-2==0 or n-1==0) return 1;
    return fibo(n-1) + fibo(n-2);
}

bool checksort(vector<int> arr){
    if(arr.size() <= 1) return true; 

    return arr[0] <= arr[1] && checksort(vector<int>(arr.begin() + 1, arr.end()));
  
}

bool binarysearch(vector<int> arr, int target){
    auto mid = arr.begin() + arr.size()/2;
    if(arr.size() == 0) return false; 
    if(*mid == target or *arr.begin()==target or *(arr.end()-1)==target) return true;
    if(*mid < target) {
        return binarysearch(vector<int>(mid + 1, arr.end()), target);
    } else {
        return binarysearch(vector<int>(arr.begin(), mid), target);
    }
}



int main() {
    cout<<fibo(13)<<endl;
    
    vector<int> arr1 = {1, 2, 3, 4};    // -1 (sorted)
vector<int> arr2 = {1, 3, 2};       // 0 (not sorted)

cout <<boolalpha<< checksort(arr1)<<endl;  // -1
cout << checksort(arr2)<<endl;  // 0

// Arrays
vector<int> v1 = {1, 3, 5, 7, 9};            // Normal case
vector<int> v2 = {2, 4, 6, 8, 10};           // Target not found
vector<int> v3 = {11, 22, 33, 44, 55};       // First element
vector<int> v4 = {5, 10, 15, 20};            // Last element
vector<int> v5 = {42};                       // Single element match
vector<int> v6 = {99};                       // Single element no match
vector<int> v7 = {};                         // Empty array
vector<int> v9 = {2, 4, 4, 4, 6, 8};         // Duplicate elements
vector<int> v10 = {-10, -5, 0, 3, 9};        // Negative numbers

// Filling large array for stress test

// Targets
int t1 = 5;          // Should return 2 from v1
int t2 = 7;          // Not in v2, return -1
int t3 = 11;         // First element in v3, return 0
int t4 = 20;         // Last element in v4, return 3
int t5 = 42;         // Only element in v5, return 0
int t6 = 100;        // Not in v6, return -1
int t7 = 10;         // Empty array in v7, return -1
int t9 = 4;          // Multiple matches in v9, any index of 4 is okay
int t10 = -5;        // Return 1 from v10

cout<<"1 "<<boolalpha<<binarysearch(v1, t1)<<endl; // true
cout<<"2 "<<binarysearch(v2, t2)<<endl; // false
cout<<"3 "<<binarysearch(v3, t3)<<endl; // true
cout<<"4 "<<binarysearch(v4, t4)<<endl; // true
cout<<"5 "<<binarysearch(v5, t5)<<endl; // true
cout<<"6 "<<binarysearch(v6, t6)<<endl; // false  
cout<<"7 "<<binarysearch(v7, t7)<<endl; // false
cout<<"9 "<<binarysearch(v9, t9)<<endl; // true (any index of 4)
cout<<"10 "<<binarysearch(v10, t10)<<endl; // true (index 1)


    return 0;
}