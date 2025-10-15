class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int prefixSum = 0;
        int maxLen = 0;

        mp[0] = -1; // default case

        for(int i=0; i<n; i++) {
            prefixSum += (nums[i] == 0 ? -1:1);

            if(mp.count(prefixSum)) {
                int len = i - mp[prefixSum];
                maxLen = max(maxLen, len);
            }else{
                mp[prefixSum] = i; // only first occurence to get the max len possible 
            }
        }

        return maxLen;
    }
};