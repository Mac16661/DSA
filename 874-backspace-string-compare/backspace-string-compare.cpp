class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int sCnt = 0, tCnt = 0;

        while (i >= 0 || j >= 0) {
            // process backspaces in s
            while (i >= 0 && (s[i] == '#' || sCnt > 0)) {
                if (s[i] == '#') sCnt++;
                else sCnt--;
                i--;
            }

            // process backspaces in t
            while (j >= 0 && (t[j] == '#' || tCnt > 0)) {
                if (t[j] == '#') tCnt++;
                else tCnt--;
                j--;
            }

            // if both valid chars exist, compare them
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } 
            else if (i >= 0 || j >= 0) {
                // one string ended but not the other
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};
