/**
    Compare two version numbers version1 and version2.
    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

    You may assume that the version strings are non-empty and contain only digits and the . character.
    The . character does not represent a decimal point and is used to separate number sequences.
    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

    Here is an example of version numbers ordering:

    0.1 < 1.1 < 1.2 < 13.37
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

int compareVersion(string version1, string version2) {
    int l1=version1.length(), l2=version2.length();
    int i=0, j=0;
    while(i<l1 || j<l2){
        int num1=0;
        while(version1[i]!='.' && i<l1){
            num1=num1*10+(version1[i]-'0');
            i++;
        }
        int num2=0;
        while(version2[j]!='.' && j<l2){
            num2=num2*10+(version2[j]-'0');
            j++;
        }
        if(num1<num2) return -1;
        else if(num1>num2) return 1;
        i++;
        j++;
    }
    return 0;
}

int main(){
    assert(compareVersion("0.1", "1.1")== -1);
    assert(compareVersion("1.2", "13.37")== -1);
    assert(compareVersion("1.2", "1.1")== 1);
    assert(compareVersion("1.1", "1.1")== 0);
    assert(compareVersion("1.2", "1.2.3")== -1);
    assert(compareVersion("1.2.3.4", "1.2.3")== 1);
    assert(compareVersion("1.2.3.0", "1.2.3")== 0);
    return 0;
}


