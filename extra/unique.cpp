#include<iostream>
#include<vector>

using namespace std; 

int brute(vector<int> arr){
    int end = arr.size()-1;
        if(arr.size()==1) return arr[0]; //edge case single element only. 
    for(int i=1;i<end;i++){
        if(arr[i-1]!=arr[i] and arr[i]!=arr[i+1]) return arr[i];
    }
        if(arr[0]!=arr[1]) return arr[0]; //edge case, first element
        if(arr[end]!=arr[end-1]) return arr[end]; //edge case, last element. 
return -1;

}  

int optimize(vector<int> arr){
    int start=0; 
    int end=arr.size()-1;
    if(arr.size()==1) return arr[0];
    if( arr[0]!= arr[1]) return arr[0];
    if( arr[end]!= arr[end-1]) return arr[end];
    while (start<end){
        int mid = start + (end-start)/2;
        if(arr[mid-1]!=arr[mid] and arr[mid]!= arr[mid+1]) return arr[mid];

        if(mid%2==0){
            if(arr[mid]==arr[mid-1]) end=mid-1;
            else start=mid+1;
        }
        else {
            if(arr[mid]==arr[mid-1]){
                start=mid-1;
            }
            else end=mid+1; 
        }

    }
    return -1;
}


int main(){
    vector<int> arr ={3,3,7,7,10,11,11};
    vector<int> arr1 ={1, 1, 2, 2, 3};
    cout<< optimize(arr)<<endl;
    cout << "optimize({1, 1, 2, 2, 3}) = " << optimize(arr1) << endl;
cout << "optimize({0, 1, 1, 2, 2}) = " << optimize({0, 1, 1, 2, 2}) << endl;
cout << "optimize({1, 1, 3, 4, 4, 5, 5}) = " << optimize({1, 1, 3, 4, 4, 5, 5}) << endl;
cout << "optimize({11}) = " << optimize({11}) << endl;
cout << "optimize({1, 1, 2}) = " << optimize({1, 1, 2}) << endl;
cout << "optimize({1, 2, 2}) = " << optimize({1, 2, 2}) << endl;

// Stress test - unique at end
{
    vector<int> test;
    for (int i = 1; i <= 99999; i += 2) {
        test.push_back(i);
        test.push_back(i);
    }
    test.push_back(100001);
    cout << "optimize(stress_test_end) = " << optimize(test) << endl;
}

// Stress test - unique in middle
{
    vector<int> test;
    for (int i = 1; i <= 49999; i += 2) {
        test.push_back(i);
        test.push_back(i);
    }
    test.push_back(999999);
    for (int i = 50001; i <= 99999; i += 2) {
        test.push_back(i);
        test.push_back(i);
    }
    cout << "optimize(stress_test_middle) = " << optimize(test) << endl;
}

// Stress test - unique at start
{
    vector<int> test = {777};
    for (int i = 1; i <= 99999; i += 2) {
        test.push_back(i);
        test.push_back(i);
    }
    cout << "optimize(stress_test_start) = " << optimize(test) << endl;
}

}