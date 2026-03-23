class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> target, window;
        for (char c : s1) target[c]++;

        int left = 0, right = 0;
        int k = s1.size();

        while (right < s2.size()) {
            window[s2[right]]++;

            
            if (right - left + 1 > k) {
                window[s2[left]]--;
                if (window[s2[left]] == 0)
                    window.erase(s2[left]);
                left++;
            }

            
            if (right - left + 1 == k && window == target) {
                return true;
            }

            right++;
        }

        return false;
    }
};
