#include <bits/stdc++.h>

using namespace std;

int main () {
    int  n;
    cin >> n;
    
    int last = -1;
    int cnt = 0, maxCnt = 0;
    for (int i=0; i < n; i++) {
        int inp;
        cin >> inp;

        if (inp > last) cnt++;
        else  {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
        }

        last = inp;
    }

    cout << max(maxCnt, cnt) << endl;    
    return 0;
}