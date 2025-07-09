class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeroCount = 0;

    for (; right < nums.size(); ++right) {
        if (nums[right] == 0) zeroCount++;

        if (zeroCount > k) {
            if (nums[left] == 0) zeroCount--;
            left++;
        }
    }

    return right - left;

    }
};