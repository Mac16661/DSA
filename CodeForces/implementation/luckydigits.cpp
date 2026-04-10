#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    int cnt4 = 0;
    int cnt7 = 0;

    while (n) {
        int num = n % 10;
        n = n / 10;

        if (num == 7)
            cnt4++;
        else if (num == 4)
            cnt7++;
    }

    int sum = cnt4 + cnt7;
    if (sum == 4 || sum == 7)
        cout <<"YES" << endl;
    else
        cout <<"NO" <<endl;

    return 0;
}