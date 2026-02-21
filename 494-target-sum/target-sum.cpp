class Solution {
public:
    int cnt;
    void helper(vector<int>& nums, int t, int i, int sum) {
        if(i >= nums.size()) {
            // cout<<sum<< " ->  "<<t<<endl;
            if(sum == t) cnt++;
            return;
        }

        // plus
        helper(nums, t, i+1, sum + nums[i]);

        // minus
        helper(nums, t, i+1, sum - nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        cnt = 0;
        helper(nums, target, 0, 0);
        return cnt;
    }
};