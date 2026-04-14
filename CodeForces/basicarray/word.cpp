#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int ucnt = 0, lcnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i]))
            ucnt++;
        else
            lcnt++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (ucnt > lcnt)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }

    cout<< s << endl;
    return 0;
}