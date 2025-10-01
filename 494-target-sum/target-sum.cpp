class Solution {
public:

    void helper(int idx, vector<int>& nums, int target, int n, int sum, int& cnt) {
        if(idx >= n) {
            if(sum == target) cnt++;
            return;
        }
    
        // try add
        helper(idx+1, nums, target, n, sum+nums[idx], cnt);

        // try substract
        helper(idx+1, nums, target, n, sum-nums[idx], cnt);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        helper(0, nums, target, n, 0, cnt);

        return cnt;
    }
};