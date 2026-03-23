class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {


        // Dynamic sliding window with hash map
        int n = nums.size();
        int j = 0;
        unordered_map<int, int> mp;
        int len = 0;

        for (int i=0; i<n; i++) {
            mp[nums[i]]++;  // Expand till nums[i] freq > 2
            
            while(j < i && mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }

            len = max(len, i - j + 1);
        }

        return len;
    }
};