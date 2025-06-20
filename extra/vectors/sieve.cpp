#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
using namespace std;

//sieve of Eratosthenes

 int countPrimes(int n) { 
        vector<bool> check(n , true); //all values in range are started as true
        int ans= 1; //because i'm iterating over 2
        if(n==0 or n==1 or n==2 ) return 0; //edge case, faster output
        for(int i=3;i<n;i++) //loop to traverse range
        {
            if(i%2==0) { //because i'm skipping 2, potentially faster
                check[i] = false;
            continue;
            }
            if(check[i]==true){ // prime number check
                ans++;
            
            for(int j=i*2;j<n;j+=i){ //discards all multiples of prime. 

                check[j] =false;
            }
        }
        }
        return ans; 

    }


int main() {
    int n1 = 2;
    int n2 = 1;
    int n3 = 10;
    int n4 = 13;
    int n5 = 19;
    int n6 = 50;
    int n7 = 100;
    int n8 = 30;
    int n9 = 0;
    int n10 = 1e6;

    cout << "countPrimes(" << n1 << ") = " << countPrimes(n1) << endl;
    cout << "countPrimes(" << n2 << ") = " << countPrimes(n2) << endl;
    cout << "countPrimes(" << n3 << ") = " << countPrimes(n3) << endl;
    cout << "countPrimes(" << n4 << ") = " << countPrimes(n4) << endl;
    cout << "countPrimes(" << n5 << ") = " << countPrimes(n5) << endl;
    cout << "countPrimes(" << n6 << ") = " << countPrimes(n6) << endl;
    cout << "countPrimes(" << n7 << ") = " << countPrimes(n7) << endl;
    cout << "countPrimes(" << n8 << ") = " << countPrimes(n8) << endl;
    cout << "countPrimes(" << n9 << ") = " << countPrimes(n9) << endl;
    // For large n10, just print the count (avoid printing all primes)
    cout << "countPrimes(" << n10 << ") = " << countPrimes(n10) << endl;

    return 0;
}