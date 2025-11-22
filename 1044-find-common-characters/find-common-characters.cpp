class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> globalFreq(26, INT_MAX);

        for (auto &w : words) {
            vector<int> freq(26, 0);
            for (char c : w) freq[c - 'a']++;
            
            for (int i = 0; i < 26; i++)
                globalFreq[i] = min(globalFreq[i], freq[i]);
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            while (globalFreq[i]-- > 0) {
                ans.push_back(string(1, char(i + 'a')));
            }
        }

        return ans;
    }
};