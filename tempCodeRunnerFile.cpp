#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

// Your recursive palindrome function
bool palindrom(string str, int start = 0, int end = -1){
    if(end == -1) {
        end = str.length() - 1;
    }
    if (start >= end) {
        return true;
    }
    if(!isalnum(str[start])){
        return palindrom(str, start + 1, end );
    }
    else if(!isalnum(str[end])){
        return palindrom(str, start, end - 1);
    }
    if(tolower(str[start]) != tolower(str[end])){
        return false;
    }
    return palindrom(str, start + 1, end - 1);
}

// Your iterative palindrome function
bool isPalindrome(string str){
    int start = 0;
    int end = str.length() - 1;
    while(start <= end){
        if(!isalnum(str[start])){
            start++;
            continue;
        }
        else if(!isalnum(str[end])){
            end--;
            continue;
        }
        if(tolower(str[start]) != tolower(str[end])){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Generates a massive palindrome with non-alphanumeric noise
string generateStressPalindrome(size_t size) {
    string half;
    for (size_t i = 0; i < size / 2; ++i) {
        char c = 'a' + (i % 26);
        half += (i % 11 == 0) ? '@' : c;  // sprinkle non-alnum
    }

    string full = half;
    if (size % 2 != 0) full += 'Z';  // center character for odd lengths

    reverse(half.begin(), half.end());
    full += half;

    return full;
}

int main() {
    size_t testSize = 1'000'0; // 1 million characters
    string test = generateStressPalindrome(testSize);

    // Test recursive
    auto start1 = chrono::high_resolution_clock::now();
    bool recResult = palindrom(test);
    auto end1 = chrono::high_resolution_clock::now();
    cout << "Recursive: " << (recResult ? "true" : "false") << endl;
    cout << "Recursive time: " << chrono::duration<double, milli>(end1 - start1).count() << " ms\n";

    // Test iterative
    auto start2 = chrono::high_resolution_clock::now();
    bool iterResult = isPalindrome(test);
    auto end2 = chrono::high_resolution_clock::now();
    cout << "Iterative: " << (iterResult ? "true" : "false") << endl;
    cout << "Iterative time: " << chrono::duration<double, milli>(end2 - start2).count() << " ms\n";

    return 0;
}
