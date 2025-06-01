class Solution {
public:
    void helper(vector<int>& arr, int target, vector<int> & ds, vector<vector<int>>& ans, int idx){
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i < arr.size(); i++) {
            if(i!=idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            helper(arr, target-arr[i], ds, ans, i+1); // i+1 because cannot take same value twice unlike the first varient 
            ds.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());

        helper(candidates, target, ds, ans, 0);
        return ans;
    }
};