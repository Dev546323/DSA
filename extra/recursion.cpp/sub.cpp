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
    swap(arr[i], arr[j]);
    permutations(arr, permutation, i + 1);
    swap(arr[i], arr[j]); // backtrack to original state
  }
  return permutation;
} 

int main() {
    vector<int> arr = {1,2,3};
    vector<int> subset;
  printsubsets(arr, subset, 0);
    vector<vector<int>> permutation;

    permutations(arr, permutation, 0);
    print <vector<vector<int>>>p1 (permutation);

    return 0;
}