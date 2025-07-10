class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        if (s1.size() > s2.size()) {};

        unordered_map<char, int> target, window;
        for (char c : s1) target[c]++;

        int left = 0, right = 0;
        int k = s1.size();

        vector<int> ans;
        while (right < s2.size()) {
            window[s2[right]]++;

            
            if (right - left + 1 > k) {
                window[s2[left]]--;
                if (window[s2[left]] == 0)
                    window.erase(s2[left]);
                left++;
            }

            
            if (right - left + 1 == k && window == target) {
                ans.push_back(left);
            }

            right++;
        }

        return ans;
    }
};