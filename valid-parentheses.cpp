/**
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back


bool isValid(string s) {
    int len=s.length();
    if(!len) return 1;
    stack<char> p;
    for(int i=0; i<len; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') p.push(s[i]);
        else{
            if(!p.empty())
            {
                char top=p.top();
                if(s[i]=='}' && top=='{') p.pop();
                else if(s[i]==')' && top=='(') p.pop();
                else if(s[i]==']' && top=='[') p.pop();
                else return false;
            }
            else return false;
        }
    }
    if(p.empty()) return true;
    else return false;
}

int main(){
    assert(isValid("")==1);
    assert(isValid("()")==1);
    assert(isValid("()[]{}")==1);
    assert(isValid("(]")==0);
    assert(isValid("([)]")==0);
    assert(isValid("([])]")==0);
    assert(isValid("({(([")==0);
    assert(isValid("}))))]")==0);
    return 0;
}



