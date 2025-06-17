class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        return wb(s, dict, memo);
    }

private:
    bool wb(const string& s, unordered_set<string>& dict, unordered_map<string, bool>& memo) {
        int len = s.size();
        if (len == 0) return true;
        if (memo.count(s)) return memo[s];

        for (int i = 1; i <= len; ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (dict.count(left) && wb(right, dict, memo)) {
                return memo[s] = true;
            }
        }
        return memo[s] = false;
    }
};