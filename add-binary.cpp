/**
    Given two binary strings, return their sum (also a binary string).

    For example,
    a = "11"
    b = "1"
    Return "100".
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

string addBinary(string a, string b) {
    int alen = a.length(), blen=b.length();
    if(!alen && !blen) return "";
    if(!alen) return b;
    if(!blen) return a;
    string ans;
    int carry=0;
    alen--;
    blen--;
    while(alen>=0 && blen>=0){
        if(a[alen]=='0' && b[blen]=='0' && !carry){
                ans+='0';
                carry=0;
        }
        else if((a[alen]=='1' && b[blen]=='1' && !carry) || (a[alen]=='1' && b[blen]=='0' && carry) || (a[alen]=='0' && b[blen]=='1' && carry)){
            ans+='0';
            carry=1;
        }
        else if(a[alen]=='1' && b[blen]=='1' && carry){
            ans+='1';
            carry=1;
        }
        else{
            ans+='1';
            carry=0;
        }
        alen--;
        blen--;

    }
    while(alen>=0){
        if(carry){
            if(a[alen]=='1'){
                ans+='0';
                carry=1;
            }
            else{
                ans+='1';
                carry=0;
            }
        }
        else ans+=a[alen];
        alen--;
    }
    while(blen>=0){
        if(carry){
            if(b[blen]=='1'){
                ans+='0';
                carry=1;
            }
            else{
                ans+='1';
                carry=0;
            }
        }
        else ans+=b[blen];
        blen--;
    }
    if(carry) ans+='1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    assert(addBinary("11", "1")=="100");
    assert(addBinary("1", "111")=="1000");
    assert(addBinary("", "")=="");
    assert(addBinary("", "1")=="1");
    assert(addBinary("11", "")=="11");
    assert(addBinary("01", "1")=="10");
    assert(addBinary("0", "0")=="0");
    return 0;
}


