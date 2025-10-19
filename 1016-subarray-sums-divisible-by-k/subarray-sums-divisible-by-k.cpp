class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        int prefix = 0, cnt = 0;

        for(int i=0; i<n; i++) {
            prefix += nums[i];

            int rem = ((prefix % k) + k) % k;  // normalize remainder -> if remainder is -ve it becomes +ve after normalization 
            if(mp.find(rem) != mp.end()) {
                cnt+= mp[rem];
            }
            mp[rem]++;
        }

        return cnt;
    }
};