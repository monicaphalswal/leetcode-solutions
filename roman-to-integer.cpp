/**
    Given a roman numeral, convert it to an integer.

    Input is guaranteed to be within the range from 1 to 3999.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back


int romanToInt(string s) {
    map<char, int> t;
    t['I']=1;
    t['V']=5;
    t['X']=10;
    t['L']=50;
    t['C']=100;
    t['D']=500;
    t['M']=1000;
    int len=s.length();
    if(!len) return 0;
    int ans=0;
    for(int i=0; i<len-1; i++){
        if(t[s[i]]>=t[s[i+1]]) ans+=t[s[i]];
        else ans-=t[s[i]];
        //cout<<"* "<<ans<<endl;
    }
    ans+=t[s[len-1]];
    //cout<<ans<<endl;
    return ans;
}

int main(){
    assert(romanToInt("I")==1);
    assert(romanToInt("MMMCMXCIX")==3999);
    assert(romanToInt("DLCV")==555);
    assert(romanToInt("CD")==400);
    assert(romanToInt("CCV")==205);
    return 0;
}


