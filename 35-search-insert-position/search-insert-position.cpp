class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // edge cases
        if(nums.size() == 0) return 0;
        if(target > nums[nums.size() - 1]) return nums.size();

        int low = 0;
        int high = nums.size()-1;
        int ans = high;

        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid] >= target) {
                ans = mid;
                high = mid-1;
            }else {
                low = mid + 1;
            }
        }
    
        
        return ans;
    }
};