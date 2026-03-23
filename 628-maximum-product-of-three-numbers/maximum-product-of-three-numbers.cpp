class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        {
            return -1;
        }
        sort(nums.begin(),nums.end());

        int maxi=max(nums[n-3]*nums[n-2]*nums[n-1],nums[0]*nums[1]*nums[n-1]);

        return maxi;
    }
};