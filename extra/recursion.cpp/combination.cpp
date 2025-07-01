#include "/home/yestodrugs/Desktop/DSA/print.h"

using namespace std;
void helper(vector<int> &arr, int target, vector<vector<int>>&s, vector<int> &current, int index) {
    if (target ==0) {
        s.push_back(current);
        return;
    }
    if ( index >= arr.size()or target < 0) {
        return;
    }
    current.push_back(arr[index]);
    // helper(arr,target-arr[index],s,current, index+1); "supposed inclusion line"
    //only produces duplicates. removing it only makes the diffeerence of removing duplicates

    helper(arr,target-arr[index],s,current, index); //multiple inclusion
        current.pop_back();
    helper(arr,target,s,current, index+1); //exclusion


}


void combination(vector<int> &arr, int target){
    vector<vector<int>>s;
    vector<int> current;
    int sum = 0;
    int index=0;

    helper(arr,target,s,current,index);
    
   print <vector<vector<int>>> p(s);
}


int main() {
    vector<int> arr = {2,3,6,7};
    int target = 17;

    combination(arr, target);
    return 0;
}