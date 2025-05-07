#include<iostream>
#include<climits>
using namespace std;

void subarray(int a[], int b){
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

int maxs(int a[], int size) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for(int i = 0; i < size; i++) {
        current_sum += a[i];
        if(current_sum > max_sum)
            max_sum = current_sum;
        if(current_sum < 0)
            current_sum = 0;
    }
    return max_sum;
}

int main(){
   int array[]={5,8,95,3,3,45,7,89,5,6,9,78,4,5,32,8,5,2,544,5,52,6};
   int array1[]={1,2,3,4,5,6,7};
   int size= sizeof(array)/sizeof(array[0]); 
   int size1= sizeof(array1)/sizeof(array1[0]);

    subarray(array1,size1);
    // int l= maxs(array1,size1);
    cout<<maxs(array1,size1)<<endl;
   

}