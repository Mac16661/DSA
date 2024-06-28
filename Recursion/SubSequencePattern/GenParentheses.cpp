#include<bits/stdc++.h>
using namespace std;

void GenParenthesis(int pos, int n, int open, int close) {
    static char s[100];

    if(close == n) {
        cout<<s<<endl;
        return;
    }

    if(open < n) {
        s[pos] = '{';
        GenParenthesis(pos+1, n, open+1, close);
    }

    if(open > close) { //we have extra open parenthesis
        s[pos] = '}';
        GenParenthesis(pos+1, n, open, close+1);
    }
    
    
    
}

int main() {
    GenParenthesis(0, 3, 0 , 0);
    return 0;
}