#include<bits/stdc++.h>
using namespace std;

void letter(string s1, string s2, int idx){

    if(idx == s1.length()) return;

    for(int i = 0; i < s2.length(); i++) {
        cout<<s1[idx]<<s2[i]<<endl;
    }

    letter(s1, s2, idx+1);
}

int main() {

    letter("wxyz", "abc", 0);

    return 0;
}