class Solution {
public:
    void leftShift(vector<int>& nums, int j) {
        for (int i = j; i < nums.size() - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums.pop_back(); // shrink size after shifting
    }

    int removeDuplicates(vector<int>& nums) {
        int removed = 0;

        for (int i = 0; i < nums.size();) {
            int cnt = 0;
            int j = i;

            while (j < nums.size() && nums[i] == nums[j]) {
                cnt++;
                j++;
            }

            while (cnt > 2) {
                leftShift(nums, j - 1); // remove from end of this block
                cnt--;
                removed++;
                j--; 
            }

            i = j;
        }

        return nums.size(); 
    }
};
