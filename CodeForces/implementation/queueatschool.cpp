#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, t;
    if (!(cin >> n >> t)) return 0;
    
    string s;
    cin >> s;

    // Simulate for each second
    while (t--) {
        for (int i = 0; i < n - 1; ++i) {
            // Only swap if a Boy is strictly in front of a Girl
            if (s[i] == 'B' && s[i+1] == 'G') {
                swap(s[i], s[i+1]);
                i++; // Skip the girl we just swapped to avoid double-moving
            }
        }
    }

    cout << s << endl;
    return 0;
}