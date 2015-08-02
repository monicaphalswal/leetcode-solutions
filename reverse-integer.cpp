/**
    Reverse digits of an integer.

    Example1: x = 123, return 321
    Example2: x = -123, return -321
*/
#include<bits/stdc++.h>

using namespace std;
int reverse(int x) {
    int ans=0;
    while(x){
        if (abs(ans) > INT_MAX/10) return 0;
        ans=ans*10+(x%10);
        x/=10;
    }
    return ans;
}

int main(){
    assert(reverse(123)==321);
    assert(reverse(-123)==-321);
    return 0;
}
