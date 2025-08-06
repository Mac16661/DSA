class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid] == target) return  mid;

            // # Move here if only left part is sorted
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && nums[mid] >= target) { // check if it is lies in between
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            // Move here only if right part is sorted
            }else {
                if(nums[mid] <= target && nums[high] >= target) { // check if taret lies in between
                    low = mid+1;
                }else {
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};