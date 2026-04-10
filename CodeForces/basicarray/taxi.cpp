#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    int count[5] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        count[s]++;
    }

    // 1. Groups of 4 always need their own taxi
    int total = count[4];
   
    // 2. Groups of 3 take one group of 1 if possible
    total += count[3];
    count[1] = max(0, count[1] - count[3]);

    // 3. Two groups of 2 can share a taxi
    total += count[2] / 2;
    if (count[2] % 2 == 1) {
        // One group of 2 is left. It takes a taxi and can fit up to two 1s.
        total++;
        count[1] = max(0, count[1] - 2);
    }

    // TODO: Very imp
    // 4. Remaining groups of 1 are packed 4 to a taxi
    if (count[1] > 0) {
        total += (count[1] + 3) / 4; // Ceiling division
    }

    cout << total << endl;
    return 0;
}
