class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        // Step 1: sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        // Step 2: sliding window
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k]; // slide the window
            maxSum = max(maxSum, sum);
        }

        // Step 3: return max average
        return maxSum / k;
    }
};
