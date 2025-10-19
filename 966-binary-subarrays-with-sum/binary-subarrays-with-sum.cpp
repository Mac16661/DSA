class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;

        int prefix = 0, cnt = 0;

        for(int i=0; i<n; i++) {
            prefix += nums[i];

            if(mp.find(prefix - goal) != mp.end()) {
                cnt += mp[prefix - goal];
            }

            mp[prefix]++;
        }

        return cnt;
    }
};