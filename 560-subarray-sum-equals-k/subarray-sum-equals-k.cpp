class Solution {
public:
     int subarraySum(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum == k)
            {
                count++;
            }
            int remaining=sum-k;
            if(mp.find(remaining) != mp.end())
            {
                count+=mp[remaining].size();
            }
            
            mp[sum].push_back(i);
        }
        return count;
    }
};