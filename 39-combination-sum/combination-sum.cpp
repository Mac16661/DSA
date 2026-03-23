class Solution {
public:
    void helper(vector<int>& arr, int target, vector<int> & ds, vector<vector<int>>& ans, int idx, int sum){
        if(sum == target) {
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i < arr.size(); i++) {

            if(sum+arr[i] <= target) {
                ds.push_back(arr[i]);
                helper(arr, target, ds, ans, i, sum+arr[i]);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;

        helper(candidates, target, ds, ans, 0, 0);
        return ans;
    }
};