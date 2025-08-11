class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size()-1;
        // Edge cases
        if(n==0) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n] > nums[n-1]) return n;

        int low = 1, high = n-1;

        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;

            // Movig towards peaks
            if(nums[mid-1] < nums[mid]) low = mid+1;
            else if(nums[mid-1] > nums[mid]) high = mid-1;
            else low = mid+1;// alternatively we can set high = mid-1;
        }

        return -1;
    }
};