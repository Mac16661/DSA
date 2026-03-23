class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, len = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i=0; i<n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if(mp.count(sum)) len = max(len, i - mp[sum]);
            else mp[sum] = i;
        }   

        return len;
    }
};