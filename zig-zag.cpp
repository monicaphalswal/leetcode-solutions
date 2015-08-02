/**
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back

string convert(string s, int numRows){
    if(numRows>s.length()) return s;
    if(numRows<=1) return s;
    int shift=2*numRows-2;
    string ans;
    for(int i=0; i<s.length(); i+=shift) ans+=s[i]; ///first row

    for(int i=1, j=2*(numRows-1)-1; i<numRows-1; i++, j--){ ///In-between rows
        int temp=i, temp2=j;
        while(temp<s.length()){
            ans+=s[temp];
            temp+=shift;
            if(temp2<s.length()){
                    ans+=s[temp2];
                    temp2+=shift;
            }
        }
    }

    for(int i=numRows-1; i<s.length(); i+=shift) ans+=s[i]; ///Last row
    return ans;
}

int main(){
    string s;
    int rows;
    assert(convert("PAYPALISHIRING", 0)=="PAYPALISHIRING");
    assert(convert("PAYPALISHIRING", 1)=="PAYPALISHIRING");
    assert(convert("PAYPALISHIRING", 2)=="PYAIHRNAPLSIIG");
    assert(convert("PAYPALISHIRING", 3)=="PAHNAPLSIIGYIR");
    assert(convert("PAYPALISHIRING", 4)=="PINALSIGYAHRPI");
    assert(convert("PAYPALISHIRING", 5)=="PHASIYIRPLIGAN");
    assert(convert("PAYPALISHIRING", 6)=="PRAIIYHNPSGAIL");
    assert(convert("PAYPALISHIRING", 7)=="PNAIGYRPIAHLSI");
    assert(convert("PAYPALISHIRING", 8)=="PAGYNPIARLIIHS");
    assert(convert("PAYPALISHIRING", 14)=="PAYPALISHIRING");
    assert(convert("PAYPALISHIRING", 15)=="PAYPALISHIRING");

    while(1){
            cin>>rows;
            string ans=convert("PAYPALISHIRING", rows);
            cout<<ans<<endl;
    }
    return 0;
}


