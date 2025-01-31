#include<bits/stdc++.h>
using namespace std; 

string RmvOuterMostP(string s) {
    int bal = 0;
    string ans = "";

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            bal++;

            if(bal > 1) ans+= s[i];

        }else{

            if(bal > 1) ans+= s[i];

            bal--;
        }
    }

    return ans;
}

int main() {
    string brackets = "(()())(())(()(()))";
    cout<<RmvOuterMostP(brackets)<<endl;
    return 0;
}