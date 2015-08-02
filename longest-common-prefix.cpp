/**
    Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0) return "";
    string ans="";
    int j=0;
    for(int i=0;; i++){
        int add=1;
        char key=strs[0][i];
        for(int j=0; j<strs.size(); j++){
            if(i>=strs[j].length()) return ans;
            if(strs[j][i]!=key) add=0;
        }
        if(add) ans+=key;
        else return ans;
    }
    return ans;
}

int main(){
    vector<string> strs = {"", "", ""};
    assert(longestCommonPrefix(strs)== "");
    strs = {};
    assert(longestCommonPrefix(strs)== "");
    strs = {"ajj", "", ""};
    assert(longestCommonPrefix(strs)== "");
    strs = {"pikachu", "pika", "piku"};
    assert(longestCommonPrefix(strs)== "pik");
    strs = {"pikachu", "pika", "piku", "p"};
    assert(longestCommonPrefix(strs)== "p");
    strs = {"pikachu", "pika", "piku", "b"};
    assert(longestCommonPrefix(strs)== "");
    strs = {"pikachu", "pik"};
    assert(longestCommonPrefix(strs)== "pik");
    strs = {"abca", "abc"};
    assert(longestCommonPrefix(strs)== "abc");

    return 0;
}


