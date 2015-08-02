/**
    Implement strStr().

    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

int strStr(string haystack, string needle) {
    int h=haystack.length(), n=needle.length();
    if(!h && !n) return 0;
    if(h<n) return -1;
    if(!n) return 0;
    for(int i=0; i<=h-n; i++){
        int flag=i;
        if(haystack[i]==needle[0]){
            int j=1, k=i+1;
            while(j<n){
                if(haystack[k]==needle[j])
                {
                    k++;
                    j++;
                }
                else{
                    flag=-1;
                    break;
                }
            }
            if(flag>=0) return i;
        }
    }
    return -1;
}

int main(){
    assert(strStr("monica", "moni")==0);
    assert(strStr("monica", "pawan")==-1);

    return 0;
}


