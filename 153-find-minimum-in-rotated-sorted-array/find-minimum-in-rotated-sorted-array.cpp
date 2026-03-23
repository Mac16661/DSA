class Solution {
public:
    int findMin(vector<int>& nums) {
        // always go to the sorted side and check
        int low=0;
        int high = nums.size() - 1;
        int ans = nums[0];

        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[low]<= nums[mid]) {
                ans = min(nums[low], ans);
                // search on right subarr
                low = mid+1;
            }else if(nums[mid+1] <= nums[high]) {
                ans = min(nums[mid+1], ans);
                // search on left subarr
                high = mid;
            }
        }
        return ans;
    }
};