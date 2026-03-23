class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto c : t) need[c]++;   // build freq map for t

        int have = 0, required = need.size();
        int n = s.size();
        int minLen = INT_MAX, startIdx = 0;

        int j = 0;
        for (int i = 0; i < n; i++) {
            window[s[i]]++;

            if (need.count(s[i]) && window[s[i]] == need[s[i]]) {
                have++;
            }

            while (have == required) {
                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    startIdx = j;
                }
                window[s[j]]--;
                if (need.count(s[j]) && window[s[j]] < need[s[j]]) {
                    have--;
                }
                j++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
