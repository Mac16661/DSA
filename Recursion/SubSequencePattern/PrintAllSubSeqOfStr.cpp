#include<bits/stdc++.h>
using namespace std;

void PowerSet(string s, string f, int start) {
    if(start == s.length()) {
        cout<<f<<endl;
        return;
    }

    f = f+s[start];
    PowerSet(s,f,start+1);
    f.pop_back();
    PowerSet(s,f,start+1);
    
}

int main() {
    string f = "";
    PowerSet("abc", f, 0);
    return 0;
}