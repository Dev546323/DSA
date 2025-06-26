#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>


using namespace std;

void test(int n){
    if(n<=0){
        cout<<endl;
        return;
    }
    if(n%2 !=0){
        n-=1;
    }
    cout << n << " ";
    test(n-2);
    cout << n << " ";
}
int factorial(int n) {
   if (n <= 1) {
        return 1;
    }

    return n* factorial(n - 1);

}
int power(int base, int exp){
    if(exp == 0){
  return 1;       
    }
    return base * power(base, exp - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b); //follows Euclid's algorithm 
    // look carefully the numbers gets swapped every call. making sure a is always greater than b
}

int mini(int arr[], int n){
    if(n == 1){
        return arr[0];
    }
    return min(arr[n-1], mini(arr, n - 1));
}

int main() {

    test(25);
    cout<< "\nFactorial: "<<factorial(13)<<endl;
    cout<< "\nPower: "<<power(2, 10)<<endl;
    cout<< "\nFibonacci: "<<fibonacci(10)<<endl;

        int a1 = 10,      b1 = 15;       // GCD = 5
    int a2 = 100,     b2 = 25;       // GCD = 25
    int a3 = 17,      b3 = 13;       // GCD = 1 (both primes)

    cout << "\nGCD(" << a1 << ", " << b1 << ") = " << GCD(a1, b1) << endl;
    cout << "GCD(" << a2 << ", " << b2 << ") = " << GCD(a2, b2) << endl;
    cout << "GCD(" << a3 << ", " << b3 << ") = " << GCD(a3, b3) << endl;
  
    
    return 0;
}