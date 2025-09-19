class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];

        int slow = nums[0];
        int fast = nums[0];

        // intersection point
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};