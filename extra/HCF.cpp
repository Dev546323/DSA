#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int brute(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return max(a, b); // GCD(0, b) = b

    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return -1; // Should never hit this with positive inputs
}
 
int euclid(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return max(a, b); // GCD(0, b) = b

    while (b != 0 or a != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
        if (a == b or a == 0 or b == 0) {
            return max(a, b); // GCD found
        }
    }
    return a; // GCD is now in 'a'
}

int LCM (int a, int b){ //LCM = (a*b)/HCF
    a = abs(a);
    b = abs(b);
   
    return (a * b) / euclid(a, b);
}

int main() {
    int a1 = 10,      b1 = 15;       // GCD = 5
    int a2 = 100,     b2 = 25;       // GCD = 25
    int a3 = 17,      b3 = 13;       // GCD = 1 (both primes)
    int a4 = 0,       b4 = 50;       // GCD = 50 (one zero)
    int a5 = 50,      b5 = 0;        // GCD = 50 (other zero)
    int a6 = 0,       b6 = 0;        // GCD = 0 or undefined (edge case)
    int a7 = -20,     b7 = 30;       // GCD = 10 (negative input)
    int a8 = 270,     b8 = 192;      // GCD = 6 (Euclid’s case)
    int a9 = 123456,  b9 = 789012;   // GCD = 12 (stress test)
    int a10 = 1000000, b10 = 1000000; // GCD = 1000000 (same large numbers)

    using namespace std::chrono;
    auto start_brute = high_resolution_clock::now();
    cout << "brute(" << a1 << ", " << b1 << ") = " << brute(a1, b1) << endl;
    cout << "brute(" << a2 << ", " << b2 << ") = " << brute(a2, b2) << endl;
    cout << "brute(" << a3 << ", " << b3 << ") = " << brute(a3, b3) << endl;
    cout << "brute(" << a4 << ", " << b4 << ") = " << brute(a4, b4) << endl;
    cout << "brute(" << a5 << ", " << b5 << ") = " << brute(a5, b5) << endl;
    cout << "brute(" << a6 << ", " << b6 << ") = " << brute(a6, b6) << endl;
    cout << "brute(" << a7 << ", " << b7 << ") = " << brute(a7, b7) << endl;
    cout << "brute(" << a8 << ", " << b8 << ") = " << brute(a8, b8) << endl;
    cout << "brute(" << a9 << ", " << b9 << ") = " << brute(a9, b9) << endl;
    cout << "brute(" << a10 << ", " << b10 << ") = " << brute(a10, b10) << endl;
    auto end_brute = high_resolution_clock::now();
    auto duration_brute = duration_cast<microseconds>(end_brute - start_brute);
    cout << "Time taken by brute: " << duration_brute.count() << " microseconds" << endl;

    auto start_euclid = high_resolution_clock::now();
    cout << "euclid(" << a1 << ", " << b1 << ") = " << euclid(a1, b1) << endl;
    cout << "euclid(" << a2 << ", " << b2 << ") = " << euclid(a2, b2) << endl;
    cout << "euclid(" << a3 << ", " << b3 << ") = " << euclid(a3, b3) << endl;
    cout << "euclid(" << a4 << ", " << b4 << ") = " << euclid(a4, b4) << endl;
    cout << "euclid(" << a5 << ", " << b5 << ") = " << euclid(a5, b5) << endl;
    cout << "euclid(" << a6 << ", " << b6 << ") = " << euclid(a6, b6) << endl;
    cout << "euclid(" << a7 << ", " << b7 << ") = " << euclid(a7, b7) << endl;
    cout << "euclid(" << a8 << ", " << b8 << ") = " << euclid(a8, b8) << endl;
    cout << "euclid(" << a9 << ", " << b9 << ") = " << euclid(a9, b9) << endl;
    cout << "euclid(" << a10 << ", " << b10 << ") = " << euclid(a10, b10) << endl;
    auto end_euclid = high_resolution_clock::now();
    auto duration_euclid = duration_cast<microseconds>(end_euclid - start_euclid);
    cout << "Time taken by euclid: " << duration_euclid.count() << " microseconds" << endl;

    

    return 0;
}