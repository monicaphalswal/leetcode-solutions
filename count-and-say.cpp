/**
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...

    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back
string gen(string s){
    string ans;
    int c=1;
    int len=s.length();
    for(int i=1; i<len; i++){
        if(s[i]!=s[i-1]){
            ans+=to_string(c);
            ans+=s[i-1];
            c=1;
        }
        else c++;
    }
    ans+=to_string(c);
    ans+=s[len-1];
    return ans;
}

string countAndSay(int n) {
    if(n==0) return "";
    if(n==1) return "1";
    string ans="1";
    for(int i=1; i<n; i++) ans=gen(ans);
    return ans;
}

int main(){
    assert(countAndSay(0)=="");
    assert(countAndSay(1)=="1");
    assert(countAndSay(2)=="11");
    assert(countAndSay(3)=="21");
    assert(countAndSay(4)=="1211");
    assert(countAndSay(5)=="111221");
    assert(countAndSay(6)=="312211");
    assert(countAndSay(7)=="13112221");
    return 0;
}


