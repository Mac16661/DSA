class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        // Edge case handelling 
        if(n==0) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n] != nums[n-1]) return nums[n];

        int low = 0, high = n;

        // Elimination method
        while(low<=high){
            int mid = (low+high)/2;

            // Single element
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];

            // Eliminate left
            if((mid % 2 == 1 && nums[mid-1] == nums[mid]) || (mid % 2 == 0 && nums[mid]==nums[mid+1])){
                low = mid+1;

            }else{ // Eliminate right
                high = mid-1;
            }
        }
        return -1;
    }
};