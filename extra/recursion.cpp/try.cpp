#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>


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

bool palindrom(string str, int start = 0, int end = -1){
    if(end == -1) {
        end = str.length() - 1; // Initialize end on first call
    }
    if (start >= end) {
        return true; // Base case: if start index meets or exceeds end index, it's a palindrome
    }
    if (str[start] != str[end]) {
        return false; // If characters at start and end don't match, it's not a palindrome
    }
    return palindrom(str, start + 1, end - 1); // Recursive call
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
    string str = "Hello, World!";
    
  
    
    return 0;
}