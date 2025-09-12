class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size()-1;
        if(n==0) return 0;
        // Edge cases
        if(nums[0] > nums[1]) return 0;
        if(nums[n] > nums[n-1]) return n;

        for(int i=1; i<=n-1; i++) {
            // cout<<nums[i]<<endl;
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }

        return 0;
    }
};