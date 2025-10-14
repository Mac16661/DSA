class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int cnt = 0;

        for(int i=0; i<n; i++) {
            prefixSum += nums[i];

            int remainder = ((prefixSum % k) + k) % k;  // normalize remainder
            cnt += mp[remainder];
            mp[remainder]++;
        }

        return cnt;
    }
};