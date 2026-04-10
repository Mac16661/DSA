#include <bits/stdc++.h>

using namespace std;

int main () {
    int oRow, oCol;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int val;

            cin >> val;
            
            if (val == 1) {
                oRow = i;
                oCol = j;
            }
        }
    }

    // position we need to set oRow and oCol
    int pRow = 2, pCol = 2;

    cout << abs(oRow - pRow) + abs(oCol - pCol) << endl; 
    return 0;
}