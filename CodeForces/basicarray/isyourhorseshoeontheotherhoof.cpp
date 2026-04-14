#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> st;

    for (int i = 0; i < 4; i++) {
        int curr;
        cin >> curr;

        st.insert(curr);
    }

    cout << 4 - st.size() << endl;
    return 0;
}