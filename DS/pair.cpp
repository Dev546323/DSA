#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main(){

    pair<int,int> p ={1,2}; 
    pair<int,char> p1 ={1,'a'}; //can use any data type
    pair<int,pair<int,int>> p2 = {1,{2,3}}; //pair inside a pair

    vector<pair<int,pair<int,int>>> v={{1,{2,3}},{4,{5,6}},{7,{8,9}}}; //vector of pairs

    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl<<endl; //accessing the pair inside a pair

    for(auto i:v){ 
        cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
    }
}