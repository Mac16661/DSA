#include<bits/stdc++.h>
using namespace std;

unordered_set<string> sn;

void DistinctSubseq(string s, string ds, int ind){
    if(ind == s.length()) {
        sn.insert(ds);
        return;
    }

    ds = ds + s[ind];
    DistinctSubseq(s, ds, ind+1);
    ds.pop_back();
    DistinctSubseq(s, ds, ind+1);
}

int main() {
    DistinctSubseq("gfg", "", 0);
    int one = sn.size();
    sn.clear();
    
    DistinctSubseq("ggg", "", 0);
    int two = sn.size();

    if(one > two){
        cout<<"gfg"<<endl;
    }else if(one == two){
        cout<<"gfg & ggg"<<endl;
    }else{
        cout<<"ggg"<<endl;
    }
    
    return 0;
}