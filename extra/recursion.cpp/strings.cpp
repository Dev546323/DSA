#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include <string>

using namespace std;

bool isVowel(char c) {
    char lowerC = tolower(c);
    return (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u');
}
int vowel(string str, int start=0, int end=-1) {
    if (end == -1) {
        end = str.length() - 1; // Initialize end on first call
    }
    if (start > end) {
        return 0; // Base case: if start index exceeds end index, return 0
    }
    
    if(isVowel(str[start])) {
        return 1 + vowel(str, start + 1, end); 
    }
    else if(isVowel(str[end])) {
        return 1 + vowel(str, start, end - 1);
       }
    else {
        return  vowel(str, start + 1, end - 1); // Recursive call
    }
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

void reverse(string &str, int start = 0, int end = -1){
    if(end == -1) {
        end = str.length() - 1; // Initialize end on first call
    }
    if (start >= end) {
        return; // Base case: if start index meets or exceeds end index, return
    }
    
    swap(str[start], str[end]); // Swap characters at start and end
    reverse(str, start + 1, end - 1); // Recursive call
}

void uppercase(string &str, int index = 0) {
    if (index >= str.length()) {
        return; // Base case: if index exceeds string length, return
    }
    
        str[index] = toupper(str[index]); 
    
    
    uppercase(str, index + 1); // Recursive call
}

int main() {
    string str = "Hello, World! This is a test string with vowels.";
    int vowelCount = vowel(str);
    cout << "Number of vowels in the string: " << vowelCount << endl;
    reverse(str);
    cout << "Reversed string: " << str << endl;
    reverse(str); 

    //uppercase(str);
    //cout << "Uppercase string: " << str << endl;
    
    return 0;
}