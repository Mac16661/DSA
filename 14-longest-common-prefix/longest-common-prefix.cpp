class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];

        for(int i = 1; i<strs.size(); i++) {
            string curr = strs[i];
            int j = 0;
            while( j< min(s.size(),curr.size()) && s[j] == curr[j]) j++;
            s = s.substr(0, j);
        }

        return s;
    }
};