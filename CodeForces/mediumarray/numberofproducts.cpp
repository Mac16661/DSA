#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long neg_prefixes = 0;
    long long pos_prefixes = 1; // Base case: prefix product before index 1 is positive (+1)

    long long neg_subsegments = 0;
    long long pos_subsegments = 0;

    int current_sign = 1; // 1 represents positive, -1 represents negative

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        // Update the current prefix product sign
        if (val < 0) {
            current_sign *= -1;
        }

        // If the current prefix is positive
        if (current_sign == 1) {
            pos_subsegments += pos_prefixes;
            neg_subsegments += neg_prefixes;
            pos_prefixes++;
        } 
        // If the current prefix is negative
        else {
            pos_subsegments += neg_prefixes;
            neg_subsegments += pos_prefixes;
            neg_prefixes++;
        }
    }

    cout << neg_subsegments << " " << pos_subsegments << "\n";

    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for (int i=0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int nv = 0, pv = 0;

//     for (int i = 0; i < n; i++) {
//         long long prod = 1;
//         for (int j = i; j < n; j++) {
//             if (arr[j] > 0) {
//                 prod *= 1;
//             } else {
//                 prod *= -1;
//             }

//             if (prod < 0)
//                 nv++;
//             else
//                 pv++;
//         }
//     }

//     cout<< nv << " " << pv << endl;

//     return 0;
// }