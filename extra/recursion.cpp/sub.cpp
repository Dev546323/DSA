#include "/home/yestodrugs/Desktop/DSA/print.h"
using namespace std;

void printsubsets(vector<int>& arr, vector<int>& subset, int i) {
  if(i==arr.size()){
    print <int> p(subset);
    return;
  }
  //include the current element
    subset.push_back(arr[i]);

    printsubsets(arr, subset, i + 1);

    //exclude the current element
    subset.pop_back();

    int index = i+1;

    //only works for sorted arrays
    while(index < arr.size()){
        if(arr[index] == arr[i]) {
            index++;
        } else {
            break; // removes duplicates 
        }
    }
    printsubsets(arr, subset, index );
}

vector<vector<int>> permutations(vector<int>& arr, vector<vector<int>>& permutation, int i ){
  if (i >= arr.size()) {
    permutation.push_back(arr);
    return permutation;
  }
  for(int j=i;j<arr.size();j++){
    if ( i!=j and arr[i] == arr[j]) continue; // skip duplicates to avoid repeated permutations
    swap(arr[i], arr[j]); // swap to create a new permutation
    
    permutations(arr, permutation, i + 1);// recursively call for the next index

    swap(arr[i], arr[j]); // backtrack to original state
  }
  return permutation;
} 

int main() {
    vector<int> arr = {1,2,3,3};
    vector<int> subset;
  printsubsets(arr, subset, 0);
    vector<vector<int>> permutation;

    permutations(arr, permutation, 0);
    print <vector<vector<int>>>p1 (permutation);

    return 0;
}