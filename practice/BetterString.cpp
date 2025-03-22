#include<bits/stdc++.h>
using namespace std;

void subSeq(string s1, int i, set<string> &s, string ans) {
    if(i > s1.length()){
        s.insert(ans);
        return;
    }

    // not taking
    subSeq(s1, i+1, s, ans);

    // taking
    ans = ans + s1[i];
    subSeq(s1, i+1, s, ans);
}

string betterSubstr(string s1, string s2){
    set<string> s;
    subSeq(s1, 0, s, "");
    int s1L = s.size();
    s.clear();
    subSeq(s2, 0, s, "");
    int s2L = s.size();

    if(s1L >= s2L) return s1;

    return s2;
}

int main() {
    cout<<betterSubstr("aad", "bca")<<endl;
    return 0;
}