#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a=234;
    int *ptr= &a;
    int **ptr1 = &ptr; // pointers to pointers
    int ***ptr2= &ptr1; // pointers to pointers 
    int ****ptr3 = &ptr2; // pointers to pointers 
    cout << &a << " ";
    cout << ptr <<endl;
    cout << &ptr << " "<< ptr1 << endl;
    cout << &ptr1 << " " << ptr2 <<endl;
    cout << &ptr2 << " " << ptr3 <<endl; 
    cout << &ptr3 <<endl; 
    cout<< *ptr3 << " " << *ptr2 << " " << *ptr1 << " " << *ptr << endl; /*dereferncing a pointer removes 2 layers, it access the data in the variable whose address is saved
    * ptr1 removes the address of the ptr and access the data inside ptr, which is the mem addy of a. 
     think of it as value at operator. */
     
    cout<<**ptr1<<endl; /*i can use multiple * to dereference the operator multiple times. 
    first '*' = value at mem addy saved by ptr1 = value at ptr 
    second '*' = value at mem addy saved at ptr. 
    can only use multiple dereferencing with pointer to pointer */
}