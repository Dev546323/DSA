#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>

using namespace std;

string duplicates(string s, string part){
      while(s.find(part)!= string::npos){
            s.erase(s.find(part),part.length());
        }
        return s;
}

int main() {
    string s1  = "daabcbaabcbc";    string part1  = "abc";     // Output: "dab"
string s2  = "axxxxyyyyb";      string part2  = "xy";      // Output: "ab"
string s3  = "aabbaabbaabba";   string part3  = "aab";     // Output: "ba"
string s4  = "ababab";          string part4  = "ab";      // Output: ""
string s5  = "aaaaa";           string part5  = "aa";      // Output: "a"
string s6  = "hellohello";      string part6  = "llo";     // Output: "hehe"
string s7  = "mississippi";     string part7  = "issi";    // Output: "msippi"
string s8  = "aaaaaa";          string part8  = "aaa";     // Output: ""
string s9  = "abcabcabcabc";    string part9  = "abc";     // Output: ""
string s10 = "abcde";           string part10 = "f";       // Output: "abcde" (no match)
 
    cout<<duplicates(s1, part1)<<endl; // Output: "dab"
    cout<<duplicates(s2, part2)<<endl; // Output: "ab"
    cout<<duplicates(s3, part3)<<endl; // Output: "ba"
    cout<<duplicates(s4, part4)<<endl; // Output: ""
    cout<<duplicates(s5, part5)<<endl; // Output: "a"
    cout<<duplicates(s6, part6)<<endl; // Output: "hehe"
    cout<<duplicates(s7, part7)<<endl; // Output: "msippi"
    cout<<duplicates(s8, part8)<<endl; // Output: ""
    cout<<duplicates(s9, part9)<<endl; // Output: ""
    cout<<duplicates(s10, part10)<<endl; // Output: "abcde" (no match)

    return 0;
}