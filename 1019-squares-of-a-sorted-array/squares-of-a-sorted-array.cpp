class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int i = n-1;
        vector<int> ans(n);

        while(l<=r) {
            int num1 = nums[l] * nums[l];
            int num2 = nums[r] * nums[r];

            if(num1 > num2) {
                ans[i] = num1;
                l++;
            }else {
                ans[i] = num2;
                r--;
            }
            i--;
        }
        return ans;
    }
};