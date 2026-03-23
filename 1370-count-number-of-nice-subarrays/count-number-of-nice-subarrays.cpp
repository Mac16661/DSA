class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;

        unordered_map<int,int> mp;
        mp[0] = 1; // base case

        int count = 0;

        for(int i=0; i<n; i++) {
            prefix += (nums[i] % 2 != 0) ? 1 : 0;
            count += mp[prefix - k];
            mp[prefix]++;
        }

        return count;
    }
};