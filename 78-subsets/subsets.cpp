class Solution {
public:
    vector<vector<int>> arr;

    void bt(vector<int> &nums, int i, vector<int> ds) {
        if( i >= nums.size()) {
            arr.push_back(ds);
            return;
        } 

        bt(nums, i+1, ds);

        ds.push_back(nums[i]);
        bt(nums, i+1, ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        bt(nums, 0, ds);
        return arr;
    }
};