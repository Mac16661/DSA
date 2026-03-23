class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;

        unordered_map<int, int> mp;

        int prefix = 0;
        mp[0] = -1; // to efficiently calculate len 

        for(int i=0; i<n; i++) {
            prefix += nums[i];

            int rem = prefix % k;
            if(rem < 0) rem+= k;

            if(mp.find(rem) != mp.end()) {
                if(i - mp[rem] >= 2) return true;
            }else{
                mp[rem] = i;
            }
            
        }

        return false;
    }
};