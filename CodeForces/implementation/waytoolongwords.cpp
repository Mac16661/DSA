#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.size() < 11) {
            cout<< s << endl;
            continue;
        }

        string ans = s[0] + to_string(s.size() - 2) + s[s.size()-1];
        cout << ans<< endl;
    }
    return 0;
}