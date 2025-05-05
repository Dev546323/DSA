//consider vector as a dyanmic type array 
#include<iostream>
#include<vector>
using namespace std;


/*there are 2 types of mem allocation static and dynamic 
static mem is pre-defined at compile time, if i create a array of size 5, 4bytes*5 values= 20 bytes will be allocated 
to the array at compile time 
allocation @ stack 

whereas if i create a vector of 0 size, and add data into it, during run-time or post declaration. it will allocate the required mem 
at run time itself 
all run time mem allocation is @heap
*/
int main(){
    vector<int> vec;//vector class of <int> type named vec 
    vec ={1,2,3}; //can be declared completely array like 

    for(int i:vec){}// vector works with range based loops. 
    //i becomes the variable. 

    cout<<vec.size()<<endl; //size function included in  header 
    vec.push_back(4); //adds a vector in the end. 
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl; 
    vec.pop_back(); //deletes the last variable.    
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<vec.front()<<endl; //considers the first value
    cout<<vec.back()<<endl;// considers the last value
    cout<<vec.at(2)<<endl; //as the function suggests, value at index()
    
    //easy to consider the vector header as a class modifier. 
    cout<<vec.size(); //the amount of data it currently holds
    cout<<vec.capacity()<<endl; //the amount of data it can hold. 

    //for every varaible that is out of bounds at run time. the size of vector is doubled. 

}