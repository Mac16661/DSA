class Solution {
public:
    int bs(vector<int>& nums, int t, int low, int high) {
        if(low > high) return -1;

        int mid = (low+high)/2;

        if(nums[mid] == t) return mid;
        else if(nums[mid] > t) {
            return bs(nums, t, low , mid-1);
        }else {
            return bs(nums,t, mid+1 , high );
        }
    } 

    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        // return bs(nums, target, 0, high);
        int low= 0;

        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return -1;
    }
};