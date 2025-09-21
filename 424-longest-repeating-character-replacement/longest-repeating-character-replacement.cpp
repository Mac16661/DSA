class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int maxCount = 0; // freq of most frequent char in the window
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right<s.size(); right++) {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // if more than k character need to be replaced
            while((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};