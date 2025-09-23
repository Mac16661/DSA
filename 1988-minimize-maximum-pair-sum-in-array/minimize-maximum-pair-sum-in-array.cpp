class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        int maxi = 0;
        int i=0, j = n;
        while(i<j) {
            int sum = nums[i]+nums[j];

            if(sum > maxi) {
                maxi = sum;
            }

            i++;j--;
        }

        return maxi;
    }
};