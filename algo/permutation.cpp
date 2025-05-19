//find lexicographically next permutation

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<numeric>

using namespace std;

/*
1- pivot is exactly where A[I]< A[I+1]
2- find the element "just" greater than pivot on  the right side.  swap it with pivot
3- create the smallest combination of the elements on the right side of pivot (basically reverse the elements)
4- return the new array
*/
void print(vector<int> &arr){
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
void permutaion(vector<int> &arr){
    int n = arr.size();
    int pivot = -1;
    for(int i=n-2;i>=0;i--){ //starting a backwards array, since last element does not have a i+1 we start  i with n-2
        if(arr[i]<arr[i+1]){
            pivot = i;
            break; //break because we only need the first pivot
        }
    }
    if(pivot == -1){
        reverse(arr.begin(),arr.end()); //if no pivot is found, it means we are at the last permutation, so we sort the array
          if(n>200) return;
        print(arr);
        return;
    }

    for(int i=n-1;i>=0;i--){ 
        if(arr[i]>arr[pivot]){ //find the first element greater than pivot
            swap(arr[i],arr[pivot]);
            break;
        }
    }
  reverse(arr.begin()+pivot+1,arr.end()); //sort the elements after the pivot
    if(n>200) return;
    print(arr); 
}

int main(){
    // ✅ Test Case 1: Normal Case
vector<int> test1 = {1, 2, 3}; 
// Expected: {1, 3, 2}
permutaion(test1);

// ✅ Test Case 2: Last Permutation (Reversed)
vector<int> test2 = {3, 2, 1}; 
// Expected: {1, 2, 3}
permutaion(test2);

// ✅ Test Case 3: With Duplicates
vector<int> test3 = {1, 1, 5}; 
// Expected: {1, 5, 1}
permutaion(test3);

// ✅ Test Case 4: Single Element
vector<int> test4 = {42}; 
// Expected: {42} (unchanged)
permutaion(test4);

// ✅ Test Case 5: Two Elements Already Maxed
vector<int> test5 = {9, 8}; 
// Expected: {8, 9}
permutaion(test5);

// ✅ Test Case 6: Middle Lexicographic Perm
vector<int> test6 = {1, 3, 2}; 
// Expected: {2, 1, 3}
permutaion(test6);

// ✅ Test Case 7: All Elements Equal
vector<int> test7 = {7, 7, 7}; 
// Expected: {7, 7, 7}
permutaion(test7);

// ✅ Test Case 8: Larger Set
vector<int> test8 = {1, 2, 3, 6, 5, 4}; 
// Expected: {1, 2, 4, 3, 5, 6}
permutaion(test8);

// ✅ Test Case 9: Stress Test - Sorted 1 to 1000
vector<int> test9(1000);
iota(test9.begin(), test9.end(), 1);
// Expected: Will mutate to next lexicographic (just swaps last two)
permutaion(test9);

// ✅ Test Case 10: Stress Test - Already Last Permutation
vector<int> test10(1000);
iota(test10.begin(), test10.end(), 1);
reverse(test10.begin(), test10.end());
// Expected: Becomes sorted in ascending (1 to 1000)
permutaion(test10);

}