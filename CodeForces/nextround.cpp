#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> score(n);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    int cnt = 0;
    int num = score[k-1];

    for (int i = 0; i < n; i++) {
        if (score[i] != 0 && score[i] >= num){
            // cout << score[i] <<" ";
            cnt++;
        }
    }

    cout <<cnt<<endl;

    return 0;
}