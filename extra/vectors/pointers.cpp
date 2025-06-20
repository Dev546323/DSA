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


    int *null = nullptr; // holds the value 0, but unusable and cannot be dereferenced 
    cout<<null<<endl;

    ptr++; //pointer addition, it adds memory into the pointer equal to the pointer type (here it will add 4 bytes of mem)
    ptr-1; //subtraction  can be any number, number works the same way. p-2 = -8 bytes of data

    int arr1[] = {12, 7, 25, 3, 18, 42, 9, 31};
    int arr2[] = {5, 18, 22, 7, 13, 42, 56, 3,5,3};

    cout<<arr2-&arr2[3]<<endl; //basically subtracting index, there is space to save 3 integers  bettween arr[0] and arr[3]
     //
}