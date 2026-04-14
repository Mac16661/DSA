#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() <= 7) {
        cout << "NO" << endl;
        return 0;
    }

    int prev = s[0];
    int runningSum = s[0] == '1' ? 1 : -1;

    for (int i = 0; i < s.size(); i++) {
        int curr = s[i];

        if (prev != curr) // reset
            runningSum = 0;

        runningSum += curr == '1' ? 1 : -1;

        if (runningSum >= 7 || runningSum <= -7){
            cout<< "YES" << endl;
            return 0;
        }

        prev = curr;
    }

    cout << "NO" << endl;
    return 0;
}