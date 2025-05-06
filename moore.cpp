#include<iostream>
#include <vector>
using namespace std;

int moore (vector<int> a){
    int frequency{0};
    int num{};
    for(int i=0;i<a.size();i++){
        if(frequency==0){
            num=a[i];
        }
        if (num==a[i]){
            frequency++;
        }
        if (num!=a[i]){
            frequency--;
        }
    }

    
}

int main (){
    vector<int> arr = {3,2,5,4,6,2,5,2};
    cout<<endl<<moore(arr)<<endl;
}