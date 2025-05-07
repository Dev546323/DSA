//time complexity is the amount of time taken based on the input size. (general formula of time taken based on n(input size))
//the actual time is varaible as input sizes can vary. 

#include<iostream>
#include<vector>
using namespace std;

//linear search  O(n)
int linear(vector<int> arr, int target){
    for(int i:arr){
        if(i==target) return i; //can return index if i use index
    }
}
//this function would take a linear time complexity, i.e the time increases linearly with the input size. 


//constant time complexity.
void constant(int &a, int &b){
    int c=a;
    a=b;
    b=c;

}
//time complexity irrespective of input size. 


//O(logn) this is a good time complexity
//it is very close to constant complexity but considered very good.
//binary search 


//O(nlogn) less than n^2 decent enough complexity
//optimized sort algos use this complexity. 




//quadratic time complexity. 
//loop in a loop increases time complexity n^number of loop in loop
vector<int> quadratic (vector<int> arr, int target){
    vector<int> returna;
    int size = arr.size()-1;
    for(int i=0;i<=size;i++){
        for(int j=i+1;j<=size;j++){
            if(i==j) continue;
            if(arr[i]+arr[j]==target){
                returna.push_back(i);
                returna.push_back(j);
            }
        }
    }
    return returna;
}
//not a very good time complexity as it increases quadratically with the input size. 


//cubic time complexity. 
//really not good. 
void cubic(int a[], int b){
    for(int i=0;i<b;i++){ //array from start to end
  
        for(int j=i;j<b;j++){ //array from the index to remaining
            int sum=0;
           
            for(int k=i;k<=j;k++){ // between index and remaining 
                cout<<a[k];
                sum+=a[k];
            
            }
            cout<<"-"<<sum<<"  ";
        }
        cout<<endl;
    }

}

//2^n complexity, second to worst time complexity. generally found amongst recursion. 

//n! n factorial complexity. the worst time complexity. also found amongst recursion. 






int main(){
    
}
