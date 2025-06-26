#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include <chrono>
#include<string>

using namespace std;

bool palindrome(string str){
 int start =0;
 int end = str.length()-1;
  while(start<=end){
    if(!isalnum(str[start])){
        start++;
        continue;
    
    }
    else if(!isalnum(str[end])){
        end--;
        continue;
    }
    
    if(tolower(str[start])!=tolower(str[end])){
        return false;
    }
   
    start++;
    end--;
  }
      return true;

}

bool palindrom(string str, int start = 0, int end = -1){
    if(end == -1) {
        end = str.length() - 1; // Initialize end on first call
    }
    if (start >= end) {
        return true; // Base case: if start index meets or exceeds end index, it's a palindrome
    }
        if(!isalnum(str[start])){
        return palindrom(str, start + 1, end );
    }

    else if(!isalnum(str[end])){
        return palindrom(str, start, end - 1);
    }
    if(tolower(str[start])!=tolower(str[end])){
        return false; // If characters at start and end don't match, it's not a palindrome
    }
    return palindrom(str, start + 1, end - 1); // Recursive call
}


int main() {
    string str1 = "Was it a car or a cat I saw?";
string str2 = "A1b2B1a";
string str3 = "!!!???,,,,";
string str4 = "Madam, in Eden, I'm Adam";
string str5 = "   A   man     a   plan     a canal    Panama   ";

string str6 = "Was it a cat or a car I saw?";
string str7 = "A1b2C1a";
string str8 = "Racecar123";
string str9 = "AbBa";
string str10 = "été";

using namespace std::chrono;
    auto start_brute = high_resolution_clock::now();
    cout<<boolalpha<<"1"<<palindrome(str1)<<endl; //true
    cout<<boolalpha<<"2"<<palindrome(str2)<<endl; //true
    cout<<boolalpha<<"3"<<palindrome(str3)<<endl; //true
    cout<<boolalpha<<"4"<<palindrome(str4)<<endl; //true
    cout<<boolalpha<<"5"<<palindrome(str5)<<endl; //true
    cout<<boolalpha<<"6"<<palindrome(str6)<<endl; //false
    cout<<boolalpha<<"7"<<palindrome(str7)<<endl; //false
    cout<<boolalpha<<"8"<<palindrome(str8)<<endl; //true
    cout<<boolalpha<<"9"<<palindrome(str9)<<endl; //true
    cout<<boolalpha<<"10"<<palindrome(str10)<<endl; //true
      auto end_brute = high_resolution_clock::now();
    auto duration_brute = duration_cast<microseconds>(end_brute - start_brute);
    cout << "Time taken by brute: " << duration_brute.count() << " microseconds" << endl;

        auto start_test = high_resolution_clock::now();

    cout<<boolalpha<<"\n1"<<palindrom(str1)<<endl; //true
    cout<<boolalpha<<"2"<<palindrom(str2)<<endl; //true
    cout<<boolalpha<<"3"<<palindrom(str3)<<endl; //true
    cout<<boolalpha<<"4"<<palindrom(str4)<<endl; //true
    cout<<boolalpha<<"5"<<palindrom(str5)<<endl; //true
    cout<<boolalpha<<"6"<<palindrom(str6)<<endl; //false
    cout<<boolalpha<<"7"<<palindrom(str7)<<endl; //false
    cout<<boolalpha<<"8"<<palindrom(str8)<<endl; //true
    cout<<boolalpha<<"9"<<palindrom(str9)<<endl; //true
    cout<<boolalpha<<"10"<<palindrom(str10)<<endl; //true
    auto end_test = high_resolution_clock::now();
    auto duration_test = duration_cast<microseconds>(end_test - start_test);
    cout << "Time taken by test: " << duration_test.count() << " microseconds" << endl;


    
    return 0;
}