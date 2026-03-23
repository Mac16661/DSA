class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = 0;
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        for (int i = 0; i < n; i++) {
            int leftSum = (i == 0) ? 0 : prefix[i - 1];
            int rightSum = prefix[n - 1] - prefix[i];
            if (leftSum == rightSum) return i;
        }

        return -1;
    }
};