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

void print(vector<int> &v){ 
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void iterator(vector<int> &v){ 
   vector<int> ::iterator it; //pointer to the vector

    for(it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl; 
}

int main(){
    vector<int> vec;//vector class of <int> type named vec 
    vec ={1,2,3}; //can be declared completely array like 
    vector<int> vec1(5,10); //vector of size 5, with all values as 10.
    vector<int> vec2{1,2,3,4,5,6,7,8}; 
    vector<int> vec3(vec2); //copy constructor, copies the values of vec2 into vec3.
    
    for(int i:vec){}// vector works with range based loops. 
    //i becomes the variable. 

    cout<<vec.size()<<endl; //size function included in  header 
    vec.push_back(4); //adds a vector in the end. 
     print(vec); 

    vec.pop_back(); //deletes the last variable.  
        cout<<"popback function"<<endl;
     print(vec); 

    cout<<vec.front()<<endl; //considers the first value
    cout<<vec.back()<<endl;// considers the last value
    cout<<vec.at(2)<<endl; //as the function suggests, value at index()
    
    //easy to consider the vector header as a class modifier. 
    cout<<vec.size(); //the amount of data it currently holds
    cout<<vec.capacity()<<endl; //the amount of data it can hold. 

    //for every varaible that is out of bounds at run time. the size of vector is doubled. 


    print(vec2);
    cout<<"erase function"<<endl;
    vec2.erase(vec2.begin()+1,vec2.begin()+3); //erase function, deletes the values from index 1 to 3.
    print(vec2);

    cout<<"insert function"<<endl;
    vec2.insert(vec2.begin()+1,2); //insert function, inserts 3 values of 100 at index 1.
     vec2.insert(vec2.begin()+3,3);
     vec2.insert(vec2.begin()+7,4,10); //4 values of 10 at index 7.
    print(vec2);
    cout<<endl;

    print(vec3);
    vec3.clear(); //clears the vector, but does not delete the memory allocated to it.
    print(vec3);
    cout<<vec3.capacity()<<endl;
    vec3.empty();// to check whether the vector is empty or not.
    
    cout<<*(vec.begin())<<endl; //returns the first iterator of the vector.
    cout<<*(vec.end())<<endl; //returns the last iterator of the vector. //points to the next value after the last value of the vector.
    //iterator can be considered as a pointer to the vector.
}