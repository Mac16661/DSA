#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;

    cin >> s1;
    cin >> s2;

    int i = 0;
    while (i < s1.size()) {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);

        if (c1 < c2) {
            cout << "-1" <<endl;
            return 0;
        }else if (c2 < c1) {
            cout << "1" <<endl;
            return 0;
        }
        i++;
    }

    cout << "0" << endl;

    return 0;
}