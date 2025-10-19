class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int prefix = 0, maxLen = 0;
        mp[0] = -1;

        for(int i=0; i<n; i++) {
            prefix += (nums[i]==0)?-1:1;
            if(mp.find(prefix) != mp.end()) {
                int len = i - mp[prefix];
                maxLen = max(len , maxLen);
            }else mp[prefix] = i; // only first occurence to get the lasgest subarr
        }
        return maxLen;
    }
};