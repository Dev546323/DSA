#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>

string reversewords (string s){
    string ans;
    reverse(s.begin(), s.end());
    for(int i =0;i<s.length();i++){
        string word;
                if(s[i]==' ') continue; //to remove extra spaces    
                

        while(s[i]!=' '&& s[i]!='\0'){
            word+=s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        ans+=' '+ word;
        
    }
    return ans.substr(1);
}

using namespace std;

int main() {

    return 0;
}