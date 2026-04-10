#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>> n;

    int inc = 0, dec = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "++X" || s == "X++")
            inc++;
        else
            dec++;
    }

    cout << inc - dec << endl;
    return 0;
}