#include <bits/stdc++.h>

using namespace std;

int main () {
    unordered_set<int> st;
    int n, p , q;
    cin >> n;

    cin>> p;
    for (int i = 0; i < p; i++) {
        int in;
        cin >> in;
        st.insert(in);
    }
    cin>> q;
    for (int i = 0; i < q; i++) {
        int in;
        cin >> in;
        st.insert(in);
    }

    if (st.size() == n) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;

    return 0;
}