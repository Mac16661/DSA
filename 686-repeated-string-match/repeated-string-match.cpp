class Solution {
public:
    int rabinKarp(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        if (m > n) return -1;

        const int base = 256;
        const int mod = 1e9 + 7;

        long long patternHash = 0, textHash = 0, power = 1;

        // Precompute base^(m-1)
        for (int i = 0; i < m - 1; ++i)
            power = (power * base) % mod;

        // Compute hash for pattern and first window
        for (int i = 0; i < m; ++i) {
            patternHash = (patternHash * base + pattern[i]) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }

        // Slide the window
        for (int i = 0; i <= n - m; ++i) {
            if (patternHash == textHash) {
                if (text.substr(i, m) == pattern)
                    return i;  // Match found
            }
            // Roll the hash (if not at the end)
            if (i < n - m) {
                textHash = (textHash - text[i] * power) % mod;
                textHash = (textHash * base + text[i + m]) % mod;
                if (textHash < 0) textHash += mod;
            }
        }

        return -1; // Not found
    }


    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(rabinKarp(source,B) != -1) return count;
        if(rabinKarp(source+A,B) != -1) return count+1;
        return -1;
    }
};