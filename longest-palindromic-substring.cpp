/**
    Given a string S, find the longest palindromic substring in S.
    You may assume that the maximum length of S is 1000,
    and there exists one unique longest palindromic substring.
*/
#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int len=s.length();
    string ans="";
    int start=0, en=0;
    if(len==0) return ans;
    else if(len==1) return s;
    for(int i=0; i<len; i++){
        int j=i-1, k=i+1;
        while(j>=0 && k<len){
            if(s[j]!=s[k]) break;
            if((k-j)>(en-start)){
                en=k;
                start=j;
            }
            j--;
            k++;
        }
    }
    for(int i=0; i<len-1; i++){
        if(s[i]==s[i+1]){
            if((en-start)<2){
                en=i+1;
                start=i;
            }
            int j=i-1, k=i+2;
            while(j>=0 && k<len){
                if(s[j]!=s[k]) break;
                if((k-j)>(en-start)){
                    en=k;
                    start=j;
                }
                j--;
                k++;
            }
        }
    }
    return s.substr(start, en-start+1);
}

int main(){
    assert(longestPalindrome("")=="");
    assert(longestPalindrome("monica")=="m");
    assert(longestPalindrome("pawan")=="awa");
    assert(longestPalindrome("qawaq")=="qawaq");
    assert(longestPalindrome("qmonicaacinomp")=="monicaacinom");
    assert(longestPalindrome("monicaacinom")=="monicaacinom");
    return 0;
}
