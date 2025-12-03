class Solution {
public:
    string lastNonEmptyString(string s) {
        string ans="";
        int maxF = 0;
        unordered_map<char, int> freq;
        unordered_set<char> isPresent;

        // find the max freq as well
        for(char c:s) {
            freq[c]++;
            if(freq[c] > maxF) maxF = freq[c];
        }

        for(int i=s.size()-1; i>=0; i--) {
            char c = s[i];
            if(freq[c] == maxF && !isPresent.count(c)) {
                ans = c + ans;
                isPresent.insert(c);
            }
        }

        return ans;
    }
};