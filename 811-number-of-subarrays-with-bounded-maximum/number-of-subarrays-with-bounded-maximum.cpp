class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i=0, j=0;
        int n = nums.size();
        int cnt=0, maxi=0;
        while(j<n) {
            if(nums[j] > right) {
                maxi=0;
                i=j+1;
            }else if(nums[j] >= left && nums[j]<=right) {
                maxi= j-i+1;
            }
            cnt+= maxi;
            j++;
        }
        return cnt;
    }
};