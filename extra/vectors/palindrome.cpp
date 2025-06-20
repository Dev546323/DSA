#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>

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


    
    return 0;
}