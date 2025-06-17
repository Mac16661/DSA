class Solution {
public:
    void helper(int index, vector<int>& s, vector<vector<int>>& ans) {
        if(index == s.size()) {
            ans.push_back(s);
            return;
        }

        for(int i = index; i<s.size(); i++) {
            swap(s[i], s[index]);
            helper(index+1, s, ans);
            swap(s[i], s[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        sort(ans.begin(), ans.end());

        return ans;
    }
};

