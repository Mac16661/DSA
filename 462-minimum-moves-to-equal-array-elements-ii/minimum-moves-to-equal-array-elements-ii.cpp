class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(nums.size()%2==0) {
            mid = (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }else {
            mid = nums[n / 2];
        }

        int sum = 0;

        for(auto num: nums) {
            sum += abs(num-mid);
        }

        return sum;
    }
};