class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int n = nums.size();
        int prod = 1, cnt = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            prod *= nums[j];

            while (prod >= k && i <= j) {
                prod /= nums[i];
                i++;
            }
            cnt += (j - i + 1);
        }

        return cnt;
    }
};
