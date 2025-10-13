class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }   

        // storing prefix sum - k for each i
        unordered_map<int, int> mp;
        int ans = 0;

        for(int i=0; i<n; i++) {
            if(prefix[i] == k) ans++;

            // if prefix sum - k exists in the unordered map
            if(mp.find(prefix[i] - k) != mp.end()) {
                ans+= mp[prefix[i] - k];
            }

            mp[prefix[i]]++;
        }
        return ans;
    }
};