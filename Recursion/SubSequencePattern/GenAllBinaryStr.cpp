#include<bits/stdc++.h>
using namespace std;

void GenBinaryStr(string s,int i, int n) {
    if(i > n-1) {
        cout<<s<<endl;
        return;
    }


    s[i] = '1';
    GenBinaryStr(s,i+1, n);
    s[i] = '0';
    GenBinaryStr(s,i+1, n);

}

int main() {
    string s = "000";
    GenBinaryStr(s,0,3);
    

    return 0;
}