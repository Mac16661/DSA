#include<bits/stdc++.h>
using namespace std;

int num = 0;

int Atoi(string s, int n) {
    if(n >= 0) {
        int val = ((int)s[n]) - 48;
        Atoi(s, n-1);
        num = (num*10) + val;
    }

    return num;
}

int main() {
    cout<<Atoi("1234",3)<<endl;
    return 0;
}