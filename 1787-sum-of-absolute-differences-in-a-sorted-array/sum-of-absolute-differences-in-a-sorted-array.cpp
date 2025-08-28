class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), res(n, 0);

        // Build prefix sum
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            long left = (long)nums[i] * i - (i > 0 ? prefix[i-1] : 0);
            long right = (prefix[n-1] - prefix[i]) - (long)nums[i] * (n-i-1);
            res[i] = left + right;
        }
        return res;
        

    }
};