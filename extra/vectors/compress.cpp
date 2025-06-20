#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<string>

int compress(vector<char>& chars) {
        int n = chars.size();


        for(int i=0;i<n;){
            int count =0;
            char j=chars[i];
            vector<char> temp;

            while(i<n and j==chars[i]){
                count++;
                i++;
            }
                       while(count>0){
                temp.push_back(('0'+count%10));
                count /=10;
            }
                        chars.push_back(j);

            for(int x=temp.size()-1;x>=0;x--){
            if(temp.size()==1 and temp[0]=='1'){
                continue;
            } 
            chars.push_back(temp[x]);
            }

        }
        chars.erase(chars.begin(),chars.begin()+n);
        print<char> p(chars);
        cout<<endl;
        return chars.size();
    }

using namespace std;

int main() {
    #include <vector>
using namespace std;

vector<char> vec1 = {'a','a','b','b','c','c','c'};                  // Standard compression case
vector<char> vec2 = {'a','b','c'};                                  // No compression, all unique
vector<char> vec3 = {'a','a','a','a','a','a','a','a','a','a','a'};  // Single char, count = 11
vector<char> vec4 = {};                                             // Empty input (edge case)
vector<char> vec5 = {'x','x','y','y'};                               // Multiple groups, same count
vector<char> vec6 = {'a','a','b','c','c','c','d'};                   // Mix of single and multiple
vector<char> vec7 = {'z','z','z','z','z','z','z','z','z'};           // Count = 9, single digit
vector<char> vec8 = {'m','m','m','m','m','m','m','m','m','m','m'};   // Count = 11, double-digit
vector<char> vec9 = {'a','b','a','b','a','b'};                       // Alternating pattern, no compression
vector<char> vec10(10000, 'x');                                     // Stress test: 10,000 same characters

compress(vec1);
compress(vec2);
compress(vec3);
compress(vec4);
compress(vec5);
compress(vec6);
compress(vec7);
compress(vec8);
compress(vec9);
compress(vec10);
    return 0;
}