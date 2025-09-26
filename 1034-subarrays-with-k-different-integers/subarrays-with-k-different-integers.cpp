class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    long long atMostK(const vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long res = 0;
        unordered_map<int,int> freq;

        for (int j = 0; j < n; ++j) {
            if (freq[nums[j]] == 0) {
                --k;
            }
            ++freq[nums[j]];

            while (k < 0) { 
                --freq[nums[i]];
                if (freq[nums[i]] == 0) {
                    ++k;
                }
                ++i;
            }

            res += (j - i + 1);
        }
        return res;
    }
};