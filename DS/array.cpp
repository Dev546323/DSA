#include<iostream>
using namespace std;


//array name is implicitly a pointer. 

//search target. 
int search(int n[], int i){ //linear search 
    int target=7;
    for(int x=0;x<i;x++){
        if(n[x]==target){
            return x+1;
            
        }
    }
     return -1;
}

void swap (int n[], int i){
    int temp{};
    for(int x=0;x<i/2;x++){
        temp=n[x];
        n[x]=n[i-x-1];
        n[i-x-1]=temp;

    }
}
int main(){
   int array[]={5,8,95,3,3,45,7,89,5,6,9,78,4,5,32,8,5,2,544,5,52,6};
    cout<<"First instance of finding the target value is @ "<<search(array,(sizeof(array)/sizeof(array[0])))<<"th position"<<endl;

    swap(array,(sizeof(array)/sizeof(array[0])));
    for(int i=0;i<(sizeof(array)/sizeof(array[0]));i++){
        cout<<array[i]<<" ";
    }

}