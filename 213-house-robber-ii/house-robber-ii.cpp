class Solution {
public:
    int helperDP(int n, vector<int> &nums, vector<int> & dp) {
            // base case
            if(n < 0) {
                return 0;
            }

            // dp
            if(dp[n] != -1) return dp[n];

            // Take
            int t = helperDP(n-2, nums, dp) + nums[n];

            // Not Take
            int nt = helperDP(n-1, nums, dp);

            return dp[n] = max(t, nt);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> nums2(nums.begin()+1, nums.end());
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> dp(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        return max(helperDP(n-2, nums1, dp), helperDP(n-2, nums2, dp2));
    }
};