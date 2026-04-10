#include <bits/stdc++.h>

using namespace std;

int main () {
    int x;
    cin>> x;

    if (x <= 5) {
        cout<< 1 << endl;
        return 0;
    }

    int num = x / 5;
    
    if (x % 5 != 0)
        num++; 

    cout << num << endl;
    return 0;
}