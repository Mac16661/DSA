class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // we will compute both prefix sum and mantain hashmap in one go
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;  // setting 0 as default key and val as 1

        int ans = 0;
        int prefixSum = 0;

        for(int i=0; i<n; i++) {
            prefixSum += nums[i];

            int rmv = prefixSum - k;
            ans += mp[rmv];
            mp[prefixSum]++;
        }

        return ans;
    }
};