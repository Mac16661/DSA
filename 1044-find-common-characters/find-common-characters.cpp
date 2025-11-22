class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> globalFreq(26, INT_MAX);

        for (auto &w : words) {
            // If some char is not present in all the number it's freq will become 0 in globalFreq because freq(26,0) & min(globalFreq[i], freq[i])
            vector<int> freq(26, 0); // very important 
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