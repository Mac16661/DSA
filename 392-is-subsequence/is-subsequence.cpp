class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0;
        int i = 0;
        int n = t.size(); 

        while(i < n && sIdx < s.size()) {
            if(t[i] == s[sIdx]) {
                sIdx++;
            }
            i++;
        }

        if(sIdx == s.size()) return true;

        return false;
    }
};