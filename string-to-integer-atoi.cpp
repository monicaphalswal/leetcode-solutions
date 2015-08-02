/**
    Implement atoi to convert a string to an integer.
    Notes: It is intended for this problem to be specified vaguely (i.e, no given input specs).
    You are responsible to gather all the input requirements up front.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

int myAtoi(string str) {
    if(str.length()==0) return 0;
    int i=0;
    while(str[i]==' ') i++;
    int ans=0;
    bool negative=0;
    if(str[i]=='+'){
            i++;
            if(!isdigit(str[i])) return 0;
    }
    if(str[i]=='-'){
            negative=1;
            i++;
            if(!isdigit(str[i])) return 0;
    }
    for(; i<str.length(); i++){
            if(isdigit(str[i])){
                if(negative){
                    if(-ans<INT_MIN/10 || (-ans==INT_MIN/10 && (str[i]-'0')>8)) return INT_MIN;
                }
                else{
                    if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (str[i]-'0')>7)) return INT_MAX;
                }
                ans = ans*10+(str[i]-'0');
            }
            else break;
    }
    if(negative) return -ans;
    else return ans;
}

int main(){
    assert(myAtoi("")==0);
    assert(myAtoi("+-2")==0);
    assert(myAtoi("1")==1);
    assert(myAtoi("0001")==1);
    assert(myAtoi("-1")==-1);
    assert(myAtoi("-0001")==-1);
    assert(myAtoi("  -0012a42")==-12);
    assert(myAtoi("    -0001")==-1);
    assert(myAtoi("-0001  ")==-1);
    assert(myAtoi("100")==100);
    assert(myAtoi("000")==0);
    assert(myAtoi("0")==0);
    assert(myAtoi("2147483648")==INT_MAX);
    assert(myAtoi("-2147483649")==INT_MIN);
    assert(myAtoi(" -1010023630o4")==-1010023630);
    assert(myAtoi("2147483650")==INT_MAX);
    assert(myAtoi("-2147483650")==INT_MIN);
    assert(myAtoi(to_string(INT_MAX))==INT_MAX);
    assert(myAtoi(to_string(INT_MIN))==INT_MIN);
    return 0;
}


