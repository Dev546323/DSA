#include<iostream>
#include<vector>
using namespace std;

vector<int> brute(vector<int> arr){
    vector<int> returnw(arr.size(),1);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(i==j) continue;
            returnw[i]*=arr[j];
        }
    }
    return returnw;
}

vector<int> optimized(vector<int> arr){
    vector<int> prefix(arr.size(),1);
    vector<int> suffix(arr.size(),1);
    vector<int> returnw(arr.size(),1);
    int size=arr.size()-1;
    for(int i=1;i<=size;i++){
        prefix[i]*=prefix[i-1]*arr[i-1]; //product of array before i
    }
    for(int i=size-1;i>=0;i--){
        suffix[i]*=suffix[i+1]*arr[i+1]; //product of array after i
    }
    for(int i=0;i<=size;i++){
        returnw[i]=prefix[i]*suffix[i]; //product of array before i * after i
    }
    return returnw;
}
vector<long long> optimal(vector<int> arr){
  
    vector<long long> returnw(arr.size(),1);
    int size=arr.size()-1;
    for(int i=1;i<=size;i++){
        returnw[i]*=returnw[i-1]*arr[i-1]; //prefix calculation directly into return array
    }
    int suffix=1;
    for(int i=size-1;i>=0;i--){
        suffix*=arr[i+1]; //suffix variable as int, to maintain cumulative nature. 
        //variable needed because array now has the prefix values already baked in, can't use the array to cumulate the value like i did with prefix. 
        returnw [i]*=suffix;
    }
   
    return returnw;
}


int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    vector<long long>ans = optimal(arr);
    for(int i:ans){
        cout<<i<<" ";
    }

}