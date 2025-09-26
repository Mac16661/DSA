class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int> count;

        for (char c : s) count[c]++;

        int k = n / 4;  // target frequency per char
        if (count['Q'] == k && count['W'] == k && count['E'] == k && count['R'] == k)
            return 0;

        int ans = n, i = 0;

        for (int j = 0; j < n; j++) {
            count[s[j]]--;

            // shrink left side while condition is satisfied
            while (i < n &&
                   count['Q'] <= k &&
                   count['W'] <= k &&
                   count['E'] <= k &&
                   count['R'] <= k) {
                ans = min(ans, j - i + 1);
                count[s[i]]++;
                i++;
            }
        }
        return ans;
    }
};
