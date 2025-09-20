class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, mini = INT_MAX;

        while (j < n) {
            sum += nums[j];
            j++;
            while (sum >= target) {
                mini = min(mini, j - i);
                sum -= nums[i];
                i++;
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};
