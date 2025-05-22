#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {

    char str[] = "Hello World \n";
   print<string> p{(string)str};

   char str1[200];
  // cin.getline(str1, 200,'\n');
  
  //ignores input after character limit. 
   //(variable name, character limit, delimiter), delimiter is optional
   // dilimiter is used to stop reading input at a specific character default specified is '\n'
   //don't increase limit more than array size, it will kill the program

    string str2 = "KILL MEEEEEEEEEEEE!";
    
    string str3 = str + str2; //concatenation
    print<string> p3{str3};

    cout << boolalpha << "Equal??" << (str == str2) << endl; 
    cout<< "greater than??" << (str > str2) << endl; //checks lexicographical order
    cout<< "less than??" << (str < str2) << endl;
    return 0;
}