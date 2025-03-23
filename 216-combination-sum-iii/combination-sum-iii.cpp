class Solution {
public:
    void bt(vector<vector<int>> &ans, vector<int> &ds, int k, int sum, int idx) {
        if(ds.size()==k){
            if(sum == 0){
                ans.push_back(ds);
                return;
            }
        }

        for(int i = idx; i<=9; i++) {
            ds.push_back(i);
            bt(ans, ds, k, sum - i, i+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        bt(ans, ds, k, n, 1);
        return ans;
    }
};