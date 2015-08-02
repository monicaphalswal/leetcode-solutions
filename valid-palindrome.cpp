/**
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
    For example,
    "A man, a plan, a canal: Panama" is a palindrome.
    "race a car" is not a palindrome.

    Note:
    Have you consider that the string might be empty? This is a good question to ask during an interview.

    For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

bool isPalindrome(string s) {
    int len=s.length();
    int i=0, h=len-1;
    while(i<h){
        while(!isalnum(s[i]) && i<h) i++;
        while(!isalnum(s[h]) && i<h) h--;
        if(tolower(s[i]) != tolower(s[h])) return false;
        i++;
        h--;
    }
    return true;
}

int main(){
    assert(isPalindrome("")==1);
    assert(isPalindrome("A man, a plan, a canal: Panama")==1);
    assert(isPalindrome("race a car")==0);
    return 0;
}


