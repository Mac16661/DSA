class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i=0; i<s.size(); i++) last[s[i]] = i;

        vector<int> ans;
        int strEnd = 0;
        int strStart = 0;
        for(int i=0; i<s.size(); i++) {
            strEnd = max(strEnd, last[s[i]]);
            if(i==strEnd) {
                ans.push_back(strEnd - strStart + 1);
                strStart = i+1;
            }
        }

        return ans;
    }
};