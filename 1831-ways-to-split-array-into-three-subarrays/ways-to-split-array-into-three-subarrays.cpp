class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long res = 0;
        int j = 0, k = 0;

        for (int i = 0; i < n - 2; i++) {
            long long leftSum = prefix[i];

            j = max(j, i + 1);
            while (j < n - 1 && prefix[j] - prefix[i] < leftSum)
                j++;

            // Move k to first invalid position where right < mid
            k = max(k, j);
            while (k < n - 1 && prefix[n - 1] - prefix[k] >= prefix[k] - prefix[i])
                k++;

            // Add all valid splits between j and k-1
            res = (res + (k - j)) % MOD;
        }

        return (int)res;
    }
};
