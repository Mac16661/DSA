class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int windowSize = p.size();
        unordered_map<char, int> smp, pmp;

        for(auto c: p) {
            smp[c]++;
        }

        vector<int> ans;
        for(int j=0; j<s.size(); j++) {
            pmp[s[j]]++;

            if(j-i+1 > windowSize) {
                pmp[s[i]]--;
                if(pmp[s[i]] == 0) pmp.erase(s[i]);
                i++;
            }

            if(j-i+1 == windowSize && smp == pmp) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};