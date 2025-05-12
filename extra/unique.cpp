#include<iostream>
#include<vector>

using namespace std; 

int unique(vector<int> arr){
    int start =0; 
    int end = arr.size()-1;
    while (start<=end){
        int mid = start + (end-start)/2;
        if (mid!=0 && mid!=arr.size()-1){
        if(arr[mid-1]!=arr[mid]&& arr[mid+1]!=arr[mid]) return arr[mid];
        }
        if (mid==0 && arr[mid]!=arr[mid+1]) return arr[mid];
        if (mid == arr.size()-1 && arr[mid]!=arr[mid-1]) return arr[mid];
        if(arr[mid-1]==arr[mid]){
            end=mid-1;
        }
        else start=mid+1;
    
    }
    return -1;
}


int main(){
    vector<int> arr ={1,1,2,3,3,4,4,8,8};
    cout<< unique(arr)<<endl;
}