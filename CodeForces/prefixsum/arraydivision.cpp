#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long totalSum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        totalSum += a[i];
    }

    // If sum is odd, we can never divide it into two equal integer subset
    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    long long target = totalSum / 2;
    long long currentPrefix = 0;

    multiset<long long> prefixElements, suffixElements;
    for (int i = 0; i < n; i++)
        suffixElements.insert(a[i]);

    // Check split after every element i
    for (int i = 0; i < n; i++) {
        currentPrefix += a[i];
        prefixElements.insert(a[i]);
        suffixElements.erase(suffixElements.find(a[i])); // Move element from suffix to prefix

        if (currentPrefix == target) {
            cout << "YES" << endl;
            return 0;
        }

        if (currentPrefix > target) {
            long long need = currentPrefix - target;
            if (prefixElements.count(need)) {
                cout << "YES" << endl;
                return 0;
            }
        } else {
            long long need = target - currentPrefix;
            if (suffixElements.count(need)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    return  0;
}