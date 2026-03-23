class Solution {
public:

    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int j = 0;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            while (sum > goal) {
                sum -= nums[j];
                j++;
            }

            count += (i - j + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};