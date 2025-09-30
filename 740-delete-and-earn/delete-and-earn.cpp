class Solution {
public:
    int helper(int idx, vector<int>& points, vector<int>& dp) {
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int take = points[idx] + helper(idx - 2, points, dp);

        int notTake = helper(idx - 1, points, dp);

        return dp[idx] = max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        // build points array (sum of values for each number)
        for (int num : nums) {
            points[num] += num;
            cout<<num<<" "<<points[num]<<endl;
        }

        cout<<maxVal<<endl;
        vector<int> dp(maxVal + 1, -1);
        return helper(maxVal, points, dp);
    }
};
