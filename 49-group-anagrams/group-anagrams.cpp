class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
  
        int n = strs.size();
        //edge cases
        if(strs.size()==1){
            if(strs[0] == "") {
                ans.push_back({""});
                return ans;
            }else{
                ans.push_back({strs[0]});
                return ans;
            }
        }  

        // Brute force
        // for (int i = 0; i < n; i++) {
        //     if (st.count(i)) continue; // skip already grouped words

        //     vector<string> group = {strs[i]};
        //     unordered_map<char,int> mpp;
        //     for (char c : strs[i]) mpp[c]++;

        //     for (int j = i + 1; j < n; j++) { // start from i+1 to avoid re-checking
        //         if (st.count(j) || strs[i].size() != strs[j].size()) continue;

        //         unordered_map<char, int> mpp1;
        //         for (char c : strs[j]) mpp1[c]++;

        //         if (mpp == mpp1) { //TODO: unordered_map comparison is enough
        //             group.push_back(strs[j]);
        //             st.insert(j);
        //         }
        //     }

        //     st.insert(i);
        //     ans.push_back(group);
        // } 

        // Optimal:
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Sorted string as key
            mp[key].push_back(s);
        }
        // vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(p.second);
        }
        return ans;

    }
};