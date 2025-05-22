#include<iostream>
#include<vector>

using  namespace std;

int efficient(int base, int power){
    int result =1;
    if(power<0){
        power*=-1;
        base=1/base;
    }
    while(power>0){
        if(power%2==1){
            result*=base;
        }
        base *=base;
        power/=2;
    }
    return result; 

}

int main(){

    cout<<efficient(5,26)<<endl;
}