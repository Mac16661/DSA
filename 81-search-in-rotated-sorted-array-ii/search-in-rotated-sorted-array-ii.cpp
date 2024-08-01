class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high) {
            int mid = (low+high) /2;

            if(nums[mid] == target) return true;

            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                high--;
                low++;
            }

            // If left is sorted
            else if(nums[low] <= nums[mid]) {
                // if target lies b/w low and mid
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }else{
                    low =mid+1;
                }
            }else{ //if right is sorted
                // if target lise b/w mid and high
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};