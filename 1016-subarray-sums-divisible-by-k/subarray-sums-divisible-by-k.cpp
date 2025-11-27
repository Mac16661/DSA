class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int n = nums.size();
        // int cnt = 0;
        // brute
        // for(int i = 0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=i; j<n; j++) {
        //         sum+= nums[j];
        //         if(sum%k==0) cnt++;
        //     }
        // }
        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        int prefix = 0, cnt = 0;

        for(int i=0; i<n; i++) {
            prefix += nums[i];

            int rem = ((prefix % k) + k) % k;
            if(mp.find(rem) != mp.end()) cnt+= mp[rem];
            mp[rem]++;
        }

        return cnt;
    }
};