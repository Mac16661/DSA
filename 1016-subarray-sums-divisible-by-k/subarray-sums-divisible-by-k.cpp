class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i=0; i<n; i++) {
            prefix+= nums[i];
            int rem =((prefix % k) + k) % k;
            if(mp.count(rem)) cnt += mp[rem];
            mp[rem]++;
        }

        return cnt;
    }
};