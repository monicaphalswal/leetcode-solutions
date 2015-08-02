/**
    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.

    For example,
    Given s = "Hello World",
    return 5.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

int lengthOfLastWord(string s) {
    int len=s.length();
    if(!len) return 0;
    int j=len-1;
    while(j>=0){
        if(s[j]==' ') j--;
        else break;
    }
    if(j<0) return 0;
    int i=j;
    while(i>=0){
        if(s[i]!=' ') i--;
        else break;
    }

    return j-i;
}

int main(){
    assert(lengthOfLastWord("Hello World")== 5);
    assert(lengthOfLastWord("  Hello Worldi    ")== 6);
    assert(lengthOfLastWord("Wor")== 3);
    assert(lengthOfLastWord("Hell   ")== 4);
    assert(lengthOfLastWord("  Hell   ")== 4);
    assert(lengthOfLastWord("")== 0);
    assert(lengthOfLastWord("  Hell")== 4);
    assert(lengthOfLastWord("  ")== 0);
    return 0;
}


