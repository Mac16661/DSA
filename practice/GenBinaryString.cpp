#include<iostream>
using namespace std;

void GenString(string s, int i, int n) {
    if(s.length() >= n) {
        cout<<s<<endl;
        return;
    }

    s += '0';

    GenString(s, i+1, n);

    s[i] = '1';

    GenString(s, i+1, n);

}

// Generating non consucative 1 string
void GenStr(string s, int i, int n, int last){
    if(i >= n) {
        cout<<s<<endl;
        return;
    }

    s[i] = '0';
    GenStr(s, i+1, n, 0);

    if(last != 1) {
        s[i] = '1';
        
        GenStr(s, i+1, n, 1);
    }

}

int main() {
    GenStr("0000", 0, 4, 0);
    return 0;
}