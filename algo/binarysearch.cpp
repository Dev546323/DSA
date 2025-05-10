#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int linearsearch (vector<int> arr, int target){ //linear search, we travese the entire array to find out target 
    for(int i=0;i<arr.size();i++){
        if (arr[i]==target) return i;
    }
}

int binarysearch (vector<int> arr, int target) {//CAN only be applied on SORTED arrays. 
    int start = 0; 
    int end = arr.size() -1; 
    while (start<=end){
        int mid = start+(end-start)/2;// the end - start is to prevent integer overflow
        if (target==arr[mid]) return mid;

        if(target<arr[mid]){
            end=mid-1;
        }
        else start=mid+1;
        if (target==arr[mid]) return mid;
    }
    return -1; 
}   