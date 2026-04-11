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
            if (s[i] == 'B' && s[i+1] == 'G') {
                swap(s[i], s[i+1]);
                i++;
            }
        }
    }

    cout << s << endl;
    return 0;
}